#ifndef BAL_MODEL_TYPES
#define BAL_MODEL_TYPES

#include <bcmos_system.h>
#include "bal_obj.h"

/** \defgroup object_model_data_types BAL Object Model Data Types
 * @{
 */
typedef uint32_t bcmbal_access_id;                                  /**< bcmbal_access_id: typed alias for a 32-bit unsigned integer. */
typedef uint16_t bcmbal_aggregation_port_id;                        /**< bcmbal_aggregation_port_id: typed alias for a 16-bit unsigned integer. */
typedef uint64_t bcmbal_cookie;                                     /**< bcmbal_cookie: typed alias for a 64-bit unsigned integer. */
typedef uint32_t bcmbal_intf_id;                                    /**< bcmbal_intf_id: typed alias for a 32-bit unsigned integer. */
typedef uint32_t bcmbal_sub_id;                                     /**< bcmbal_sub_id: typed alias for a 32-bit unsigned integer. */
#define BCMBAL_SUB_ID_UNKNOWN   ((bcmbal_sub_id) 65535UL)
typedef uint16_t bcmbal_service_port_id;                            /**< bcmbal_service_port_id: typed alias for a 16-bit unsigned integer. */
typedef uint32_t bcmbal_time_quanta;                                /**< bcmbal_time_quanta: typed alias for a 32-bit unsigned integer. */
typedef uint32_t bcmbal_flow_id;                                    /**< bcmbal_flow_id: typed alias for a 32-bit unsigned integer. */
typedef uint32_t bcmbal_group_id;                                   /**< bcmbal_group_id: typed alias for a 32-bit unsigned integer. */
typedef uint32_t bcmbal_tm_sched_id;                                /**< bcmbal_tm_sched_id: typed alias for a 32-bit unsigned integer. */
#define BCMBAL_TM_SCHED_ID_UNKNOWN  ((bcmbal_tm_sched_id) 65535UL)
typedef uint16_t bcmbal_tm_queue_id;                                /**< bcmbal_tm_queue_id: typed alias for a 16-bit unsigned integer. */
#define BCMBAL_TM_QUEUE_ID_UNKNOWN  ((bcmbal_tm_queue_id) 65535U)
typedef uint8_t bcmbal_percent;                                     /**< bcmbal_percent: typed alias for a 8-bit unsigned integer. */
typedef uint8_t bcmbal_tm_priority;                                 /**< bcmbal_tm_priority: typed alias for a 8-bit unsigned integer. */
typedef uint16_t bcmbal_tm_sched_id_index;                          /**< bcmbal_tm_sched_id_index: typed alias for a 16-bit unsigned integer. */
typedef uint8_t bcmbal_tm_weight;                                   /**< bcmbal_tm_weight: typed alias for a 8-bit unsigned integer. */

/** action ID. 
 */
typedef enum bcmbal_action_id
{
    BCMBAL_ACTION_ID_NONE           = 0,
    BCMBAL_ACTION_ID_CMDS_BITMASK   = 0x0001,                       /**< Commands bitmask. */
    BCMBAL_ACTION_ID_O_VID          = 0x0002,                       /**< Outer vid. */
    BCMBAL_ACTION_ID_O_PBITS        = 0x0004,                       /**< Outer pbits. */
    BCMBAL_ACTION_ID_O_TPID         = 0x0008,                       /**< Outer tpid. */
    BCMBAL_ACTION_ID_I_VID          = 0x0010,                       /**< Inner vid. */
    BCMBAL_ACTION_ID_I_PBITS        = 0x0020,                       /**< Inner pbits. */
    BCMBAL_ACTION_ID_I_TPID         = 0x0040,                       /**< Inner tpid. */
    BCMBAL_ACTION_ID_ALL            = 0x007F                        /**< All fields */
} bcmbal_action_id;

/** action_cmd_id. 
 */
typedef enum bcmbal_action_cmd_id
{
    BCMBAL_ACTION_CMD_ID_NONE                           = 0,
    BCMBAL_ACTION_CMD_ID_XLATE_OUTER_TAG                = 0x0001,   /**< Translate outer tag. */
    BCMBAL_ACTION_CMD_ID_ADD_OUTER_TAG                  = 0x0002,   /**< Add outer tag. */
    BCMBAL_ACTION_CMD_ID_REMOVE_OUTER_TAG               = 0x0004,   /**< Remove outer tag. */
    BCMBAL_ACTION_CMD_ID_XLATE_INNER_TAG                = 0x0010,   /**< Translate inner tag. */
    BCMBAL_ACTION_CMD_ID_ADD_INNER_TAG                  = 0x0020,   /**< Add inner tag. */
    BCMBAL_ACTION_CMD_ID_REMOVE_INNER_TAG               = 0x0040,   /**< Remove inner tag. */
    BCMBAL_ACTION_CMD_ID_REMARK_OUTER_PBITS             = 0x0100,   /**< Set the outer tag pbits */
    BCMBAL_ACTION_CMD_ID_COPY_INNER_PBITS_TO_OUTER_PBITS= 0x0200,   /**< Copy the inner pbits to outer pbits */
    BCMBAL_ACTION_CMD_ID_REMARK_INNER_PBITS             = 0x1000,   /**< Set the outer tag pbits */
    BCMBAL_ACTION_CMD_ID_COPY_OUTER_PBITS_TO_INNER_PBITS= 0x2000,   /**< Copy the outer pbits to inner pbits */
    BCMBAL_ACTION_CMD_ID_DISCARD_DS_BCAST               = 0x00010000UL, /**< drop downstream broadcast packets. */
    BCMBAL_ACTION_CMD_ID_TRAP_TO_HOST                   = 0x00020000UL  /**< Not a valid action for a group object member */
} bcmbal_action_cmd_id;

/** alarm status. 
 */
typedef enum bcmbal_alarm_status
{
    BCMBAL_ALARM_STATUS_OFF                             = 0,            /**< alarm status is off */
    BCMBAL_ALARM_STATUS_ON                              = 1,            /**< alarm status is on */
    BCMBAL_ALARM_STATUS_NO__CHANGE                      = 2,            /**< alarm status should not be changed */
    BCMBAL_ALARM_STATUS__NUM_OF /**< Number of enum entries, not an entry itself. */
} bcmbal_alarm_status;

/** alloc type. 
 */
typedef enum bcmbal_alloc_type
{
    BCMBAL_ALLOC_TYPE_NONE                              = 0,    /**< none. */
    BCMBAL_ALLOC_TYPE_NSR                               = 1,    /**< no status report. */
    BCMBAL_ALLOC_TYPE_SR                                = 2,    /**< status report. */
    BCMBAL_ALLOC_TYPE__NUM_OF   /**< Number of enum entries, not an entry itself. */
} bcmbal_alloc_type;

/** Sign. 
 */
typedef enum bcmbal_sign
{
    BCMBAL_SIGN_POSITIVE                                = 0,    /**< Positive. */
    BCMBAL_SIGN_NEGATIVE                                = 1,    /**< Negative. */
    BCMBAL_SIGN__NUM_OF /**< Number of enum entries, not an entry itself. */
} bcmbal_sign;

/**  XGPON ni upstream line rate capabilities 
 */
typedef enum bcmbal_upstream_line_rate_capabilities
{
    BCMBAL_UPSTREAM_LINE_RATE_CAPABILITIES_RATE_2_P_5_G                 = 0,    /**< 2.5G Upstream line rate capability. */
    BCMBAL_UPSTREAM_LINE_RATE_CAPABILITIES_RATE_10_G                    = 1,    /**< 10g upstream line rate capability . */
    BCMBAL_UPSTREAM_LINE_RATE_CAPABILITIES_RATE_DUAL_2_P_5_G_AND_10_G   = 2,    /**< dual 2.5g and 10g upstream line rate capability . */
    BCMBAL_UPSTREAM_LINE_RATE_CAPABILITIES__NUM_OF  /**< Number of enum entries, not an entry itself. */
} bcmbal_upstream_line_rate_capabilities;

/** Link Type. 
 */
typedef enum bcmbal_link_type
{
    BCMBAL_LINK_TYPE_UNSPECIFIED                                        = 0,    /**<  link type unspecified  */
    BCMBAL_LINK_TYPE_B                                                  = 1,    /**< link type a is not supported, link type b is supported */
    BCMBAL_LINK_TYPE_A                                                  = 2,    /**< link type a is supported, link type b is not supported */
    BCMBAL_LINK_TYPE_A_AND_B                                            = 3,    /**< both link types a and b are supported  */
    BCMBAL_LINK_TYPE__NUM_OF    /**< Number of enum entries, not an entry itself. */
} bcmbal_link_type;

/** Calibration record. 
 */
typedef enum bcmbal_calibration_record
{
    BCMBAL_CALIBRATION_RECORD_UNSPECIFIED                               = 0,    /**< Unspecified. */
    BCMBAL_CALIBRATION_RECORD_UNCALIBRATED                              = 1,    /**< Uncalibrated. */
    BCMBAL_CALIBRATION_RECORD_LOOSE                                     = 2,    /**< Loose. */
    BCMBAL_CALIBRATION_RECORD_SUFFICIENT                                = 3,    /**< Sufficient. */
    BCMBAL_CALIBRATION_RECORD__NUM_OF   /**< Number of enum entries, not an entry itself. */
} bcmbal_calibration_record;

/** classifier ID. 
 */
typedef enum bcmbal_classifier_id
{
    BCMBAL_CLASSIFIER_ID_NONE                                           = 0,
    BCMBAL_CLASSIFIER_ID_O_TPID                                         = 0x0001,   /**< Outer TPID of the packet to be classified */
    BCMBAL_CLASSIFIER_ID_O_VID                                          = 0x0002,   /**< Outer VID of the packet to be classified */
    BCMBAL_CLASSIFIER_ID_I_TPID                                         = 0x0004,   /**< Inner TPID of the packet to be classified */
    BCMBAL_CLASSIFIER_ID_I_VID                                          = 0x0008,   /**< Inner VID of the packet to be classified */
    BCMBAL_CLASSIFIER_ID_O_PBITS                                        = 0x0010,   /**< Outer PBITS of the packet to be classified */
    BCMBAL_CLASSIFIER_ID_I_PBITS                                        = 0x0020,   /**< Inner PBITS of the packet to be classified */
    BCMBAL_CLASSIFIER_ID_ETHER_TYPE                                     = 0x0040,   /**< Ethertype of the packet to be classified */
    BCMBAL_CLASSIFIER_ID_DST_MAC                                        = 0x0080,   /**< Destination MAC address of the packet to be classified */
    BCMBAL_CLASSIFIER_ID_SRC_MAC                                        = 0x0100,   /**< Source MAC address of the packet to be classified */
    BCMBAL_CLASSIFIER_ID_IP_PROTO                                       = 0x0200,   /**< IP protocol of the packet to be classified */
    BCMBAL_CLASSIFIER_ID_DST_IP                                         = 0x0400,   /**< Destination IP address of the packet to be classified */
    BCMBAL_CLASSIFIER_ID_SRC_IP                                         = 0x0800,   /**< Source IP address of the packet to be classified */
    BCMBAL_CLASSIFIER_ID_SRC_PORT                                       = 0x1000,   /**< Source port of the packet to be classified */
    BCMBAL_CLASSIFIER_ID_DST_PORT                                       = 0x2000,   /**< Destination port of the packet to be classified */
    BCMBAL_CLASSIFIER_ID_PKT_TAG_TYPE                                   = 0x4000,   /**< The tag type of the ingress packets */
    BCMBAL_CLASSIFIER_ID_ALL                                            = 0x7FFF    /**< All fields */
} bcmbal_classifier_id;

/** Packet tag type. 
 */
typedef enum bcmbal_pkt_tag_type
{
    BCMBAL_PKT_TAG_TYPE_NONE                                            = 0,
    BCMBAL_PKT_TAG_TYPE_UNTAGGED                                        = 0x0001,   /**< Untagged. */
    BCMBAL_PKT_TAG_TYPE_SINGLE_TAG                                      = 0x0002,   /**< Single tag. */
    BCMBAL_PKT_TAG_TYPE_DOUBLE_TAG                                      = 0x0004    /**< Double tag. */
} bcmbal_pkt_tag_type;

/** Generic enable/disable enumeration 
 */
typedef enum bcmbal_control
{
    BCMBAL_CONTROL_DISABLE                                              = 0,        /**< disable. */
    BCMBAL_CONTROL_ENABLE                                               = 1,        /**< enable. */
    BCMBAL_CONTROL__NUM_OF  /**< Number of enum entries, not an entry itself. */
} bcmbal_control;

/** Destination type. 
 */
typedef enum bcmbal_dest_type
{
    BCMBAL_DEST_TYPE_NNI                                                = 1,    /**< for packets being sent to the NNI */
    BCMBAL_DEST_TYPE_SUB_TERM                                           = 2,    /**< for packets being sent to a subscriber terminal */
    BCMBAL_DEST_TYPE_SVC_PORT                                           = 3,    /**< for packet being sent to the pon service port */
    BCMBAL_DEST_TYPE_ITU_OMCI_CHANNEL                                   = 4,    /**< for itu omci channel packets */
    BCMBAL_DEST_TYPE_IEEE_OAM_CHANNEL                                   = 5     /**< for ieee oam channel packets */
} bcmbal_dest_type;

/** Downstrean action for unknown packets. 
 */
typedef enum bcmbal_ds_miss_mode
{
    BCMBAL_DS_MISS_MODE_DISCARD                                         = 0,    /**< Discard. */
    BCMBAL_DS_MISS_MODE_BROADCAST                                       = 1,    /**< Broadcast. */
    BCMBAL_DS_MISS_MODE_VID                                             = 2,    /**< Vid. */
    BCMBAL_DS_MISS_MODE__NUM_OF /**< Number of enum entries, not an entry itself. */
} bcmbal_ds_miss_mode;

