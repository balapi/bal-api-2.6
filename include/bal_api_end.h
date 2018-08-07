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
 * @file bal_api_end.h
 * @brief BAL API End in Distributed mode header file.
 * @defgroup balapimod BAL API side module
 */
#ifndef _BAL_API_END_H
#define _BAL_API_END_H

/*@{*/

#include <bcmos_system.h>
#include "bal_api.h"
#include "bal_version.h"
#include "bal_dist_common_utils_external.h"

#ifdef ENABLE_LOG
/*
 * @brief The Logging device id for the BAL API End
 */
extern dev_log_id log_id_apiend;
#endif

#define bcmbal_init(_argc, _argv, _exit_cb)     bcmbal_apiend_init_all((_argc), (_argv), (_exit_cb), BAL_MODE_DIST_API)
#define bcmbal_cli_exec_init_script()           bcmbal_apiend_cli_exec_init_script()
#define bcmbal_cli_is_terminated()              bcmbal_apiend_cli_is_terminated()
#define bcmbal_finish()                         bcmbal_apiend_finish()


/** @brief externs defined in other file(s) */
extern bcmos_errno bcmbal_apiend_init_all(int argc, char *argv[], bcmbal_exit_cb exit_cb, bcmbal_bal_mode mode);
extern bcmos_errno bcmbal_apiend_finish(void);
#if defined(ENABLE_CLI) && defined(ENABLE_CLI_BAL_APIEND)
extern bcmos_errno bcmbal_apiend_cli_exec_init_script(void);
extern bcmos_bool  bcmbal_apiend_cli_is_terminated(void);
extern bcmos_errno bcmbal_apiend_cli_init(bcmbal_exit_cb exit_cb);
extern void bcmbal_apiend_cli_stop(void);
extern bcmos_errno bcmbal_apiend_cli_finish(void);
#endif


/**
 * @brief Get the number of NNI ports supported by the running system
 *
 * @returns Number of NNI ports
 */
uint16_t bcmbal_num_nni_ports_get(void);


/*@}*/

#endif //_BAL_API_END_H
