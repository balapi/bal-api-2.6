/******************************************************************************
 *
 *  <:copyright-BRCM:2018:DUAL/GPL:standard
 *
 *     Copyright (c) 2018 Broadcom
 *     All Rights Reserved
 *
 *  Unless you and Broadcom execute a separate written software license
 *  agreement governing use of this software, this software is licensed
 *  to you under the terms of the GNU General Public License version 2
 *  (the "GPL"), available at http://www.broadcom.com/licenses/GPLv2.php,
 *  with the following added to such license:
 *
 *     As a special exception, the copyright holders of this software give
 *     you permission to link this software with independent modules, and
 *     to copy and distribute the resulting executable under terms of your
 *     choice, provided that you also meet, for each linked independent
 *     module, the terms and conditions of the license of that module.
 *     An independent module is a module which is not derived from this
 *     software.  The special exception does not apply to any modifications
 *     of the software.
 *
 *  Not withstanding the above, under no circumstances may you combine
 *  this software in any way with any other Broadcom software provided
 *  under a license other than the GPL, without Broadcom's express prior
 *  written consent.
 *
 *  :>
 *
 *****************************************************************************/

/**
 * @file bcmos_system.h
 * @brief The file provides a FAKE stub for bcmos_system.h
 *
 */
#ifndef BCMOS_SYSTEM_H
#define BCMOS_SYSTEM_H

#include <pthread.h>
#include <semaphore.h>
#include "bal_osmsg.h"

/** BCM68620 module (FAKE)
 * \ingroup system_module
 */
typedef enum
{
    BCMOS_MODULE_ID_NONE,                       /**< no module */
}bcmos_module_id;

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef long long unsigned int uint64_t;

typedef signed char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef long long int64_t;

typedef _Bool bcmos_bool;

#define BCMOS_ETH_ALEN   6

/** MAC address */
typedef struct
{
    uint8_t u8[BCMOS_ETH_ALEN];
} bcmos_mac_address;

/** IPv4 address. It is stored in network byte order. */
typedef union
{
    uint32_t u32;
    uint8_t u8[4];
} bcmos_ipv4_address;


/** IPv6 address */
typedef uint8_t bcmos_ipv6_address[16];

#define BCMOS_TRUE 1
#define BCMOS_FALSE 0

typedef enum
{
    BCMOS_ENDIAN_BIG_E          = 0,
    BCMOS_ENDIAN_LITTLE_E       = 1,
} bcmos_endian;

#define __PACKED_ATTR_START__
#define __PACKED_ATTR_END__ __attribute__ ((packed))

/** 24-bit unsigned integer */
typedef union
{
    uint8_t u8[3];
    struct __PACKED_ATTR_START__
    {
        uint8_t low;
        uint8_t mid;
        uint8_t hi;
    } __PACKED_ATTR_END__ low_hi;
} uint24_t;

/** VLAN tag (CoS/CFI/VID) */
typedef uint16_t bcmos_vlan_tag;

/** FAKE Message header for compilation */
typedef struct bcmos_msg bcmos_msg;

typedef uint16_t bcmos_msg_instance;
typedef void (*F_bcmos_msg_handler)(bcmos_module_id module_id, bcmos_msg *msg);

typedef uint32_t bcmos_msg_queue_ep_type;
typedef uint32_t bcmos_msg_send_flags;

typedef struct bcmos_msg_addr
{
    bcmos_msg_queue_ep_type type;       /**< Address type */
    uint32_t len;                       /**< Address length */
    void *addr;                         /**< Address pointer */
} bcmos_msg_addr;

/** Message header */
struct bcmos_msg
{
    bcmos_msg_id   type;        /**< Message type */
    bcmos_msg_instance instance;/**< Message recipient instance (e.g., optical link id) */
    bcmos_module_id sender;     /**< Sender module */
    F_bcmos_msg_handler handler;/**< Message handler. Can be set by the sender or message dispatcher */
    struct bcmos_msg *next; /**< Next message pointer */
    void *data;                 /**< Message data pointer */
    void *start;                /**< Message data block start (for release) */
    void *user_data;            /**< User pointer. Opaque for OS abstraction */
    uint32_t size;              /**< Message data size */
    bcmos_msg_send_flags send_flags;    /**< Flags the message was sent with */
#define BCMOS_MSG_QUEUE_SIZE_UNLIMITED    0xFFFFFFFF      /**< Unlimited queue */
#ifdef BCMOS_MSG_QUEUE_REMOTE_SUPPORT
    bcmos_msg_addr addr;        /**< Sender address for received message, destination address when sending */
#endif
    void (*release)(bcmos_msg *);       /**< Release callback */
    void (*data_release)(bcmos_msg *);  /**< Data release callback. Used when message is released to message pool */
};


/** FAKE semaphore for compilation */
typedef struct bcmos_sem
{
    sem_t s;      /**< posix semaphore */
} bcmos_sem;

#endif /* BCMOS_SYSTEM_H */