/** error enumeration. 
 */
typedef enum bcmbal_errno
{
    BCMBAL_ERRNO_OK                                                     = 0,    /**< no error. */
    BCMBAL_ERRNO__NUM_OF    /**< Number of enum entries, not an entry itself. */
} bcmbal_errno;

/** extended epon dba ID. 
 */
typedef enum bcmbal_extended_epon_dba_id
{
    BCMBAL_EXTENDED_EPON_DBA_ID_NONE                                    = 0,
    BCMBAL_EXTENDED_EPON_DBA_ID_POLLING_INTERVAL_US                     = 0x0001,   /**< The amount of time between when this LLID last reported upstream data and when it will next be polled (approximate: rounded down to the nearest 65.536 us). */
    BCMBAL_EXTENDED_EPON_DBA_ID_GRANT_THRESHOLD_TQ                      = 0x0002,   /**< Used to determine the maximum grant size that will be issued to this LLID (in TQ; rounded up to the nearest 128TQ; 1TQ = 16ns = 2Bytes@1G or 20Bytes@10G). */
    BCMBAL_EXTENDED_EPON_DBA_ID_CIR_PRIORITY                            = 0x0004,   /**< The priority of the CIR scheduling element. */
    BCMBAL_EXTENDED_EPON_DBA_ID_CIR_WEIGHT_TQ                           = 0x0008,   /**< The weight of the CIR scheduler (in TQ rounded up to nearest 128). Must be greater than or equal to Grant Threshold. */
    BCMBAL_EXTENDED_EPON_DBA_ID_PIR_PRIORITY                            = 0x0010,   /**< The priority of the PIR scheduling element. */
    BCMBAL_EXTENDED_EPON_DBA_ID_PIR_WEIGHT_TQ                           = 0x0020,   /**< The weight of the PIR scheduler (in TQ rounded up to nearest 128). Must be greater than or equal to Grant Threshold. */
    BCMBAL_EXTENDED_EPON_DBA_ID_TDM_GRANT_SIZE_TQ                       = 0x0040,   /**< Size of TDM grants (in TQ). */
    BCMBAL_EXTENDED_EPON_DBA_ID_TDM_GRANT_INTERVAL_US                   = 0x0080,   /**< Interval between TDM grants (in us). */
    BCMBAL_EXTENDED_EPON_DBA_ID_ALL                                     = 0x00FF    /**< All fields */
} bcmbal_extended_epon_dba_id;

/** Polling Interval. 
 */
typedef enum bcmbal_polling_interval
{
    BCMBAL_POLLING_INTERVAL_POLLING_DISABLED                            = 0,        /**< No polling gates will be sent to this LLID. */
    BCMBAL_POLLING_INTERVAL_US_500                                      = 500,      /**< 500 us. */
    BCMBAL_POLLING_INTERVAL_MS_1                                        = 1000,     /**< 1 ms. */
    BCMBAL_POLLING_INTERVAL_MS_2                                        = 2000,     /**< 2 ms. */
    BCMBAL_POLLING_INTERVAL_MS_4                                        = 4000,     /**< 4 ms. */
    BCMBAL_POLLING_INTERVAL_MS_8                                        = 8000,     /**< 8 ms. */
    BCMBAL_POLLING_INTERVAL_MS_16                                       = 16000     /**< 16 ms. */
} bcmbal_polling_interval;

/** extended itu dba ID. 
 */
typedef enum bcmbal_extended_itu_dba_id
{
    BCMBAL_EXTENDED_ITU_DBA_ID_NONE                                     = 0,
    BCMBAL_EXTENDED_ITU_DBA_ID_EXTRA_BW_ELIG                            = 0x0001,   /**< Extra BW eligibility type */
    BCMBAL_EXTENDED_ITU_DBA_ID_NRT_CBR                                  = 0x0002,   /**< NRT CBR in Bytes per second */
    BCMBAL_EXTENDED_ITU_DBA_ID_RT_CBR                                   = 0x0004,   /**< RT_CBR in Bytes per second */
    BCMBAL_EXTENDED_ITU_DBA_ID_RT_PROFILE                               = 0x0008,   /**< RT Profile */
    BCMBAL_EXTENDED_ITU_DBA_ID_NRT_PROFILE                              = 0x0010,   /**< NRT Profile */
    BCMBAL_EXTENDED_ITU_DBA_ID_ALLOC_TYPE                               = 0x0020,   /**< alloc_type. */
    BCMBAL_EXTENDED_ITU_DBA_ID_ALL                                      = 0x003F    /**< All fields */
} bcmbal_extended_itu_dba_id;

/** Extra BW Eligibility Type 
 */
typedef enum bcmbal_extra_bw_eligibility_type
{
    BCMBAL_EXTRA_BW_ELIGIBILITY_TYPE_NONE                               = 0,        /**< None */
    BCMBAL_EXTRA_BW_ELIGIBILITY_TYPE_NOT_ASSURED                        = 1,        /**< Not assured */
    BCMBAL_EXTRA_BW_ELIGIBILITY_TYPE_BEST_EFFORT                        = 2,        /**< Best effort */
    BCMBAL_EXTRA_BW_ELIGIBILITY_TYPE__NUM_OF    /**< Number of enum entries, not an entry itself. */
} bcmbal_extra_bw_eligibility_type;

/** Flow Type. 
 */
typedef enum bcmbal_flow_type
{
    BCMBAL_FLOW_TYPE_UPSTREAM                                           = 1,    /**< Upstream flow */
    BCMBAL_FLOW_TYPE_DOWNSTREAM                                         = 2,    /**< Downstream Flow */
    BCMBAL_FLOW_TYPE_BROADCAST                                          = 3,    /**< Broadcast Flow */
    BCMBAL_FLOW_TYPE_MULTICAST                                          = 4     /**< Multicast Flow */
} bcmbal_flow_type;

/** Member operation type. 
 */
typedef enum bcmbal_group_member_cmd
{
    BCMBAL_GROUP_MEMBER_CMD_ADD_MEMBERS                                 = 1,    /**< Add new members. */
    BCMBAL_GROUP_MEMBER_CMD_REM_MEMBERS                                 = 2,    /**< Remove existing members. */
    BCMBAL_GROUP_MEMBER_CMD_SET_MEMBERS                                 = 3     /**< Replace members with new set. */
} bcmbal_group_member_cmd;

/** Interface type in DS direction. 
 */
typedef enum bcmbal_intf_type_ds
{
    BCMBAL_INTF_TYPE_DS_PON                                             = 1,    /**< PON Interface. */
    BCMBAL_INTF_TYPE_DS_EPON_1G_PATH                                    = 2,    /**< EPON 1G Path. */
    BCMBAL_INTF_TYPE_DS_EPON_10G_PATH                                   = 3     /**< EPON 10G Path. */
} bcmbal_intf_type_ds;

/** typeof the group 
 */
typedef enum bcmbal_group_type
{
    BCMBAL_GROUP_TYPE_NONE                                              = 0,    /**< no type set */
    BCMBAL_GROUP_TYPE_MULTICAST                                         = 1,    /**< used as multicast group */
    BCMBAL_GROUP_TYPE_N_TO_1                                            = 2,    /**< used as n:1 group */
    BCMBAL_GROUP_TYPE__NUM_OF   /**< Number of enum entries, not an entry itself. */
} bcmbal_group_type;

/** interface_ngpon2 ID. 
 */
typedef enum bcmbal_interface_ngpon_2_id
{
    BCMBAL_INTERFACE_NGPON_2_ID_NONE                                    = 0,
    BCMBAL_INTERFACE_NGPON_2_ID_SYS_ID                                  = 0x0001,   /**< 20-bit identifier of the NGPON2 system, should match a key of exysting sys_channel_profile object */
    BCMBAL_INTERFACE_NGPON_2_ID_OPERATION_CONTROL                       = 0x0002,   /**< operation_control. */
    BCMBAL_INTERFACE_NGPON_2_ID_TOL                                     = 0x0004,   /**< Transmit Optical Level. An indication of the current OLT CT transceiver channel launch power into the ODN */
    BCMBAL_INTERFACE_NGPON_2_ID_ALL                                     = 0x0007    /**< All fields */
} bcmbal_interface_ngpon_2_id;

/** Operation control ID. 
 */
typedef enum bcmbal_operation_control_id
{
    BCMBAL_OPERATION_CONTROL_ID_NONE                                    = 0,
    BCMBAL_OPERATION_CONTROL_ID_RE                                      = 0x0001,   /**<  Indicates whether the Transmit Optical Level (TOL) contains the launch power of the OTL (RE=0) or of a reach extender (RE=1) */
    BCMBAL_OPERATION_CONTROL_ID_ODN_CLASS                               = 0x0002,   /**<  Identifies the nominal optical parameters of the transceiver according to the ODN Optical Path Loss (OPL) */
    BCMBAL_OPERATION_CONTROL_ID_DS_FEC_MODE                             = 0x0004,   /**<  Enable/Disable the downstream FEC. Default is Enable. Attribute can be set only when PON NI state is Inactive */
    BCMBAL_OPERATION_CONTROL_ID_PROTOCOL                                = 0x0008,   /**< When system mode is NGPON2, this parameter Indicate the TC layer protocol: ITU-T G.989.3 or ITU-T G.987.3 */
    BCMBAL_OPERATION_CONTROL_ID_DS_LINK_TYPE                            = 0x0010,   /**<  Optical link type (Unspecified, A, B, Both) */
    BCMBAL_OPERATION_CONTROL_ID_PON_ID                                  = 0x0020,   /**<  Identifies the TWDM channel termination within a certain domain  */
    BCMBAL_OPERATION_CONTROL_ID_C                                       = 0x0040,   /**< Transmit optical level (TOL) reference point indicator: S/R-CG or S/R-CP  */
    BCMBAL_OPERATION_CONTROL_ID_ALL                                     = 0x007F    /**< All fields */
} bcmbal_operation_control_id;

/** ODN Class. 
 */
typedef enum bcmbal_odn_class
{
    BCMBAL_ODN_CLASS_N_1                                                = 0,        /**< N1. */
    BCMBAL_ODN_CLASS_N_2                                                = 4,        /**< N2. */
    BCMBAL_ODN_CLASS_E_1                                                = 2,        /**< E1. */
    BCMBAL_ODN_CLASS_E_2                                                = 3         /**< E2. */
} bcmbal_odn_class;

/** TC protocol. 
 */
typedef enum bcmbal_tc_protocol
{
    BCMBAL_TC_PROTOCOL_TC_LAYER_PROTOCOL_G_987_P_3                      = 0,        /**< TC layer protocol G.987.3. */
    BCMBAL_TC_PROTOCOL_TC_LAYER_PROTOCOL_G_989_P_3                      = 1,        /**< TC layer protocol G.989.3 . */
    BCMBAL_TC_PROTOCOL__NUM_OF  /**< Number of enum entries, not an entry itself. */
} bcmbal_tc_protocol;

/** Interface type. 
 */
typedef enum bcmbal_intf_type
{
    BCMBAL_INTF_TYPE_NNI                                                = 0,    /**< NNI Interface. */
    BCMBAL_INTF_TYPE_PON                                                = 1,    /**< PON Interface. */
    BCMBAL_INTF_TYPE_EPON_1G_PATH                                       = 2,    /**< EPON 1G Path. */
    BCMBAL_INTF_TYPE_EPON_10G_PATH                                      = 3,    /**< EPON 10G Path. */
    BCMBAL_INTF_TYPE__NUM_OF    /**< Number of enum entries, not an entry itself. */
} bcmbal_intf_type;

/** Interworking Function Mode. 
 */
typedef enum bcmbal_iwf_mode
{
    BCMBAL_IWF_MODE_DIRECT_MAPPING                                      = 0,    /**< Direct mapping. */
    BCMBAL_IWF_MODE_PER_FLOW                                            = 1,    /**< Per flow . */
    BCMBAL_IWF_MODE__NUM_OF /**< Number of enum entries, not an entry itself. */
} bcmbal_iwf_mode;

/** The PON family 
 */
typedef enum bcmbal_pon_family
{
    BCMBAL_PON_FAMILY_ITU                                               = 0,    /**< ITU family. */
    BCMBAL_PON_FAMILY_IEEE                                              = 1,    /**< IEEE family. */
    BCMBAL_PON_FAMILY_INVALID                                           = 2,    /**< INVALID . */
    BCMBAL_PON_FAMILY__NUM_OF   /**< Number of enum entries, not an entry itself. */
} bcmbal_pon_family;

/** The PON sub-family 
 */
typedef enum bcmbal_pon_sub_family
{
    BCMBAL_PON_SUB_FAMILY_GPON                                          = 0,    /**< GPON. */
    BCMBAL_PON_SUB_FAMILY_XGPON                                         = 1,    /**< XGPON. */
    BCMBAL_PON_SUB_FAMILY_XGS                                           = 2,    /**< XGS. */
    BCMBAL_PON_SUB_FAMILY_EPON_TDMA                                     = 3,    /**<  EPON_TDMA. */
    BCMBAL_PON_SUB_FAMILY_EPON_1_G                                      = 4,    /**< EPON_1G. */
    BCMBAL_PON_SUB_FAMILY_EPON_10_G                                     = 5,    /**< EPON_10G. */
    BCMBAL_PON_SUB_FAMILY_XGS_XGPON_TDMA                                = 6,    /**< XGS_XGPON_TDMA. */
    BCMBAL_PON_SUB_FAMILY_NGPON_2                                       = 7,    /**< NGPON2. */
    BCMBAL_PON_SUB_FAMILY_INVALID                                       = 8,    /**< INVALID. */
    BCMBAL_PON_SUB_FAMILY__NUM_OF   /**< Number of enum entries, not an entry itself. */
} bcmbal_pon_sub_family;

