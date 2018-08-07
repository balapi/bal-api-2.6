##############################################################################
#
#  <:copyright-BRCM:2018:DUAL/GPL:standard
#
#     Copyright (c) 2018 Broadcom
#     All Rights Reserved
#
#  Unless you and Broadcom execute a separate written software license
#  agreement governing use of this software, this software is licensed
#  to you under the terms of the GNU General Public License version 2
#  (the "GPL"), available at http://www.broadcom.com/licenses/GPLv2.php,
#  with the following added to such license:
#
#     As a special exception, the copyright holders of this software give
#     you permission to link this software with independent modules, and
#     to copy and distribute the resulting executable under terms of your
#     choice, provided that you also meet, for each linked independent
#     module, the terms and conditions of the license of that module.
#     An independent module is a module which is not derived from this
#     software.  The special exception does not apply to any modifications
#     of the software.
#
#  Not withstanding the above, under no circumstances may you combine
#  this software in any way with any other Broadcom software provided
#  under a license other than the GPL, without Broadcom's express prior
#  written consent.
#
#  :>
#
#############################################################################/

all: clean balapi_stubs hello_bal hello_bal_app

export BAL_EXTRA_CFLAGS=-m32 -march=i386 -lpthread -lrt -DBCMOS_MSG_QUEUE_REMOTE_SUPPORT

BAL_SO_LIB_DIR=-L../

BAL_SO_LIB=-lbal_api_dist



balapi_stubs:
	make -C ../stubs

#Build hello_bal with BAL stub functions for BAL API calls
hello_bal:
	gcc -DBAL_API_STUB $(BAL_EXTRA_CFLAGS) hello_bal.c ../stubs/balapi_stubs.o -I ../include -o hello_bal


#Build hello_bal with actual BAL API functions for BAL API calls
#Note: This needs BAL shared lib from building BAL image obtained through Broadcom SLA, or obtained by other means.
hello_bal_app:
	test -s ../libbal_api_dist.so && \
	gcc $(BAL_EXTRA_CFLAGS) hello_bal.c -I ../include  $(BAL_SO_LIB_DIR) $(BAL_SO_LIB) -o hello_bal_app \
	|| \
	echo "libbal_api_dist.so not found! Not building hello_bal..." && exit


clean:
	rm -rf hello_bal
	rm -rf hello_bal_app
