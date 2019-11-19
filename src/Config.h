/*
 * Config.h
 *
 *  Created on: Feb 14, 2013
 *      Author: skfeng36@163.com
 */
#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string>
#include <map>
#include <stdint.h>
#include <fstream>
#include <stdlib.h>
#include<stdio.h>
#include<string.h>
#include "common/Str.h"

namespace SuperK {
    class Config{
    public:
	    Config(std::string filename="");
	    virtual ~Config();
	    std::string GetStringValue(const std::string &key);
            int32_t GetIntValue(const std::string &key);
            void ToString();

    private:
	    std::map<std::string ,std::string> fields_;
            const std::string filename_;
    };
};
#endif