/** Result. 
 */
typedef enum bcmbal_result
{
    BCMBAL_RESULT_SUCCESS                                               = 0,    /**< Success. */
    BCMBAL_RESULT_FAIL                                                  = 1,    /**< Failure. */
    BCMBAL_RESULT__NUM_OF   /**< Number of enum entries, not an entry itself. */
} bcmbal_result;

/** SLA ID. 
 */
typedef enum bcmbal_sla_id
{
    BCMBAL_SLA_ID_NONE                                                  = 0,
    BCMBAL_SLA_ID_MIN_RATE                                              = 0x0001,   /**< The minimal rate for this flow, in kilobits per second (optional) */
    BCMBAL_SLA_ID_MAX_RATE                                              = 0x0002,   /**< The maximum rate for this flow, in kilobits per second (optional) */
    BCMBAL_SLA_ID_ALL                                                   = 0x0003    /**< All fields */
} bcmbal_sla_id;

/** Admin state values for access terminal object 
 */
typedef enum bcmbal_state
{
    BCMBAL_STATE_UP                                                     = 0,        /**< Admin state up */
    BCMBAL_STATE_DOWN                                                   = 1,        /**< Admin state down */
    BCMBAL_STATE__NUM_OF    /**< Number of enum entries, not an entry itself. */
} bcmbal_state;

/** Oper status values 
 */
typedef enum bcmbal_status
{
    BCMBAL_STATUS_UP                                                    = 0,    /**< Oper status up */
    BCMBAL_STATUS_DOWN                                                  = 1,    /**< Oper status down */
    BCMBAL_STATUS_NOT_PRESENT                                           = 2,    /**< Oper status not present */
    BCMBAL_STATUS__NUM_OF   /**< Number of enum entries, not an entry itself. */
} bcmbal_status;

/** Sub Term Act Fail Reason. 
 */
typedef enum bcmbal_sub_term_act_fail_reason
{
    BCMBAL_SUB_TERM_ACT_FAIL_REASON_NONE                                = 0,    /**< Reason not set */
    BCMBAL_SUB_TERM_ACT_FAIL_REASON_RANGING                             = 1,    /**< ITU Ranging Failed */
    BCMBAL_SUB_TERM_ACT_FAIL_REASON_PASSWORD_AUTHENTICATION             = 2,    /**< ITU Authentication Failed */
    BCMBAL_SUB_TERM_ACT_FAIL_REASON_LOS                                 = 3,    /**< ITU LOS */
    BCMBAL_SUB_TERM_ACT_FAIL_REASON_ONU_ALARM                           = 4,    /**< ITU ONU Alarm */
    BCMBAL_SUB_TERM_ACT_FAIL_REASON_SWITCH_OVER                         = 5,    /**< ITU Protection Switch Over */
    BCMBAL_SUB_TERM_ACT_FAIL_REASON__NUM_OF /**< Number of enum entries, not an entry itself. */
} bcmbal_sub_term_act_fail_reason;

/** sub_term_rate. 
 */
typedef enum bcmbal_sub_term_rate
{
    BCMBAL_SUB_TERM_RATE_SYMMETRIC_10_G                                 = 0,    /**< ITU: XGS-PON */
    BCMBAL_SUB_TERM_RATE_ASYMMETRIC_10_G                                = 1,    /**< ITU: XG-PON1 */
    BCMBAL_SUB_TERM_RATE_SYMMETRIC_1_G                                  = 2,    /**< ITU: GPON */
    BCMBAL_SUB_TERM_RATE__NUM_OF    /**< Number of enum entries, not an entry itself. */
} bcmbal_sub_term_rate;

/** The type of release version 
 */
typedef enum bcmbal_version_type
{
    BCMBAL_VERSION_TYPE_UNKNOWN                                         = 0,    /**< illegal */
    BCMBAL_VERSION_TYPE_RELEASE                                         = 1,    /**< released version */
    BCMBAL_VERSION_TYPE_DEVELOPMENT                                     = 2,    /**< debug version */
    BCMBAL_VERSION_TYPE__NUM_OF /**< Number of enum entries, not an entry itself. */
} bcmbal_version_type;

/** System profile ID. 
 */
typedef enum bcmbal_system_profile_id
{
    BCMBAL_SYSTEM_PROFILE_ID_NONE                                       = 0,
    BCMBAL_SYSTEM_PROFILE_ID_VERSION                                    = 0x0001,   /**< System profile version. */
    BCMBAL_SYSTEM_PROFILE_ID_CHANNEL_SPACING                            = 0x0002,   /**< An integer indicating the channel spacing in units of 1GHz  */
    BCMBAL_SYSTEM_PROFILE_ID_US_OPERATING_WAVELENGTH_BANDS              = 0x0004,   /**< US  operating wavelength bands. */
    BCMBAL_SYSTEM_PROFILE_ID_US_MSE                                     = 0x0008,   /**<  Upstream Maximum Spectral Excursion (MSE) represented as an unsigned integer indicating the value in units of 1GHz */
    BCMBAL_SYSTEM_PROFILE_ID_LOOSE_CALIBRATION_BOUND                    = 0x0010,   /**< Spectral excursion bound below which a TWDM ONU can be considered as loosely calibrated  */
    BCMBAL_SYSTEM_PROFILE_ID_FSR                                        = 0x0020,   /**<  If a cyclic WM is used in the upstream, Free Spectral Range indicates the value in units of 0.1 GHz */
    BCMBAL_SYSTEM_PROFILE_ID_TWDM_CHANNEL_COUNT                         = 0x0040,   /**<  The number of Channel_Profile PLOAM messages with distinct Channel Profile indices that an ONU can expect to receive while listening to this downstream wavelength channel */
    BCMBAL_SYSTEM_PROFILE_ID_ALL                                        = 0x007F    /**< All fields */
} bcmbal_system_profile_id;

/** US  operating wavelength bands. 
 */
typedef enum bcmbal_us_operating_wavelength_bands
{
    BCMBAL_US_OPERATING_WAVELENGTH_BANDS_EXPANDED_SPECTRUM_WIDE_BAND    = 0,        /**< expanded spectrum wide band option . */
    BCMBAL_US_OPERATING_WAVELENGTH_BANDS_EXPANDED_SPECTRUM_REDUCED_BAND = 1,        /**< expanded spectrum reduced band option. */
    BCMBAL_US_OPERATING_WAVELENGTH_BANDS_EXPANDED_SPECTRUM_NARROW_BAND  = 2,        /**< expanded spectrum narrow band option. */
    BCMBAL_US_OPERATING_WAVELENGTH_BANDS_SHARED_SPECTRUM_WIDE_BAND      = 3,        /**< shared spectrum wide band option. */
    BCMBAL_US_OPERATING_WAVELENGTH_BANDS_SHARED_SPECTRUM_REDUCED_BAND   = 4,        /**< shared spectrum reduced band option . */
    BCMBAL_US_OPERATING_WAVELENGTH_BANDS_SHARED_SPECTRUM_NARROW_BAND    = 5,        /**< shared spectrum wide narrow option . */
    BCMBAL_US_OPERATING_WAVELENGTH_BANDS__NUM_OF    /**< Number of enum entries, not an entry itself. */
} bcmbal_us_operating_wavelength_bands;

/** Buffer Admission Control Type 
 */
typedef enum bcmbal_tm_bac_type
{
    BCMBAL_TM_BAC_TYPE_TAILDROP                                         = 0,    /**< Taildrop  */
    BCMBAL_TM_BAC_TYPE_WTAILDROP                                        = 1,    /**< Weighted taildrop */
    BCMBAL_TM_BAC_TYPE_RED                                              = 2,    /**< Random Early Discard */
    BCMBAL_TM_BAC_TYPE_WRED                                             = 3,    /**< Weighted Random Early Discard */
    BCMBAL_TM_BAC_TYPE__NUM_OF  /**< Number of enum entries, not an entry itself. */
} bcmbal_tm_bac_type;

/** TM Creation Mode 
 */
typedef enum bcmbal_tm_creation_mode
{
    BCMBAL_TM_CREATION_MODE_MANUAL                                      = 0,    /**< tm object created manually */
    BCMBAL_TM_CREATION_MODE_AUTO                                        = 1,    /**< tm object created automatically */
    BCMBAL_TM_CREATION_MODE__NUM_OF /**< Number of enum entries, not an entry itself. */
} bcmbal_tm_creation_mode;

/** Traffic Direction 
 */
typedef enum bcmbal_tm_sched_dir
{
    BCMBAL_TM_SCHED_DIR_US                                              = 1,    /**< Upstream */
    BCMBAL_TM_SCHED_DIR_DS                                              = 2     /**< Downstream */
} bcmbal_tm_sched_dir;

/** TM Scheduler Owner Type 
 */
typedef enum bcmbal_tm_sched_owner_type
{
    BCMBAL_TM_SCHED_OWNER_TYPE_UNDEFINED                                = 0,    /**< Undefined */
    BCMBAL_TM_SCHED_OWNER_TYPE_INTERFACE                                = 1,    /**< Interface */
    BCMBAL_TM_SCHED_OWNER_TYPE_SUB_TERM                                 = 2,    /**< Subscriber terminal */
    BCMBAL_TM_SCHED_OWNER_TYPE_AGG_PORT                                 = 3,    /**< TM scheduler is owned by aggregation port */
    BCMBAL_TM_SCHED_OWNER_TYPE_VIRTUAL                                  = 4,    /**< Other unspecified owner */
    BCMBAL_TM_SCHED_OWNER_TYPE__NUM_OF  /**< Number of enum entries, not an entry itself. */
} bcmbal_tm_sched_owner_type;

/** tm_sched_owner agg_port ID. 
 */
typedef enum bcmbal_tm_sched_owner_agg_port_id
{
    BCMBAL_TM_SCHED_OWNER_AGG_PORT_ID_NONE                              = 0,
    BCMBAL_TM_SCHED_OWNER_AGG_PORT_ID_INTF_ID                           = 0x0001,   /**< PON interface id */
    BCMBAL_TM_SCHED_OWNER_AGG_PORT_ID_SUB_TERM_ID                       = 0x0002,   /**< Subscriber terminal id */
    BCMBAL_TM_SCHED_OWNER_AGG_PORT_ID_AGG_PORT_ID                       = 0x0004,   /**< Aggregation port id */
    BCMBAL_TM_SCHED_OWNER_AGG_PORT_ID_ALL                               = 0x0007    /**< All fields */
} bcmbal_tm_sched_owner_agg_port_id;

/** tm_sched_parent ID. 
 */
typedef enum bcmbal_tm_sched_parent_id
{
    BCMBAL_TM_SCHED_PARENT_ID_NONE                                      = 0,
    BCMBAL_TM_SCHED_PARENT_ID_SCHED_ID                                  = 0x0001,   /**< Parent scheduler id */
    BCMBAL_TM_SCHED_PARENT_ID_PRIORITY                                  = 0x0002,   /**< Priority */
    BCMBAL_TM_SCHED_PARENT_ID_WEIGHT                                    = 0x0004,   /**< Weight */
    BCMBAL_TM_SCHED_PARENT_ID_ALL                                       = 0x0007    /**< All fields */
} bcmbal_tm_sched_parent_id;

/** Scheduler Type 
 */
typedef enum bcmbal_tm_sched_type
{
    BCMBAL_TM_SCHED_TYPE_WFQ                                            = 1,        /**< Weighted Fair Queue */
    BCMBAL_TM_SCHED_TYPE_SP                                             = 2,        /**< Strict Priority */
    BCMBAL_TM_SCHED_TYPE_SP_WFQ                                         = 3         /**< Hybrid SP + WFQ */
} bcmbal_tm_sched_type;

/** tm_shaping ID. 
 */
typedef enum bcmbal_tm_shaping_id
{
    BCMBAL_TM_SHAPING_ID_NONE                                           = 0,
    BCMBAL_TM_SHAPING_ID_CIR                                            = 0x0001,   /**< Committed Information Rate (kbps) */
    BCMBAL_TM_SHAPING_ID_PIR                                            = 0x0002,   /**< Peak Information Rate (kbps) */
    BCMBAL_TM_SHAPING_ID_BURST                                          = 0x0004,   /**< Max Burst Bytes at Peak Bit Rate */
    BCMBAL_TM_SHAPING_ID_ALL                                            = 0x0007    /**< All fields */
} bcmbal_tm_shaping_id;

/** Transceiver types 
 */
typedef enum bcmbal_trx_type
{
    BCMBAL_TRX_TYPE_GPON_SPS_43_48                                      = 0,        /**< gpon_sps_43_48. */
    BCMBAL_TRX_TYPE_GPON_SPS_SOG_4321                                   = 1,        /**< gpon_sps_sog_4321. */
    BCMBAL_TRX_TYPE_GPON_LTE_3680_M                                     = 2,        /**< gpon_lte_3680_m. */
    BCMBAL_TRX_TYPE_GPON_SOURCE_PHOTONICS                               = 3,        /**< gpon_source_photonics. */
    BCMBAL_TRX_TYPE_GPON_LTE_3680_P                                     = 4,        /**< gpon_lte_3680_p. */
    BCMBAL_TRX_TYPE_XGPON_LTH_7222_PC                                   = 5,        /**< xgpon_lth_7222_pc. */
    BCMBAL_TRX_TYPE_XGPON_LTH_7226_PC                                   = 6,        /**< xgpon_lth_7226_pc. */
    BCMBAL_TRX_TYPE_XGPON_LTH_5302_PC                                   = 7,        /**< xgpon_lth_5302_pc. */
    BCMBAL_TRX_TYPE_XGPON_LTH_7226_A_PC_PLUS                            = 8,        /**< xgpon_lth_7226_a_pc_plus. */
    BCMBAL_TRX_TYPE_XGPON_LTW_627_X_PC                                  = 9,        /**< xgpon_ltw_627_x_pc. */
    BCMBAL_TRX_TYPE_XGPON_XPP_XE_R_3_CDFB                               = 10,       /**< xgpon_xpp_xe_r_3_cdfb. */
    BCMBAL_TRX_TYPE__NUM_OF /**< Number of enum entries, not an entry itself. */
} bcmbal_trx_type;

