#ifndef BAL_OBJ_H
#define BAL_OBJ_H

#include <bcmos_system.h>
#include <bcmos_errno.h>
#include "bal_model_ids.h"
#include "bal_buf.h"
#include "bal_msg_type.h"
#ifdef ENABLE_LOG
#include "bcm_dev_log.h"
#endif

/*
 * The current BAL header version
 */
#define BAL_HDR_VERSION_MAJOR    (1)
#define BAL_HDR_VERSION_MINOR    (2)

/** Max error text length */
#define BCMBAL_MAX_ERR_TEXT_LENGTH      256

/*
 * The BAL common message header
 */
typedef struct bal_comm_msg_hdr
{
    bcmos_msg        m;               /**< bcmos message header */
    uint8_t          version_major;   /**< Header Major version number */
    uint8_t          version_minor;   /**< Header Minor version number */
    bcmbal_msg_type  msg_type;        /**< Request / Response / Ack / Indication */
    uint32_t         msg_id;          /**< Message ID – the ID of the message (subID under the message type) */
    uint32_t         ex_id;           /**< Exchange ID for message tracking between endpoints */
    bal_subsystem    sender;          /**< Sender subsystem - used for additional validation */
    uint32_t         timestamp;       /**< Timestamp when the message was sent */
    bcmos_sem        sem;             /**< Semaphore used for inter-thread communication */
    void*            scratchpad;      /**< Scratchpad used for inter-thread communication */
    uint32_t         access_term_id;  /**< Access Term Id for this BAL message */
    uint8_t          payload[];       /**< Payload follows the header */
} bal_comm_msg_hdr;

typedef uint32_t bcmbal_object_ver;              /**< The attribute type in the object info structure */

/** Bitmask of object attributes that are specified in an object (1 = specified, 0 = not specified) */
typedef uint64_t bcmbal_presence_mask;

/** Presence mask indicating all fields present */
#define BCMBAL_PRESENCE_MASK_ALL ((bcmbal_presence_mask)0xFFFFFFFFFFFFFFFF)

/** Helper type to determine what the data format of a message should look like */
typedef enum bcmbal_mgt_group
{
    BCMBAL_MGT_GROUP_KEY,               /**< Key that uniquely identifies object instance */
    BCMBAL_MGT_GROUP_CFG,               /**< Configuration (get/set/clear) */
    BCMBAL_MGT_GROUP_STAT,              /**< Statistics */
    BCMBAL_MGT_GROUP_AUTO,              /**< Autonomous indications */
    BCMBAL_MGT_GROUP_AUTO_CFG,          /**< Autonomous indication configuration */
    BCMBAL_MGT_GROUP__NUM_OF
} bcmbal_mgt_group;

/** Object message type. Can be a combination of flags. */
typedef enum bcmbal_obj_msg_type
{
    BCMBAL_OBJ_MSG_TYPE_GET   = 0x01,   /**< Get configuration parameters */
    BCMBAL_OBJ_MSG_TYPE_SET   = 0x02,   /**< Set configuration parameters */
    BCMBAL_OBJ_MSG_TYPE_CLEAR = 0x04,   /**< Clear configuration parameters */
} bcmbal_obj_msg_type;

/** Object message direction - request or response. */
typedef enum bcmbal_obj_msg_dir
{
    BCMBAL_OBJ_MSG_DIR_REQUEST,
    BCMBAL_OBJ_MSG_DIR_RESPONSE
} bcmbal_obj_msg_dir;

#define BCMBAL_OBJ_INIT_VAL  0xdeadbeef /**< The value of the obj_init_val after macro initialization */

#define BCMBAL_ERR_FIELD_NONE 0xffff    /**< Value of err_field_idx if error is not related attribute validation */

