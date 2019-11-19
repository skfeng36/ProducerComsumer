/*
 * Str.h
 *
 *  Created on: Feb 14, 2013
 *      Author: skfeng36@163.com
 */
#ifndef _STR_H_
#define _STR_H_

#include <string>
#include <vector>

namespace SuperK {
    class Str{
    public:
	    static std::vector<std::string>  Split(const std::string &s,const std::string &seq);
    };
};
#endif