#define bcmbal_action_id_none                                   BCMBAL_ACTION_ID_NONE
#define bcmbal_action_id_cmds_bitmask                           BCMBAL_ACTION_ID_CMDS_BITMASK
#define bcmbal_action_id_o_vid                                  BCMBAL_ACTION_ID_O_VID
#define bcmbal_action_id_o_pbits                                BCMBAL_ACTION_ID_O_PBITS
#define bcmbal_action_id_o_tpid                                 BCMBAL_ACTION_ID_O_TPID
#define bcmbal_action_id_i_vid                                  BCMBAL_ACTION_ID_I_VID
#define bcmbal_action_id_i_pbits                                BCMBAL_ACTION_ID_I_PBITS
#define bcmbal_action_id_i_tpid                                 BCMBAL_ACTION_ID_I_TPID
#define bcmbal_action_id_all                                    BCMBAL_ACTION_ID_ALL
#define bcmbal_classifier_id_none                               BCMBAL_CLASSIFIER_ID_NONE
#define bcmbal_classifier_id_o_tpid                             BCMBAL_CLASSIFIER_ID_O_TPID
#define bcmbal_classifier_id_o_vid                              BCMBAL_CLASSIFIER_ID_O_VID
#define bcmbal_classifier_id_i_tpid                             BCMBAL_CLASSIFIER_ID_I_TPID
#define bcmbal_classifier_id_i_vid                              BCMBAL_CLASSIFIER_ID_I_VID
#define bcmbal_classifier_id_o_pbits                            BCMBAL_CLASSIFIER_ID_O_PBITS
#define bcmbal_classifier_id_i_pbits                            BCMBAL_CLASSIFIER_ID_I_PBITS
#define bcmbal_classifier_id_ether_type                         BCMBAL_CLASSIFIER_ID_ETHER_TYPE
#define bcmbal_classifier_id_dst_mac                            BCMBAL_CLASSIFIER_ID_DST_MAC
#define bcmbal_classifier_id_src_mac                            BCMBAL_CLASSIFIER_ID_SRC_MAC
#define bcmbal_classifier_id_ip_proto                           BCMBAL_CLASSIFIER_ID_IP_PROTO
#define bcmbal_classifier_id_dst_ip                             BCMBAL_CLASSIFIER_ID_DST_IP
#define bcmbal_classifier_id_src_ip                             BCMBAL_CLASSIFIER_ID_SRC_IP
#define bcmbal_classifier_id_src_port                           BCMBAL_CLASSIFIER_ID_SRC_PORT
#define bcmbal_classifier_id_dst_port                           BCMBAL_CLASSIFIER_ID_DST_PORT
#define bcmbal_classifier_id_pkt_tag_type                       BCMBAL_CLASSIFIER_ID_PKT_TAG_TYPE
#define bcmbal_classifier_id_all                                BCMBAL_CLASSIFIER_ID_ALL
#define bcmbal_extended_epon_dba_id_none                        BCMBAL_EXTENDED_EPON_DBA_ID_NONE
#define bcmbal_extended_epon_dba_id_polling_interval_us         BCMBAL_EXTENDED_EPON_DBA_ID_POLLING_INTERVAL_US
#define bcmbal_extended_epon_dba_id_grant_threshold_tq          BCMBAL_EXTENDED_EPON_DBA_ID_GRANT_THRESHOLD_TQ
#define bcmbal_extended_epon_dba_id_cir_priority                BCMBAL_EXTENDED_EPON_DBA_ID_CIR_PRIORITY
#define bcmbal_extended_epon_dba_id_cir_weight_tq               BCMBAL_EXTENDED_EPON_DBA_ID_CIR_WEIGHT_TQ
#define bcmbal_extended_epon_dba_id_pir_priority                BCMBAL_EXTENDED_EPON_DBA_ID_PIR_PRIORITY
#define bcmbal_extended_epon_dba_id_pir_weight_tq               BCMBAL_EXTENDED_EPON_DBA_ID_PIR_WEIGHT_TQ
#define bcmbal_extended_epon_dba_id_tdm_grant_size_tq           BCMBAL_EXTENDED_EPON_DBA_ID_TDM_GRANT_SIZE_TQ
#define bcmbal_extended_epon_dba_id_tdm_grant_interval_us       BCMBAL_EXTENDED_EPON_DBA_ID_TDM_GRANT_INTERVAL_US
#define bcmbal_extended_epon_dba_id_all                         BCMBAL_EXTENDED_EPON_DBA_ID_ALL
#define bcmbal_extended_itu_dba_id_none                         BCMBAL_EXTENDED_ITU_DBA_ID_NONE
#define bcmbal_extended_itu_dba_id_extra_bw_elig                BCMBAL_EXTENDED_ITU_DBA_ID_EXTRA_BW_ELIG
#define bcmbal_extended_itu_dba_id_nrt_cbr                      BCMBAL_EXTENDED_ITU_DBA_ID_NRT_CBR
#define bcmbal_extended_itu_dba_id_rt_cbr                       BCMBAL_EXTENDED_ITU_DBA_ID_RT_CBR
#define bcmbal_extended_itu_dba_id_rt_profile                   BCMBAL_EXTENDED_ITU_DBA_ID_RT_PROFILE
#define bcmbal_extended_itu_dba_id_nrt_profile                  BCMBAL_EXTENDED_ITU_DBA_ID_NRT_PROFILE
#define bcmbal_extended_itu_dba_id_alloc_type                   BCMBAL_EXTENDED_ITU_DBA_ID_ALLOC_TYPE
#define bcmbal_extended_itu_dba_id_all                          BCMBAL_EXTENDED_ITU_DBA_ID_ALL
#define bcmbal_interface_ngpon_2_id_none                        BCMBAL_INTERFACE_NGPON_2_ID_NONE
#define bcmbal_interface_ngpon_2_id_sys_id                      BCMBAL_INTERFACE_NGPON_2_ID_SYS_ID
#define bcmbal_interface_ngpon_2_id_operation_control           BCMBAL_INTERFACE_NGPON_2_ID_OPERATION_CONTROL
#define bcmbal_interface_ngpon_2_id_tol                         BCMBAL_INTERFACE_NGPON_2_ID_TOL
#define bcmbal_interface_ngpon_2_id_all                         BCMBAL_INTERFACE_NGPON_2_ID_ALL
#define bcmbal_operation_control_id_none                        BCMBAL_OPERATION_CONTROL_ID_NONE
#define bcmbal_operation_control_id_re                          BCMBAL_OPERATION_CONTROL_ID_RE
#define bcmbal_operation_control_id_odn_class                   BCMBAL_OPERATION_CONTROL_ID_ODN_CLASS
#define bcmbal_operation_control_id_ds_fec_mode                 BCMBAL_OPERATION_CONTROL_ID_DS_FEC_MODE
#define bcmbal_operation_control_id_protocol                    BCMBAL_OPERATION_CONTROL_ID_PROTOCOL
#define bcmbal_operation_control_id_ds_link_type                BCMBAL_OPERATION_CONTROL_ID_DS_LINK_TYPE
#define bcmbal_operation_control_id_pon_id                      BCMBAL_OPERATION_CONTROL_ID_PON_ID
#define bcmbal_operation_control_id_c                           BCMBAL_OPERATION_CONTROL_ID_C
#define bcmbal_operation_control_id_all                         BCMBAL_OPERATION_CONTROL_ID_ALL
#define bcmbal_sla_id_none                                      BCMBAL_SLA_ID_NONE
#define bcmbal_sla_id_min_rate                                  BCMBAL_SLA_ID_MIN_RATE
#define bcmbal_sla_id_max_rate                                  BCMBAL_SLA_ID_MAX_RATE
#define bcmbal_sla_id_all                                       BCMBAL_SLA_ID_ALL
#define bcmbal_system_profile_id_none                           BCMBAL_SYSTEM_PROFILE_ID_NONE
#define bcmbal_system_profile_id_version                        BCMBAL_SYSTEM_PROFILE_ID_VERSION
#define bcmbal_system_profile_id_channel_spacing                BCMBAL_SYSTEM_PROFILE_ID_CHANNEL_SPACING
#define bcmbal_system_profile_id_us_operating_wavelength_bands  BCMBAL_SYSTEM_PROFILE_ID_US_OPERATING_WAVELENGTH_BANDS
#define bcmbal_system_profile_id_us_mse                         BCMBAL_SYSTEM_PROFILE_ID_US_MSE
#define bcmbal_system_profile_id_loose_calibration_bound        BCMBAL_SYSTEM_PROFILE_ID_LOOSE_CALIBRATION_BOUND
#define bcmbal_system_profile_id_fsr                            BCMBAL_SYSTEM_PROFILE_ID_FSR
#define bcmbal_system_profile_id_twdm_channel_count             BCMBAL_SYSTEM_PROFILE_ID_TWDM_CHANNEL_COUNT
#define bcmbal_system_profile_id_all                            BCMBAL_SYSTEM_PROFILE_ID_ALL
#define bcmbal_tm_sched_owner_agg_port_id_none                  BCMBAL_TM_SCHED_OWNER_AGG_PORT_ID_NONE
#define bcmbal_tm_sched_owner_agg_port_id_intf_id               BCMBAL_TM_SCHED_OWNER_AGG_PORT_ID_INTF_ID
#define bcmbal_tm_sched_owner_agg_port_id_sub_term_id           BCMBAL_TM_SCHED_OWNER_AGG_PORT_ID_SUB_TERM_ID
#define bcmbal_tm_sched_owner_agg_port_id_agg_port_id           BCMBAL_TM_SCHED_OWNER_AGG_PORT_ID_AGG_PORT_ID
#define bcmbal_tm_sched_owner_agg_port_id_all                   BCMBAL_TM_SCHED_OWNER_AGG_PORT_ID_ALL
#define bcmbal_tm_sched_parent_id_none                          BCMBAL_TM_SCHED_PARENT_ID_NONE
#define bcmbal_tm_sched_parent_id_sched_id                      BCMBAL_TM_SCHED_PARENT_ID_SCHED_ID
#define bcmbal_tm_sched_parent_id_priority                      BCMBAL_TM_SCHED_PARENT_ID_PRIORITY
#define bcmbal_tm_sched_parent_id_weight                        BCMBAL_TM_SCHED_PARENT_ID_WEIGHT
#define bcmbal_tm_sched_parent_id_all                           BCMBAL_TM_SCHED_PARENT_ID_ALL
#define bcmbal_tm_shaping_id_none                               BCMBAL_TM_SHAPING_ID_NONE
#define bcmbal_tm_shaping_id_cir                                BCMBAL_TM_SHAPING_ID_CIR
#define bcmbal_tm_shaping_id_pir                                BCMBAL_TM_SHAPING_ID_PIR
#define bcmbal_tm_shaping_id_burst                              BCMBAL_TM_SHAPING_ID_BURST
#define bcmbal_tm_shaping_id_all                                BCMBAL_TM_SHAPING_ID_ALL

/** action. 
 */
typedef struct bcmbal_action
{
    bcmbal_action_id presence_mask;     /**< Presence Mask. */
    bcmbal_action_cmd_id cmds_bitmask;  /**< Commands bitmask. */
    uint16_t o_vid;                     /**< Outer vid. */
    uint8_t o_pbits;                    /**< Outer pbits. */
    uint16_t o_tpid;                    /**< Outer tpid. */
    uint16_t i_vid;                     /**< Inner vid. */
    uint8_t i_pbits;                    /**< Inner pbits. */
    uint16_t i_tpid;                    /**< Inner tpid. */
} bcmbal_action;

/** Variable-length list of aggregation_port_id. 
 */
typedef struct bcmbal_aggregation_port_id_list_u8
{
    uint8_t len;                        /**< List length. */
    bcmbal_aggregation_port_id *val;    /**< List contents. */
} bcmbal_aggregation_port_id_list_u8;

/** DS frequency offset. 
 */
typedef struct bcmbal_ds_frequency_offset
{
    bcmbal_sign sign;   /**< Sign. */
    uint8_t value;      /**< Value. */
} bcmbal_ds_frequency_offset;

/** Channel Profile. 
 */
typedef struct bcmbal_channel_profile
{
    uint8_t version;        /**< Channel profile version . */
    uint8_t channel_index;  /**< Channel profile index . */
    bcmbal_ds_frequency_offset ds_frequency_offset; /**< The difference between the actual OLT CT Tx frequency and the nominal central frequency for the given DWLCH ID, expressed in units of 0.1GHz */
    uint8_t channel_partition;                      /**< channel partition. */
    uint8_t uwlch_id;       /**<  The assigned upstream wavelength channel ID */
    uint32_t us_frequency;  /**< The nominal central frequency of the upstream wavelength channel or a root frequency of the cyclic set of central frequencies forming an upstream wavelength channel, indicates the value in units of 0.1 GHz. */
    bcmbal_upstream_line_rate_capabilities us_rate; /**<  US rate. */
    uint8_t default_onu_attenuation;                /**<  The default ONU attenuation level in steps of 3dB  */
    uint8_t response_threshold;                     /**< Threshold represent the maximum number of Ploams the ONU can transmit at non-zero attenuation level while attempting to establish communication with OLT CT */
    bcmbal_link_type us_link_type;                  /**< US link type. */
    bcmos_bool is_valid;    /**< Is Valid. */
} bcmbal_channel_profile;

