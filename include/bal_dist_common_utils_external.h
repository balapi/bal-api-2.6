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
 * @file bal_dist_common_utils_external.h
 * @brief BAL Utilities include file for Distributed Mode that can be exposed to external users
 *
 * @defgroup dist_util Bal Dist Util Routines
 * @ingroup lib
 */

#ifndef _BAL_DIST_COMMON_UTILS_EXTERNAL_H
#define _BAL_DIST_COMMON_UTILS_EXTERNAL_H

/*@{*/

#include <bcmos_system.h>


/**
 * @brief BAL modes
 */
typedef enum 
{
    BAL_MODE_UNDEFINED = 0,
    BAL_MODE_MONO,
    BAL_MODE_DIST_CORE,
    BAL_MODE_DIST_API
} bcmbal_bal_mode;

#define BAL_MODE_IS_VALID(_bal_mode)    ((BAL_MODE_MONO <= (_bal_mode)) && (BAL_MODE_DIST_API >= (_bal_mode)))


typedef void (* bcmbal_exit_cb)(void);


/*@}*/

#endif /* _BAL_DIST_COMMON_UTILS_EXTERNAL_H*/
