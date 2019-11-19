/*
 * Context.h
 *
 *  Created on: Feb 14, 2013
 *      Author: skfeng36@163.com
 */


#ifndef _CONTEXT_H_H
#define _CONTEXT_H_H

#include <unistd.h>
#include <stdint.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include "Config.h"

namespace SuperK {

    class Context{
    public:
	    Context(){
                config_=new Config();
            }
	    virtual ~Context(){};
            Config * GetConfig(){
                return config_;
            }

    private:
            Config * config_;
    };
};

#endif