/** Fixed-Length list: 8x channel_profile. 
 */
typedef struct bcmbal_arr_channel_profile_8
{
    bcmbal_channel_profile arr[8];  /**< Array. */
} bcmbal_arr_channel_profile_8;

/** ber monitor parameters. 
 */
typedef struct bcmbal_ber_monitor_params
{
    uint8_t sf_threshold;   /**< Signal fail alarm is raised when BER raises to 10^-x, where x is this number. */
    uint8_t sd_threshold;   /**< Signal degrade alarm is raised when BER raises to 10^-x, where x is this number. */
} bcmbal_ber_monitor_params;

/** classifier. 
 */
typedef struct bcmbal_classifier
{
    bcmbal_classifier_id presence_mask; /**< Presence Mask. */
    uint16_t o_tpid;                    /**< Outer TPID of the packet to be classified */
    uint16_t o_vid;                     /**< Outer VID of the packet to be classified */
    uint16_t i_tpid;                    /**< Inner TPID of the packet to be classified */
    uint16_t i_vid;                     /**< Inner VID of the packet to be classified */
    uint8_t o_pbits;                    /**< Outer PBITS of the packet to be classified */
    uint8_t i_pbits;                    /**< Inner PBITS of the packet to be classified */
    uint16_t ether_type;                /**< Ethertype of the packet to be classified */
    bcmos_mac_address dst_mac;          /**< Destination MAC address of the packet to be classified */
    bcmos_mac_address src_mac;          /**< Source MAC address of the packet to be classified */
    uint8_t ip_proto;                   /**< IP protocol of the packet to be classified */
    bcmos_ipv4_address dst_ip;          /**< Destination IP address of the packet to be classified */
    bcmos_ipv4_address src_ip;          /**< Source IP address of the packet to be classified */
    uint16_t src_port;                  /**< Source port of the packet to be classified */
    uint16_t dst_port;                  /**< Destination port of the packet to be classified */
    bcmbal_pkt_tag_type pkt_tag_type;   /**< The tag type of the ingress packets */
} bcmbal_classifier;

/** Packet destination. 
 */
typedef struct bcmbal_dest
{
    bcmbal_dest_type type;                      /**< packet destination. */
    union
    {
        struct
        {
            bcmbal_intf_id intf_id;             /**< Interface ID. */
        } nni;

        struct
        {
            bcmbal_sub_id sub_term_id;          /**< Subscriber terminal ID. */
            bcmbal_intf_id intf_id;             /**< Interface ID. */
        } sub_term;

        struct
        {
            bcmbal_service_port_id svc_port_id; /**< Service Port ID. */
            bcmbal_intf_id intf_id;             /**< Interface ID. */
        } svc_port;

        struct
        {
            bcmbal_sub_id sub_term_id;          /**< Subscriber terminal ID. */
            bcmbal_intf_id intf_id;             /**< Interface ID. */
        } itu_omci_channel;

        struct
        {
            bcmos_mac_address mac_address;      /**< MAC address for this link. */
            bcmbal_intf_id intf_id;             /**< Interface ID. */
        } ieee_oam_channel;
    } u;
} bcmbal_dest;

/** extended epon dba. 
 */
typedef struct bcmbal_extended_epon_dba
{
    bcmbal_extended_epon_dba_id presence_mask;  /**< Presence Mask. */
    bcmbal_polling_interval polling_interval_us;    /**< The amount of time between when this LLID last reported upstream data and when it will next be polled (approximate: rounded down to the nearest 65.536 us). */
    bcmbal_time_quanta grant_threshold_tq;          /**< Used to determine the maximum grant size that will be issued to this LLID (in TQ; rounded up to the nearest 128TQ; 1TQ = 16ns = 2Bytes@1G or 20Bytes@10G). */
    uint8_t cir_priority;                   /**< The priority of the CIR scheduling element. */
    bcmbal_time_quanta cir_weight_tq;       /**< The weight of the CIR scheduler (in TQ rounded up to nearest 128). Must be greater than or equal to Grant Threshold. */
    uint8_t pir_priority;                   /**< The priority of the PIR scheduling element. */
    bcmbal_time_quanta pir_weight_tq;       /**< The weight of the PIR scheduler (in TQ rounded up to nearest 128). Must be greater than or equal to Grant Threshold. */
    bcmbal_time_quanta tdm_grant_size_tq;   /**< Size of TDM grants (in TQ). */
    uint32_t tdm_grant_interval_us;         /**< Interval between TDM grants (in us). */
} bcmbal_extended_epon_dba;

/** Extended itu dba parameters 
 */
typedef struct bcmbal_extended_itu_dba
{
    bcmbal_extended_itu_dba_id presence_mask;   /**< Presence Mask. */
    bcmbal_extra_bw_eligibility_type extra_bw_elig; /**< Extra BW eligibility type */
    uint32_t nrt_cbr;               /**< NRT CBR in Bytes per second */
    uint32_t rt_cbr;                /**< RT_CBR in Bytes per second */
    uint8_t rt_profile;             /**< RT Profile */
    uint8_t nrt_profile;            /**< NRT Profile */
    bcmbal_alloc_type alloc_type;   /**< alloc_type. */
} bcmbal_extended_itu_dba;

/** Variable-length list of flow_id. 
 */
typedef struct bcmbal_flow_id_list_u32
{
    uint32_t len;           /**< List length. */
    bcmbal_flow_id *val;    /**< List contents. */
} bcmbal_flow_id_list_u32;

/** Queue Reference 
 */
typedef struct bcmbal_tm_queue_ref
{
    bcmbal_tm_sched_id sched_id;    /**< Scheduler (tm_sched) ID */
    bcmbal_tm_queue_id queue_id;    /**< Queue ID */
} bcmbal_tm_queue_ref;

/** Group Member Info. 
 */
typedef struct bcmbal_group_member_info
{
    bcmbal_intf_id intf_id;             /**< Access interface id for this member */
    bcmbal_intf_type_ds intf_type;      /**< Type of interface. Usually PON, or a specific data path for interfaces with multiple downstream channels. */
    bcmbal_service_port_id svc_port_id; /**< GPON/XGPON - The multicast "GEM" for this member. EPON - The multicast link identifier. */
    bcmbal_tm_queue_ref queue;          /**< Egress queue */
} bcmbal_group_member_info;

/** Variable-length list of group_member_info. 
 */
typedef struct bcmbal_group_member_info_list_u16
{
    uint16_t len;                   /**< List length. */
    bcmbal_group_member_info *val;  /**< List contents. */
} bcmbal_group_member_info_list_u16;

/** Identifies the TWDM channel termination within a certain domain 
 */
typedef struct bcmbal_pon_id
{
    uint32_t administrative_label;  /**< MSB 28 bit of the PON ID */
    uint8_t dwlch_id;               /**< LSB 4 bits of the PON ID */
} bcmbal_pon_id;

/** Operation control. 
 */
typedef struct bcmbal_operation_control
{
    bcmbal_operation_control_id presence_mask;  /**< Presence Mask. */
    uint8_t re;                     /**<  Indicates whether the Transmit Optical Level (TOL) contains the launch power of the OTL (RE=0) or of a reach extender (RE=1) */
    bcmbal_odn_class odn_class;     /**<  Identifies the nominal optical parameters of the transceiver according to the ODN Optical Path Loss (OPL) */
    bcmbal_control ds_fec_mode;     /**<  Enable/Disable the downstream FEC. Default is Enable. Attribute can be set only when PON NI state is Inactive */
    bcmbal_tc_protocol protocol;    /**< When system mode is NGPON2, this parameter Indicate the TC layer protocol: ITU-T G.989.3 or ITU-T G.987.3 */
    bcmbal_link_type ds_link_type;  /**<  Optical link type (Unspecified, A, B, Both) */
    bcmbal_pon_id pon_id;           /**<  Identifies the TWDM channel termination within a certain domain  */
    uint8_t c;                      /**< Transmit optical level (TOL) reference point indicator: S/R-CG or S/R-CP  */
} bcmbal_operation_control;

/** interface ngpon2 related attributes 
 */
typedef struct bcmbal_interface_ngpon_2
{
    bcmbal_interface_ngpon_2_id presence_mask;  /**< Presence Mask. */
    uint32_t sys_id;    /**< 20-bit identifier of the NGPON2 system, should match a key of exysting sys_channel_profile object */
    bcmbal_operation_control operation_control; /**< operation_control. */
    uint16_t tol;   /**< Transmit Optical Level. An indication of the current OLT CT transceiver channel launch power into the ODN */
} bcmbal_interface_ngpon_2;

/** Password. 
 */
typedef struct bcmbal_password
{
    uint8_t arr[10];    /**< Array. */
} bcmbal_password;

/** pon_distance. 
 */
typedef struct bcmbal_pon_distance
{
    uint32_t max_log_distance;  /**< Max logical distance of a subscriber terminal on the interface in km. */
    uint32_t max_diff_reach;    /**< Max distance between the closest and farthest subscriber terminal in km. */
} bcmbal_pon_distance;

/** Registration id. 
 */
typedef struct bcmbal_registration_id
{
    uint8_t arr[36];    /**< ONU registration ID */
} bcmbal_registration_id;

/** Serial number. 
 */
typedef struct bcmbal_serial_number
{
    uint8_t vendor_id[4];       /**< vendor id. */
    uint8_t vendor_specific[4]; /**< vendor specific. */
} bcmbal_serial_number;

/** Variable-length list of service_port_id. 
 */
typedef struct bcmbal_service_port_id_list_u8
{
    uint8_t len;                    /**< List length. */
    bcmbal_service_port_id *val;    /**< List contents. */
} bcmbal_service_port_id_list_u8;

/** SLA. 
 */
typedef struct bcmbal_sla
{
    bcmbal_sla_id presence_mask;    /**< Presence Mask. */
    uint32_t min_rate;              /**< The minimal rate for this flow, in kilobits per second (optional) */
    uint32_t max_rate;              /**< The maximum rate for this flow, in kilobits per second (optional) */
} bcmbal_sla;

/** Variable-length list of sub_id. 
 */
typedef struct bcmbal_sub_id_list_u16
{
    uint16_t len;       /**< List length. */
    bcmbal_sub_id *val; /**< List contents. */
} bcmbal_sub_id_list_u16;

/** Subscriber Terminal Alarms. Superset of ITU GPON / XGPON alarms. 
 */
typedef struct bcmbal_subscriber_terminal_alarms
{
    bcmbal_alarm_status los;            /**< ITU XGPON or GPON LOS Alarm. */
    bcmbal_alarm_status lob;            /**< ITU XGPON LOB Alarm. */
    bcmbal_alarm_status lopc_miss;      /**< ITU XGPON LOPC Miss Alarm. */
    bcmbal_alarm_status lopc_mic_error; /**< ITU XGPON LOPC Mic Error Alarm. */
    bcmbal_alarm_status lof;            /**< ITU GPON LOF Alarm. */
    bcmbal_alarm_status loam;           /**< ITU GPON LOAM Alarm. */
} bcmbal_subscriber_terminal_alarms;

/** Software version information 
 */
typedef struct bcmbal_sw_version
{
    bcmbal_version_type version_type;   /**< Release or debug version */
    uint8_t major_rev;                  /**< Major rev */
    uint8_t minor_rev;                  /**< Minor rev */
    uint8_t release_rev;                /**< Release number */
    uint16_t om_version;                /**< BAL API Object Model version */
    uint32_t dev_point;                 /**< Development point - only valid for development versions, 0 otherwise */
} bcmbal_sw_version;

/** System profile. 
 */
typedef struct bcmbal_system_profile
{
    bcmbal_system_profile_id presence_mask; /**< Presence Mask. */
    uint8_t version;                        /**< System profile version. */
    uint8_t channel_spacing;                /**< An integer indicating the channel spacing in units of 1GHz  */
    bcmbal_us_operating_wavelength_bands us_operating_wavelength_bands; /**< US  operating wavelength bands. */
    uint8_t us_mse; /**<  Upstream Maximum Spectral Excursion (MSE) represented as an unsigned integer indicating the value in units of 1GHz */
    bcmbal_calibration_record loose_calibration_bound;  /**< Spectral excursion bound below which a TWDM ONU can be considered as loosely calibrated  */
    uint16_t fsr;               /**<  If a cyclic WM is used in the upstream, Free Spectral Range indicates the value in units of 0.1 GHz */
    uint8_t twdm_channel_count; /**<  The number of Channel_Profile PLOAM messages with distinct Channel Profile indices that an ONU can expect to receive while listening to this downstream wavelength channel */
} bcmbal_system_profile;

/** Random Early Discard Configuration 
 */
typedef struct bcmbal_tm_red
{
    bcmbal_percent min_threshold;   /**< Min threshold in percent of max queue size */
    bcmbal_percent max_threshold;   /**< Max threshold in percent of max queue size */
    bcmbal_percent max_probability; /**< Discard probability for occupancy between min_threshold and max_threshold */
} bcmbal_tm_red;

/** Queue Buffer Admission Control 
 */
typedef struct bcmbal_tm_bac
{
    bcmbal_tm_bac_type type;        /**< Buffer Admission Control Type */
    union
    {
        struct
        {
            uint32_t max_size;      /**< max number of packets in the queue */
        } taildrop;

        struct
        {
            bcmbal_tm_red red;      /**< Random Early Discard configuration */
        } red;

        struct
        {
            bcmbal_tm_red green;    /**< Green Random Early Discard Configuration */
            bcmbal_tm_red yellow;   /**< Yellow Random Early Discard Configuration */
            bcmbal_tm_red red;      /**< Red Random Early Discard Configuration */
        } wred;
    } u;
} bcmbal_tm_bac;

/** Variable-length list of tm_queue_id. 
 */