/** Information common to all BAL objects */
typedef struct bcmbal_obj
{
    bal_comm_msg_hdr     comm_hdr;      /**< Communication header */
    bcmbal_object_ver    om_version;    /**< Version of the Object Model definition/structure */
    bcmbal_obj_id        obj_type;      /**< An enumerated ID associated with the object being specified */
    bcmbal_mgt_group     group;         /**< Management group */
    uint16_t             subgroup;      /**< Subgroup for indications */
    bcmbal_obj_msg_type  type;          /**< Type (e.g. get / set / clear)  */
    bcmbal_obj_msg_dir   dir;           /**< Direction - request / response */
    bcmos_errno          status;        /**< BAL status code (BCM_ERR_OK–success, error code otherwise) */
    bcmbal_presence_mask presence_mask; /**< Indicates which attribute parameters are present */
    uint16_t             err_field_idx; /**< if status != BCM_ERR_OK: index of erroneous attribute or BCMBAL_ERR_FIELD_NONE */
    char                 err_text[BCMBAL_MAX_ERR_TEXT_LENGTH];  /**< if status != BCM_ERR_OK: Error text */

    /* The following fields are internal. They are not sent on the line */
    void                *list_buf;      /**< Memory buffer in which to store variable-sized lists when unpacking */
    uint32_t             list_buf_size; /**< Number of bytes in the variable-sized list buffer */
    uint32_t             obj_init_val;  /**< An field that is set on INIT macro call, and checked by the API */
} bcmbal_obj;

#define BCMBAL_OBJ_PTR( a ) (&((a).hdr))

#define CHECK_OBJ_IND_SIZE( _obj )  BUG_ON(sizeof(bcmbal_ ## _obj ## _cfg_data) != sizeof(bcmbal_ ## _obj ## _ind_data))

/** Information structure for use with BAL configuration API (get/set/clear) */
typedef struct bcmbal_cfg
{
    bcmbal_obj hdr;
} bcmbal_cfg;

/** Information structure for BAL statistics API */
typedef struct bcmbal_stat
{
    bcmbal_obj hdr;
} bcmbal_stat;

/** Information structure for BAL indications */
typedef struct bcmbal_auto
{
    bcmbal_obj hdr;
} bcmbal_auto;

/** Information structure for BAL indication configuration API */
typedef struct bcmbal_auto_cfg
{
    bcmbal_obj hdr;
} bcmbal_auto_cfg;

/** Whether we pack the entire structure of a message */
static inline bcmos_bool bcmbal_obj_msg_should_pack_data(const bcmbal_obj *msg)
{
    switch (msg->group)
    {
        case BCMBAL_MGT_GROUP_CFG:
        case BCMBAL_MGT_GROUP_STAT:
            if ((msg->type & BCMBAL_OBJ_MSG_TYPE_GET))
            {
                return (msg->dir == BCMBAL_OBJ_MSG_DIR_RESPONSE);
            }
            else if ((msg->type & BCMBAL_OBJ_MSG_TYPE_SET))
            {
                return (msg->dir == BCMBAL_OBJ_MSG_DIR_REQUEST);
            }
            else
            {
                return BCMOS_FALSE;
            }

        case BCMBAL_MGT_GROUP_AUTO_CFG:
            return BCMOS_FALSE;

        default:
            return BCMOS_TRUE;
    }
}

/** Get the packed length of the header portion of an object message */
static inline int32_t bcmbal_obj_msg_hdr_get_packed_length(const bcmbal_obj *msg)
{
    return 22 + ((msg->status != BCM_ERR_OK) ? strlen(msg->err_text) + sizeof(uint16_t) : 0);
}

/** Pack a message header to a byte stream */
static inline bcmos_errno bcmbal_obj_msg_hdr_pack(const bcmbal_obj *msg, bcmbal_buf *buf)
{
    bcmos_bool ret;

    ret =        bcmbal_buf_write_u32(buf, (uint32_t)msg->om_version);
    ret = ret && bcmbal_buf_write_u8(buf, (uint32_t)msg->obj_type);
    ret = ret && bcmbal_buf_write_u8(buf, (uint8_t)msg->group);
    ret = ret && bcmbal_buf_write_u16(buf, msg->subgroup);
    ret = ret && bcmbal_buf_write_u8(buf, (uint8_t)msg->type);
    ret = ret && bcmbal_buf_write_u8(buf, (uint8_t)msg->dir);
    ret = ret && bcmbal_buf_write_s16(buf, (int16_t)msg->status);
    ret = ret && bcmbal_buf_write_u64(buf, (uint64_t)msg->presence_mask);
    ret = ret && bcmolt_buf_write_u16(buf, msg->err_field_idx);
    if (msg->status != BCM_ERR_OK)
    {
        uint16_t len = strlen(msg->err_text);
        ret = ret && bcmolt_buf_write_u16(buf, len);
        ret = ret && bcmolt_buf_write(buf, msg->err_text, len);
    }

    return ret ? BCM_ERR_OK : BCM_ERR_OVERFLOW;
}

