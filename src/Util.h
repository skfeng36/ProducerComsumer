/*
 * Util.h
 *
 *  Created on: Feb 14, 2013
 *      Author: skfeng36@163.com
 */
#ifndef _UTIL_H_
#define _UTIL_H_

#include <stdio.h>
#include <stdint.h>

#define SAFE_FREE(x)		\
		if(x != NULL) {free(x);x = NULL;}
#define SAFE_DELETE(x)		\
		if(x != NULL) {delete(x);x = NULL;}

#endif // _UTIL_H_