typedef struct bcmbal_tm_queue_id_list_u8
{
    uint8_t len;                /**< List length. */
    bcmbal_tm_queue_id *val;    /**< List contents. */
} bcmbal_tm_queue_id_list_u8;

/** Variable-length list of tm_sched_id. 
 */
typedef struct bcmbal_tm_sched_id_list_u8
{
    uint8_t len;                /**< List length. */
    bcmbal_tm_sched_id *val;    /**< List contents. */
} bcmbal_tm_sched_id_list_u8;

/** TM Scheduler Owner 
 */
typedef struct bcmbal_tm_sched_owner
{
    bcmbal_tm_sched_owner_type type;    /**< Owner type */
    union
    {
        struct
        {
            bcmbal_intf_type intf_type; /**< Interface Type */
            bcmbal_intf_id intf_id;     /**< Interface ID */
        } interface;

        struct
        {
            bcmbal_intf_id intf_id;     /**< PON interface id */
            bcmbal_sub_id sub_term_id;  /**< Subscriber terminal ID */
        } sub_term;

        struct
        {
            bcmbal_tm_sched_owner_agg_port_id presence_mask;    /**< Presence Mask. */
            bcmbal_intf_id intf_id;                 /**< PON interface id */
            bcmbal_sub_id sub_term_id;              /**< Subscriber terminal id */
            bcmbal_aggregation_port_id agg_port_id; /**< Aggregation port id */
        } agg_port;

        struct
        {
            uint32_t idx;   /**< Owner index */
        } virtual;
    } u;
} bcmbal_tm_sched_owner;

/** Scheduling Parent Connect Point 
 */
typedef struct bcmbal_tm_sched_parent
{
    bcmbal_tm_sched_parent_id presence_mask;    /**< Presence Mask. */
    bcmbal_tm_sched_id sched_id;                /**< Parent scheduler id */
    bcmbal_tm_priority priority;                /**< Priority */
    bcmbal_tm_weight weight;                    /**< Weight */
} bcmbal_tm_sched_parent;

/** Shaping Parameters 
 */
typedef struct bcmbal_tm_shaping
{
    bcmbal_tm_shaping_id presence_mask; /**< Presence Mask. */
    uint32_t cir;                       /**< Committed Information Rate (kbps) */
    uint32_t pir;                       /**< Peak Information Rate (kbps) */
    uint32_t burst;                     /**< Max Burst Bytes at Peak Bit Rate */
} bcmbal_tm_shaping;

/** BAL topology. 
 */
typedef struct bcmbal_topology
{
    uint32_t num_of_nni_ports;              /**< The number of nni ports for the access_terminal */
    uint32_t num_of_pon_ports;              /**< The number of pon ports for the access_terminal */
    uint32_t num_of_mac_devs;               /**< The number of mac devices associated with this access_terminal */
    uint32_t num_of_pons_per_mac_dev;       /**< The number of pon ports per mac device in this access_terminal */
    bcmbal_pon_family pon_family;           /**< The PON family for the access_terminal */
    bcmbal_pon_sub_family pon_sub_family;   /**< The PON sub-family for the access_terminal */
} bcmbal_topology;

/** Variable-length list of U8. 
 */
typedef struct bcmbal_u8_list_u32_max_2048
{
    uint32_t len;   /**< List length. */
    uint8_t *val;   /**< List contents. */
} bcmbal_u8_list_u32_max_2048;

/** Structure definition for the "key" group of the "access_terminal" object. 
 */
typedef struct bcmbal_access_terminal_key
{
    bcmbal_access_id access_term_id;    /**< Reserved (set to 0) */
} bcmbal_access_terminal_key;

/** Structure definition for the "cfg" group of the "access_terminal" object. 
 */
typedef struct bcmbal_access_terminal_cfg_data
{
    bcmbal_state admin_state;       /**< Administrative state */
    bcmbal_status oper_status;      /**< Operational status */
    bcmbal_iwf_mode iwf_mode;       /**< The interworking mode */
    bcmbal_topology topology;       /**< Topology. */
    bcmbal_sw_version sw_version;   /**< Software version information */
    uint32_t conn_id;               /**< Connection id uniquely identifying BAL core */
} bcmbal_access_terminal_cfg_data;

/** Transport message definition for "cfg" group of "access_terminal" object. 
 */
typedef struct bcmbal_access_terminal_cfg
{
    bcmbal_cfg hdr;                 /**< Transport header. */
    bcmbal_access_terminal_key key; /**< Object key. */
    bcmbal_access_terminal_cfg_data data;   /**< All properties that must be set by the user. */
} bcmbal_access_terminal_cfg;

/** Structure definition for the "oper_status_change" group of the 
 * "access_terminal" object. 
 *
 * An indication of a change of operational status 
 */
typedef struct bcmbal_access_terminal_oper_status_change_data
{
    bcmbal_status new_oper_status;  /**< The current oper status */
    bcmbal_status old_oper_status;  /**< The previous oper status before this indication was reported */
    bcmbal_state admin_state;       /**< The current admin status */
} bcmbal_access_terminal_oper_status_change_data;

/** Transport message definition for "oper_status_change" group of 
 * "access_terminal" object. 
 */
typedef struct bcmbal_access_terminal_oper_status_change
{
    bcmbal_auto hdr;                /**< Transport header. */
    bcmbal_access_terminal_key key; /**< Object key. */
    bcmbal_access_terminal_oper_status_change_data data;    /**< All properties that must be set by the user. */
} bcmbal_access_terminal_oper_status_change;

/** Transport message definition for "processing_error" group of 
 * "access_terminal" object. 
 */
typedef struct bcmbal_access_terminal_processing_error
{
    bcmbal_auto hdr;                /**< Transport header. */
    bcmbal_access_terminal_key key; /**< Object key. */
} bcmbal_access_terminal_processing_error;

/** Structure definition for the "key" group of the "flow" object. 
 */
typedef struct bcmbal_flow_key
{
    bcmbal_flow_id flow_id;     /**< The ID of the flow object instance being referenced */
    bcmbal_flow_type flow_type; /**< The type of the flow, Upstream, Downstream, Broadcast or Multicast */
} bcmbal_flow_key;

/** Structure definition for the "cfg" group of the "flow" object. 
 */
typedef struct bcmbal_flow_cfg_data
{
    bcmbal_state admin_state;           /**< Administrative state */
    bcmbal_status oper_status;          /**< Operational status */
    bcmbal_intf_id access_int_id;       /**< The ID of the subscriber side interface; i.e. PON */
    bcmbal_intf_id network_int_id;      /**< The ID of the network side interface; i.e. NNI */
    bcmbal_sub_id sub_term_id;          /**< The ID of the subsccriber terminal device */
    bcmbal_service_port_id svc_port_id; /**< The ID of the service port (for GPON/XGPON - GEM ID; for EPON - abstract link identifier) */
    bcmos_bool resolve_mac;             /**< A flag indicating if the MAC address table should be used in DS service port resolution */
    bcmbal_classifier classifier;       /**< The classifier for this flow */
    bcmbal_action action;               /**< The action associated with the flow */
    bcmbal_cookie cookie;               /**< Application cookie */
    uint16_t priority;                  /**< Priority for this flow in case of multiple match. */
    bcmbal_group_id group_id;           /**< RW - The multicast group associated with this flow, valid for type MULTICAST only */
    bcmbal_tm_queue_ref queue;          /**< Egress queue */
    bcmbal_tm_sched_id dba_tm_sched_id; /**< A reference to an us tm_sched used for us dba for this flow */
} bcmbal_flow_cfg_data;

/** Transport message definition for "cfg" group of "flow" object. 
 */
typedef struct bcmbal_flow_cfg
{
    bcmbal_cfg hdr;             /**< Transport header. */
    bcmbal_flow_key key;        /**< Object key. */
    bcmbal_flow_cfg_data data;  /**< All properties that must be set by the user. */
} bcmbal_flow_cfg;

/** Structure definition for the "oper_status_change" group of the "flow" 
 * object. 
 *
 * An indication of a change of operational status 
 */
typedef struct bcmbal_flow_oper_status_change_data
{
    bcmbal_status new_oper_status;      /**< The current oper status */
    bcmbal_status old_oper_status;      /**< The previous oper status before this indication was reported */
    bcmbal_state admin_state;           /**< The current admin status */
    uint16_t svc_port_id;               /**< The ID of the service port (for GPON/XGPON - GEM ID) */
    bcmbal_tm_sched_id dba_tm_sched_id; /**< A reference to an us tm_sched used for us dba for this flow */
    bcmbal_cookie cookie;               /**< Opaque application cookie associated with the flow (not interpreted by Maple) */
} bcmbal_flow_oper_status_change_data;

/** Transport message definition for "oper_status_change" group of "flow" 
 * object. 
 */
typedef struct bcmbal_flow_oper_status_change
{
    bcmbal_auto hdr;        /**< Transport header. */
    bcmbal_flow_key key;    /**< Object key. */
    bcmbal_flow_oper_status_change_data data;   /**< All properties that must be set by the user. */
} bcmbal_flow_oper_status_change;

/** Transport message definition for "processing_error" group of "flow" object. 
 */
typedef struct bcmbal_flow_processing_error
{
    bcmbal_auto hdr;        /**< Transport header. */
    bcmbal_flow_key key;    /**< Object key. */
} bcmbal_flow_processing_error;

/** Structure definition for the "key" group of the "group" object. 
 */
typedef struct bcmbal_group_key
{
    bcmbal_group_id group_id;   /**< The ID of the group object instance being referenced */
} bcmbal_group_key;

/** Structure definition for the "cfg" group of the "group" object. 
 */
typedef struct bcmbal_group_cfg_data
{
    bcmbal_group_member_cmd members_cmd;    /**< Membership operation commands. */
    bcmbal_group_member_info_list_u16 members;  /**< The list of members associated with this group */
    bcmbal_cookie cookie;                       /**< Application cookie */
    bcmbal_flow_id_list_u32 flows;              /**< List of flows associated with this group */
    bcmbal_group_type type;                     /**< type of the group. */
} bcmbal_group_cfg_data;

/** Transport message definition for "cfg" group of "group" object. 
 */
typedef struct bcmbal_group_cfg
{
    bcmbal_cfg hdr;             /**< Transport header. */
    bcmbal_group_key key;       /**< Object key. */
    bcmbal_group_cfg_data data; /**< All properties that must be set by the user. */
} bcmbal_group_cfg;

/** Structure definition for the "key" group of the "interface" object. 
 */
typedef struct bcmbal_interface_key
{
    bcmbal_intf_id intf_id;     /**< intf_id. */
    bcmbal_intf_type intf_type; /**< intf_type. */
} bcmbal_interface_key;

/** Structure definition for the "cfg" group of the "interface" object. 
 */
typedef struct bcmbal_interface_cfg_data
{
    bcmbal_state admin_state;   /**< Administrative state */
    bcmbal_status oper_status;  /**< Operational status */
    bcmbal_aggregation_port_id min_data_agg_port_id;    /**< The minimum agg_port_id that is allowed on a PON interface */
    bcmbal_service_port_id min_data_svc_port_id;        /**< The minimum svc_port_id that is allowed on a PON interface */
    bcmbal_trx_type transceiver_type;                   /**< The transceiver type used on an interface. N/A for EPON. */
    uint16_t mtu;               /**< The MTU for an interface */
    bcmbal_tm_sched_id ds_tm;   /**< Downstream scheduler and shaper */
    bcmbal_tm_sched_id us_tm;   /**< Upstream scheduler and shaper */
    bcmbal_sub_id_list_u16 sub_term_id_list;    /**< A list of subscriber terminal ids configured on this interface */
    bcmbal_pon_distance pon_distance;           /**< pon inetrface distance parameters */
    bcmbal_ber_monitor_params ber_monitor;      /**< BER monitor process configuration */
    uint32_t us_bandwidth_limit;                /**< Upstream bandwidth limit in bytes/second */
    bcmbal_control ds_fec;                      /**< enable/disable  ds fec (gpon only) */
    bcmbal_interface_ngpon_2 ngpon_2;           /**< ngpon_2 attributes of the interface */
} bcmbal_interface_cfg_data;

/** Transport message definition for "cfg" group of "interface" object. 
 */
typedef struct bcmbal_interface_cfg
{
    bcmbal_cfg hdr;                 /**< Transport header. */
    bcmbal_interface_key key;       /**< Object key. */
    bcmbal_interface_cfg_data data; /**< All properties that must be set by the user. */
} bcmbal_interface_cfg;

/** Structure definition for the "stat" group of the "interface" object. 
 */