/** Unpack a message header from a byte stream */
static inline bcmos_errno bcmbal_obj_msg_hdr_unpack(bcmbal_obj *msg, bcmbal_buf *buf)
{
    uint32_t   om_version;
    uint8_t    obj_type;
    uint8_t    group;
    uint16_t   subgroup;
    uint8_t    type;
    uint8_t    dir;
    int16_t    status;
    uint64_t   presence_mask;
    uint16_t   err_field_idx;
    bcmos_bool ret;

    ret =        bcmbal_buf_read_u32(buf, &om_version);
    ret = ret && bcmbal_buf_read_u8(buf, &obj_type);
    ret = ret && bcmbal_buf_read_u8(buf, &group);
    ret = ret && bcmbal_buf_read_u16(buf, &subgroup);
    ret = ret && bcmbal_buf_read_u8(buf, &type);
    ret = ret && bcmbal_buf_read_u8(buf, &dir);
    ret = ret && bcmbal_buf_read_s16(buf, &status);
    ret = ret && bcmbal_buf_read_u64(buf, &presence_mask);
    ret = ret && bcmolt_buf_read_u16(buf, &err_field_idx);
    if (status != BCM_ERR_OK)
    {
        uint16_t len = 0;
        ret = ret && bcmolt_buf_read_u16(buf, &len);
        if (len >= sizeof(msg->err_text))
            len = sizeof(msg->err_text) - 1;
        ret = ret && bcmolt_buf_read(buf, msg->err_text, len);
        msg->err_text[len] = 0;
    }
    else
    {
        msg->err_text[0] = 0;
    }
    if (ret)
    {
        msg->om_version = (bcmbal_object_ver)om_version;
        msg->obj_type = (bcmbal_obj_id)obj_type;
        msg->group = (bcmbal_mgt_group)group;
        msg->subgroup = subgroup;
        msg->type = (bcmbal_obj_msg_type)type;
        msg->dir = (bcmbal_obj_msg_dir)dir;
        msg->status = (bcmos_errno)status;
        msg->presence_mask = (bcmbal_presence_mask)presence_mask;
        msg->err_field_idx = err_field_idx;
    }

    return ret ? BCM_ERR_OK : BCM_ERR_OVERFLOW;
}

#ifdef ENABLE_LOG

/*lint -ecall(633, bcmolt_msg_err) - 4th argument will be a specific enum type, but must be treated as a uint16. */
/** Set message error. Cannot be static inline, as it uses variable argument list. */
bcmos_errno bcmbal_obj_err_set(bcmbal_obj *msg, dev_log_id log_id, bcmos_errno err, uint16_t err_field_idx, const char *fmt, ...)__attribute__((format(__printf__, 5, 6)));

#define BCMBAL_OBJ_ERR_SET(_msg, _log_id, _err, _err_field_idx, _fmt, ...) \
    bcmbal_obj_err_set(_msg, _log_id, _err, _err_field_idx, _fmt, ##__VA_ARGS__)


#else

/*lint -ecall(633, bcmolt_msg_err) - 4th argument will be a specific enum type, but must be treated as a uint16. */
/** Set message error. Cannot be static inline, as it uses variable argument list. */
bcmos_errno bcmbal_obj_err_set(bcmbal_obj *msg, bcmos_errno err, uint16_t err_field_idx, const char *fmt, ...)__attribute__((format(__printf__, 4, 5)));

/* _log_id parameter in the following macro is ignored */
#define BCMBAL_OBJ_ERR_SET(_msg, _log_id, _err, _err_field_idx, _fmt, ...) \
    bcmbal_obj_err_set(_msg, _err, _err_field_idx, _fmt, ##__VA_ARGS__)

#endif

#endif /* BAL_OBJ_H */