typedef struct bcmbal_interface_stat_data
{
    uint64_t rx_bytes;              /**< RFC 2233 */
    uint64_t rx_packets;            /**< RFC 1213 ucast + none-ucast */
    uint64_t rx_data_bytes;         /**< IEEE only: received bytes excluding MPCP/OAM */
    uint64_t rx_ucast_packets;      /**< RFC 2233 */
    uint64_t rx_mcast_packets;      /**< RFC 2233 */
    uint64_t rx_bcast_packets;      /**< RFC 2233 */
    uint64_t rx_64_packets;         /**< IEEE only: 64 byte packets received, excluding reports */
    uint64_t rx_65_127_packets;     /**< IEEE only: 65-127 byte packets received */
    uint64_t rx_128_255_packets;    /**< IEEE only: 128-255 byte packets received */
    uint64_t rx_256_511_packets;    /**< IEEE only: 256-511 byte packets received */
    uint64_t rx_512_1023_packets;   /**< IEEE only: 512-1023 byte packets received */
    uint64_t rx_1024_1518_packets;  /**< IEEE only: 1024-1518 byte packets received */
    uint64_t rx_1519_2047_packets;  /**< IEEE only: 1519-2047 byte packets received */
    uint64_t rx_2048_4095_packets;  /**< IEEE only: 2048-4095 byte packets received */
    uint64_t rx_4096_9216_packets;  /**< IEEE only: 4096-9216 byte packets received */
    uint64_t rx_9217_16383_packets; /**< IEEE only: 9217-16383 byte packets received */
    uint64_t rx_error_packets;      /**< RFC 1213 */
    uint64_t rx_unknown_protos;     /**< RFC 1213 */
    uint64_t rx_crc_errors;         /**< ITU only */
    uint64_t bip_errors;            /**< ITU only */
    uint64_t rx_mpcp;               /**< IEEE only: MPCP packets received, excluding reports */
    uint64_t rx_report;             /**< IEEE only: MPCP reports received */
    uint64_t rx_oam_bytes;          /**< IEEE only: OAM bytes received */
    uint64_t rx_oam_packets;        /**< IEEE only: OAM packets received */
    uint64_t tx_bytes;              /**< RFC 2233 */
    uint64_t tx_packets;            /**< RFC 1213 ucast + none-ucast */
    uint64_t tx_data_bytes;         /**< IEEE only: transmitted bytes excluding MPCP/OAM */
    uint64_t tx_ucast_packets;      /**< RFC 2233 */
    uint64_t tx_mcast_packets;      /**< RFC 2233 */
    uint64_t tx_bcast_packets;      /**< RFC 2233 */
    uint64_t tx_64_packets;         /**< IEEE only: 64 byte packets transmitted, excluding gates */
    uint64_t tx_65_127_packets;     /**< IEEE only: 65-127 byte packets transmitted */
    uint64_t tx_128_255_packets;    /**< IEEE only: 128-255 byte packets transmitted */
    uint64_t tx_256_511_packets;    /**< IEEE only: 256-511 byte packets transmitted */
    uint64_t tx_512_1023_packets;   /**< IEEE only: 512-1023 byte packets transmitted */
    uint64_t tx_1024_1518_packets;  /**< IEEE only: 1024-1518 byte packets transmitted */
    uint64_t tx_1519_2047_packets;  /**< IEEE only: 1519-2047 byte packets transmitted */
    uint64_t tx_2048_4095_packets;  /**< IEEE only: 2048-4095 byte packets transmitted */
    uint64_t tx_4096_9216_packets;  /**< IEEE only: 4096-9216 byte packets transmitted */
    uint64_t tx_9217_16383_packets; /**< IEEE only: 9217-16383 byte packets transmitted */
    uint64_t tx_error_packets;      /**< RFC 1213 */
    uint64_t tx_mpcp;               /**< IEEE only: MPCP packets transmitted, excluding gates */
    uint64_t tx_gate;               /**< IEEE only: MPCP gates transmitted */
    uint64_t tx_oam_bytes;          /**< IEEE only: OAM bytes transmitted */
    uint64_t tx_oam_packets;        /**< IEEE only: OAM packets transmitted */
} bcmbal_interface_stat_data;

/** Transport message definition for "stat" group of "interface" object. 
 */
typedef struct bcmbal_interface_stat
{
    bcmbal_stat hdr;                    /**< Transport header. */
    bcmbal_interface_key key;           /**< Object key. */
    bcmbal_interface_stat_data data;    /**< All properties that must be set by the user. */
} bcmbal_interface_stat;

/** Structure definition for the "los" group of the "interface" object. 
 *
 * An indication of a change olt los alarm 
 */
typedef struct bcmbal_interface_los_data
{
    bcmbal_alarm_status status; /**< The current admin status */
} bcmbal_interface_los_data;

/** Transport message definition for "los" group of "interface" object. 
 */
typedef struct bcmbal_interface_los
{
    bcmbal_auto hdr;                /**< Transport header. */
    bcmbal_interface_key key;       /**< Object key. */
    bcmbal_interface_los_data data; /**< All properties that must be set by the user. */
} bcmbal_interface_los;

/** Structure definition for the "oper_status_change" group of the "interface" 
 * object. 
 *
 * An indication of a change of operational status 
 */
typedef struct bcmbal_interface_oper_status_change_data
{
    bcmbal_status new_oper_status;  /**< The current oper status */
    bcmbal_status old_oper_status;  /**< The previous oper status before this indication was reported */
    bcmbal_state admin_state;       /**< The current admin status */
} bcmbal_interface_oper_status_change_data;

/** Transport message definition for "oper_status_change" group of "interface" 
 * object. 
 */
typedef struct bcmbal_interface_oper_status_change
{
    bcmbal_auto hdr;            /**< Transport header. */
    bcmbal_interface_key key;   /**< Object key. */
    bcmbal_interface_oper_status_change_data data;  /**< All properties that must be set by the user. */
} bcmbal_interface_oper_status_change;

/** Structure definition for the "key" group of the "packet" object. 
 */
typedef struct bcmbal_packet_key
{
    uint32_t reserved;              /**< Reserved key field. */
    bcmbal_dest packet_send_dest;   /**< Packet destination. */
} bcmbal_packet_key;

/** Structure definition for the "cfg" group of the "packet" object. 
 */
typedef struct bcmbal_packet_cfg_data
{
    bcmbal_flow_id flow_id;             /**< N/A for sending a packet */
    bcmbal_flow_type flow_type;         /**< Flow Type. */
    bcmbal_intf_id intf_id;             /**< Interface ID. */
    bcmbal_intf_type intf_type;         /**< Interface Type. */
    bcmbal_service_port_id svc_port;    /**< N/A for sending a packet */
    bcmbal_cookie flow_cookie;          /**< N/A for sending a packet */
    bcmbal_u8_list_u32_max_2048 pkt;    /**< Packet Data. */
} bcmbal_packet_cfg_data;

/** Transport message definition for "cfg" group of "packet" object. 
 */
typedef struct bcmbal_packet_cfg
{
    bcmbal_cfg hdr;                 /**< Transport header. */
    bcmbal_packet_key key;          /**< Object key. */
    bcmbal_packet_cfg_data data;    /**< All properties that must be set by the user. */
} bcmbal_packet_cfg;

/** Structure definition for the "bearer_channel_rx" group of the "packet" 
 * object. 
 */
typedef struct bcmbal_packet_bearer_channel_rx_data
{
    bcmbal_flow_id flow_id;             /**< N/A for sending a packet */
    bcmbal_flow_type flow_type;         /**< Flow Type. */
    bcmbal_intf_id intf_id;             /**< Interface ID. */
    bcmbal_intf_type intf_type;         /**< Interface Type. */
    bcmbal_service_port_id svc_port;    /**< N/A for sending a packet */
    bcmbal_cookie flow_cookie;          /**< N/A for sending a packet */
    bcmbal_u8_list_u32_max_2048 pkt;    /**< Packet Data. */
} bcmbal_packet_bearer_channel_rx_data;

/** Transport message definition for "bearer_channel_rx" group of "packet" 
 * object. 
 */
typedef struct bcmbal_packet_bearer_channel_rx
{
    bcmbal_auto hdr;        /**< Transport header. */
    bcmbal_packet_key key;  /**< Object key. */
    bcmbal_packet_bearer_channel_rx_data data;  /**< All properties that must be set by the user. */
} bcmbal_packet_bearer_channel_rx;

/** Structure definition for the "ieee_oam_channel_rx" group of the "packet" 
 * object. 
 *
 * Rx indication on the IEEE OAM channel 
 */
typedef struct bcmbal_packet_ieee_oam_channel_rx_data
{
    bcmbal_u8_list_u32_max_2048 pkt;    /**< Packet Data. */
} bcmbal_packet_ieee_oam_channel_rx_data;

/** Transport message definition for "ieee_oam_channel_rx" group of "packet" 
 * object. 
 */
typedef struct bcmbal_packet_ieee_oam_channel_rx
{
    bcmbal_auto hdr;        /**< Transport header. */
    bcmbal_packet_key key;  /**< Object key. */
    bcmbal_packet_ieee_oam_channel_rx_data data;    /**< All properties that must be set by the user. */
} bcmbal_packet_ieee_oam_channel_rx;

/** Structure definition for the "itu_omci_channel_rx" group of the "packet" 
 * object. 
 *
 * Rx indication on the ITU OMCI channel 
 */
typedef struct bcmbal_packet_itu_omci_channel_rx_data
{
    bcmbal_u8_list_u32_max_2048 pkt;    /**< Packet Data. */
} bcmbal_packet_itu_omci_channel_rx_data;

/** Transport message definition for "itu_omci_channel_rx" group of "packet" 
 * object. 
 */
typedef struct bcmbal_packet_itu_omci_channel_rx
{
    bcmbal_auto hdr;        /**< Transport header. */
    bcmbal_packet_key key;  /**< Object key. */
    bcmbal_packet_itu_omci_channel_rx_data data;    /**< All properties that must be set by the user. */
} bcmbal_packet_itu_omci_channel_rx;

/** Structure definition for the "key" group of the "subscriber_terminal" 
 * object. 
 */
typedef struct bcmbal_subscriber_terminal_key
{
    bcmbal_sub_id sub_term_id;  /**< sub_term_id. */
    bcmbal_intf_id intf_id;     /**< intf_id. */
} bcmbal_subscriber_terminal_key;

/** Structure definition for the "cfg" group of the "subscriber_terminal" 
 * object. 
 */
typedef struct bcmbal_subscriber_terminal_cfg_data
{
    bcmbal_state admin_state;               /**< Administrative state */
    bcmbal_status oper_status;              /**< Operational status */
    bcmbal_serial_number serial_number;     /**< The serial number of an  ITU PON (GPON/XG-PON1/XGS-PON/NG-PON2) subscriber terminal */
    bcmbal_password password;               /**< The password of a GPON subscriber terminal */
    bcmbal_registration_id registration_id; /**< ONU registration ID of an  ITU PON (XG-PON1/XGS-PON/NG-PON2) subscriber terminal */
    bcmbal_service_port_id svc_port_id;     /**< The management service port ID (for PON, the ONU ID) */
    bcmos_mac_address mac_address;          /**< The Ethernet MAC address of an EPON subscriber terminal */
    bcmbal_tm_sched_id ds_tm;               /**< Downstream scheduler and shaper */
    bcmbal_tm_sched_id us_tm;               /**< Upstream scheduler and shaper */
    bcmbal_service_port_id_list_u8 svc_port_id_list;        /**< A list of bearer traffic svc_port_ids associated with this subscriber terminal */
    bcmbal_aggregation_port_id_list_u8 agg_port_id_list;    /**< A list of aggr_port_ids associated with this subscriber terminal */
    bcmbal_sub_term_rate sub_term_rate;                     /**< sub_term_rate. */
    bcmbal_control us_fec;  /**< enable/disable us fec */
} bcmbal_subscriber_terminal_cfg_data;

/** Transport message definition for "cfg" group of "subscriber_terminal" 
 * object. 
 */
typedef struct bcmbal_subscriber_terminal_cfg
{
    bcmbal_cfg hdr;                     /**< Transport header. */
    bcmbal_subscriber_terminal_key key; /**< Object key. */
    bcmbal_subscriber_terminal_cfg_data data;   /**< All properties that must be set by the user. */
} bcmbal_subscriber_terminal_cfg;

/** Structure definition for the "dgi" group of the "subscriber_terminal" 
 * object. 
 */
typedef struct bcmbal_subscriber_terminal_dgi_data
{
    bcmbal_alarm_status dgi_status; /**< dgi_status. */
} bcmbal_subscriber_terminal_dgi_data;

/** Transport message definition for "dgi" group of "subscriber_terminal" 
 * object. 
 */
typedef struct bcmbal_subscriber_terminal_dgi
{
    bcmbal_auto hdr;                    /**< Transport header. */
    bcmbal_subscriber_terminal_key key; /**< Object key. */
    bcmbal_subscriber_terminal_dgi_data data;   /**< All properties that must be set by the user. */
} bcmbal_subscriber_terminal_dgi;

/** Structure definition for the "dowi" group of the "subscriber_terminal" 
 * object. 
 *
 * drift of window 
 */
typedef struct bcmbal_subscriber_terminal_dowi_data
{
    bcmbal_alarm_status dowi_status;    /**< dowi alarm status */
    uint32_t drift_value;               /**< Calculated amount of drift (positive + negative as a signed value). */
    uint32_t new_eqd;                   /**< New EQD after drift is corrected (only valid if status is 'on').  */
} bcmbal_subscriber_terminal_dowi_data;

/** Transport message definition for "dowi" group of "subscriber_terminal" 
 * object. 
 */
typedef struct bcmbal_subscriber_terminal_dowi
{
    bcmbal_auto hdr;                    /**< Transport header. */
    bcmbal_subscriber_terminal_key key; /**< Object key. */
    bcmbal_subscriber_terminal_dowi_data data;  /**< All properties that must be set by the user. */
} bcmbal_subscriber_terminal_dowi;

/** Structure definition for the "looci" group of the "subscriber_terminal" 
 * object. 
 *
 * loss of omci channel 
 */
typedef struct bcmbal_subscriber_terminal_looci_data
{
    bcmbal_alarm_status looci_status;   /**< status of loocs alarm */
} bcmbal_subscriber_terminal_looci_data;

/** Transport message definition for "looci" group of "subscriber_terminal" 
 * object. 
 */
typedef struct bcmbal_subscriber_terminal_looci
{
    bcmbal_auto hdr;                    /**< Transport header. */
    bcmbal_subscriber_terminal_key key; /**< Object key. */
    bcmbal_subscriber_terminal_looci_data data; /**< All properties that must be set by the user. */
} bcmbal_subscriber_terminal_looci;

/** Structure definition for the "oper_status_change" group of the 
 * "subscriber_terminal" object. 
 *
 * An indication of a change of operational status 
 */
typedef struct bcmbal_subscriber_terminal_oper_status_change_data
{
    bcmbal_status new_oper_status;  /**< The current oper status */
    bcmbal_status old_oper_status;  /**< The previous oper status before this indication was reported */
    bcmbal_state admin_state;       /**< The current admin status */
} bcmbal_subscriber_terminal_oper_status_change_data;

/** Transport message definition for "oper_status_change" group of 
 * "subscriber_terminal" object. 
 */
typedef struct bcmbal_subscriber_terminal_oper_status_change
{
    bcmbal_auto hdr;                    /**< Transport header. */
    bcmbal_subscriber_terminal_key key; /**< Object key. */
    bcmbal_subscriber_terminal_oper_status_change_data data;    /**< All properties that must be set by the user. */
} bcmbal_subscriber_terminal_oper_status_change;

/** Transport message definition for "processing_error" group of 
 * "subscriber_terminal" object. 
 */
typedef struct bcmbal_subscriber_terminal_processing_error
{
    bcmbal_auto hdr;                    /**< Transport header. */
    bcmbal_subscriber_terminal_key key; /**< Object key. */
} bcmbal_subscriber_terminal_processing_error;

/** Structure definition for the "sdi" group of the "subscriber_terminal" 
 * object. 
 *
 * signal degraded 
 */
typedef struct bcmbal_subscriber_terminal_sdi_data
{
    bcmbal_alarm_status sdi_status; /**< sdi alarm status */
    uint32_t ber;                   /**<  Inverse bit error rate (e.g. if this number is 1000, the BER is 1/1000). */
} bcmbal_subscriber_terminal_sdi_data;

/** Transport message definition for "sdi" group of "subscriber_terminal" 
 * object. 
 */
typedef struct bcmbal_subscriber_terminal_sdi
{
    bcmbal_auto hdr;                    /**< Transport header. */
    bcmbal_subscriber_terminal_key key; /**< Object key. */
    bcmbal_subscriber_terminal_sdi_data data;   /**< All properties that must be set by the user. */
} bcmbal_subscriber_terminal_sdi;

/** Structure definition for the "sfi" group of the "subscriber_terminal" 
 * object. 
 *
 * signal fail 
 */
typedef struct bcmbal_subscriber_terminal_sfi_data
{
    bcmbal_alarm_status sfi_status; /**< sfi alarm status */
    uint32_t ber;                   /**<  Inverse bit error rate (e.g. if this number is 1000, the BER is 1/1000). */
} bcmbal_subscriber_terminal_sfi_data;

/** Transport message definition for "sfi" group of "subscriber_terminal" 
 * object. 
 */
typedef struct bcmbal_subscriber_terminal_sfi
{
    bcmbal_auto hdr;                    /**< Transport header. */
    bcmbal_subscriber_terminal_key key; /**< Object key. */
    bcmbal_subscriber_terminal_sfi_data data;   /**< All properties that must be set by the user. */
} bcmbal_subscriber_terminal_sfi;

/** Structure definition for the "sub_term_act_fail" group of the 
 * "subscriber_terminal" object. 
 */
typedef struct bcmbal_subscriber_terminal_sub_term_act_fail_data
{
    bcmbal_sub_term_act_fail_reason fail_reason;    /**< Subscriber Terminal Activation Failure reason code. */
} bcmbal_subscriber_terminal_sub_term_act_fail_data;

/** Transport message definition for "sub_term_act_fail" group of 
 * "subscriber_terminal" object. 
 */
typedef struct bcmbal_subscriber_terminal_sub_term_act_fail
{
    bcmbal_auto hdr;                    /**< Transport header. */
    bcmbal_subscriber_terminal_key key; /**< Object key. */
    bcmbal_subscriber_terminal_sub_term_act_fail_data data; /**< All properties that must be set by the user. */
} bcmbal_subscriber_terminal_sub_term_act_fail;

/** Structure definition for the "sub_term_alarm" group of the 
 * "subscriber_terminal" object. 
 */
typedef struct bcmbal_subscriber_terminal_sub_term_alarm_data
{
    bcmbal_subscriber_terminal_alarms alarm;    /**< The serial number of an  ITU PON (GPON/XG-PON1/XGS-PON/NG-PON2) subscriber terminal */
} bcmbal_subscriber_terminal_sub_term_alarm_data;

/** Transport message definition for "sub_term_alarm" group of 
 * "subscriber_terminal" object. 
 */
typedef struct bcmbal_subscriber_terminal_sub_term_alarm
{
    bcmbal_auto hdr;                    /**< Transport header. */
    bcmbal_subscriber_terminal_key key; /**< Object key. */
    bcmbal_subscriber_terminal_sub_term_alarm_data data;    /**< All properties that must be set by the user. */
} bcmbal_subscriber_terminal_sub_term_alarm;

/** Structure definition for the "sub_term_disc" group of the 
 * "subscriber_terminal" object. 
 */
typedef struct bcmbal_subscriber_terminal_sub_term_disc_data
{
    bcmbal_serial_number serial_number; /**< The serial number of an  ITU PON (GPON/XG-PON1/XGS-PON/NG-PON2) subscriber terminal */
    bcmos_mac_address onu_mac;          /**< The mac address of an  IEEE PON (EPON)Subscriber terminal */
} bcmbal_subscriber_terminal_sub_term_disc_data;

/** Transport message definition for "sub_term_disc" group of 
 * "subscriber_terminal" object. 
 */
typedef struct bcmbal_subscriber_terminal_sub_term_disc
{
    bcmbal_auto hdr;                    /**< Transport header. */
    bcmbal_subscriber_terminal_key key; /**< Object key. */
    bcmbal_subscriber_terminal_sub_term_disc_data data; /**< All properties that must be set by the user. */
} bcmbal_subscriber_terminal_sub_term_disc;

/** Structure definition for the "sufi" group of the "subscriber_terminal" 
 * object. 
 *
 * start up failure 
 */
typedef struct bcmbal_subscriber_terminal_sufi_data
{
    bcmbal_alarm_status sufi_status;    /**< sufi alarm status */
} bcmbal_subscriber_terminal_sufi_data;

/** Transport message definition for "sufi" group of "subscriber_terminal" 
 * object. 
 */
typedef struct bcmbal_subscriber_terminal_sufi
{
    bcmbal_auto hdr;                    /**< Transport header. */
    bcmbal_subscriber_terminal_key key; /**< Object key. */
    bcmbal_subscriber_terminal_sufi_data data;  /**< All properties that must be set by the user. */
} bcmbal_subscriber_terminal_sufi;

/** Structure definition for the "tiwi" group of the "subscriber_terminal" 
 * object. 
 *
 * transmission interference 
 */
typedef struct bcmbal_subscriber_terminal_tiwi_data
{
    bcmbal_alarm_status tiwi_status;    /**< tiwi alarm status */
    uint32_t drift_value;               /**<  Calculated amount of drift (positive + negative as a signed value). */
} bcmbal_subscriber_terminal_tiwi_data;

/** Transport message definition for "tiwi" group of "subscriber_terminal" 
 * object. 
 */
typedef struct bcmbal_subscriber_terminal_tiwi
{
    bcmbal_auto hdr;                    /**< Transport header. */
    bcmbal_subscriber_terminal_key key; /**< Object key. */
    bcmbal_subscriber_terminal_tiwi_data data;  /**< All properties that must be set by the user. */
} bcmbal_subscriber_terminal_tiwi;

/** Structure definition for the "key" group of the "sys_channel_profile" 
 * object. 
 */
typedef struct bcmbal_sys_channel_profile_key
{
    int32_t sys_id; /**< StateManager::gentable_handlers.c */
} bcmbal_sys_channel_profile_key;

/** Structure definition for the "cfg" group of the "sys_channel_profile" 
 * object. 
 */
typedef struct bcmbal_sys_channel_profile_cfg_data
{
    bcmbal_system_profile system_profile;           /**< System profile. */
#define BCMBAL_SYS_CHANNEL_PROFILE_CFG_DATA_CHANNEL_PROFILE_LEN 8
    bcmbal_arr_channel_profile_8 channel_profile;   /**< Channel profile. */
    uint8_t ref_count;  /**< reference count */
} bcmbal_sys_channel_profile_cfg_data;

/** Transport message definition for "cfg" group of "sys_channel_profile" 
 * object. 
 */
typedef struct bcmbal_sys_channel_profile_cfg
{
    bcmbal_cfg hdr;                     /**< Transport header. */
    bcmbal_sys_channel_profile_key key; /**< Object key. */
    bcmbal_sys_channel_profile_cfg_data data;   /**< All properties that must be set by the user. */
} bcmbal_sys_channel_profile_cfg;

/** Structure definition for the "ind" group of the "sys_channel_profile" 
 * object. 
 */
typedef struct bcmbal_sys_channel_profile_ind_data
{
    bcmbal_system_profile system_profile;           /**< system profile. */
#define BCMBAL_SYS_CHANNEL_PROFILE_IND_DATA_CHANNEL_PROFILE_LEN 8
    bcmbal_arr_channel_profile_8 channel_profile;   /**< channel profile. */
    uint8_t ref_count;  /**< ref_count. */
} bcmbal_sys_channel_profile_ind_data;

/** Transport message definition for "ind" group of "sys_channel_profile" 
 * object. 
 */
typedef struct bcmbal_sys_channel_profile_ind
{
    bcmbal_auto hdr;                    /**< Transport header. */
    bcmbal_sys_channel_profile_key key; /**< Object key. */
    bcmbal_sys_channel_profile_ind_data data;   /**< All properties that must be set by the user. */
} bcmbal_sys_channel_profile_ind;

/** Structure definition for the "key" group of the "tm_queue" object. 
 */
typedef struct bcmbal_tm_queue_key
{
    bcmbal_tm_sched_id sched_id;    /**< Scheduler that owns the queue */
    bcmbal_tm_sched_dir sched_dir;  /**< sched dir. */
    bcmbal_tm_queue_id id;          /**< Queue id */
} bcmbal_tm_queue_key;

/** Structure definition for the "cfg" group of the "tm_queue" object. 
 */
typedef struct bcmbal_tm_queue_cfg_data
{
    bcmbal_tm_priority priority;            /**< Scheduling priority */
    bcmbal_tm_weight weight;                /**< Scheduling weight */
    bcmbal_tm_shaping rate;                 /**< Rate shaping parameters */
    bcmbal_tm_bac bac;                      /**< Buffer admission control */
    bcmbal_tm_creation_mode creation_mode;  /**< Creation mode */
    uint8_t ref_count;                      /**< reference count (flows) */
} bcmbal_tm_queue_cfg_data;

/** Transport message definition for "cfg" group of "tm_queue" object. 
 */
typedef struct bcmbal_tm_queue_cfg
{
    bcmbal_cfg hdr;                 /**< Transport header. */
    bcmbal_tm_queue_key key;        /**< Object key. */
    bcmbal_tm_queue_cfg_data data;  /**< All properties that must be set by the user. */
} bcmbal_tm_queue_cfg;

/** Structure definition for the "key" group of the "tm_sched" object. 
 */
typedef struct bcmbal_tm_sched_key
{
    bcmbal_tm_sched_dir dir;    /**< Traffic direction */
    bcmbal_tm_sched_id id;      /**< ID */
} bcmbal_tm_sched_key;

/** Structure definition for the "cfg" group of the "tm_sched" object. 
 */
typedef struct bcmbal_tm_sched_cfg_data
{
    bcmbal_tm_sched_owner owner;        /**< The owner of the tm_sched object instance */
    bcmbal_tm_sched_type sched_type;    /**< Scheduler type */
    bcmbal_tm_sched_parent sched_parent;        /**< Scheduling parameters for parent scheduler */
    uint8_t num_priorities;                     /**< Max number of strict priority scheduling elements */
    bcmbal_tm_shaping rate;                     /**< Rate shaping parameters */
    bcmbal_extended_itu_dba ext_itu_dba;        /**< Extended itu dba parameters for an agg_port owned tm_sched */
    bcmbal_extended_epon_dba ext_epon_dba;      /**< epon dba parameters for an agg_port owned tm_sched */
    bcmbal_tm_creation_mode creation_mode;      /**< Creation mode */
    bcmbal_tm_queue_id_list_u8 queue_list;      /**< Subsidiary queues */
    bcmbal_tm_sched_id_list_u8 sub_sched_list;  /**< Subsidiary schedulers */
    bcmbal_status oper_status;                  /**< Current Agg Port oper status */
} bcmbal_tm_sched_cfg_data;

/** Transport message definition for "cfg" group of "tm_sched" object. 
 */
typedef struct bcmbal_tm_sched_cfg
{
    bcmbal_cfg hdr;                 /**< Transport header. */
    bcmbal_tm_sched_key key;        /**< Object key. */
    bcmbal_tm_sched_cfg_data data;  /**< All properties that must be set by the user. */
} bcmbal_tm_sched_cfg;

/** Structure definition for the "oper_status_change" group of the "tm_sched" 
 * object. 
 */
typedef struct bcmbal_tm_sched_oper_status_change_data
{
    bcmbal_status new_oper_status;  /**< new oper status. */
    bcmbal_status old_oper_status;  /**< old oper status. */
} bcmbal_tm_sched_oper_status_change_data;

/** Transport message definition for "oper_status_change" group of "tm_sched" 
 * object. 
 */
typedef struct bcmbal_tm_sched_oper_status_change
{
    bcmbal_auto hdr;            /**< Transport header. */
    bcmbal_tm_sched_key key;    /**< Object key. */
    bcmbal_tm_sched_oper_status_change_data data;   /**< All properties that must be set by the user. */
} bcmbal_tm_sched_oper_status_change;

typedef bcmbal_access_id bcmbal_access_term_id;

/** @} */
#endif /* BAL_MODEL_TYPES */
