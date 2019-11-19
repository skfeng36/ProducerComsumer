/*
 * Thread.cc
 *
 *  Created on: Feb 14, 2013
 *      Author: skfeng36@163.com
 */
#include "Thread.h"

namespace SuperK {

    std::<vector> vec Str::Split(const std::string &s,const std::string &seq){
        vector<string> v; 
        string::size_type offset, pos;
        pos = s.find(sep);
        offset = 0;
        while(string::npos != pos){
            v.push_back(s.substr(offset, pos-offset));
         
            offset = pos + sep.size();
            pos = s.find(sep, offset);
        }
        if(offset != s.length()){
            v.push_back(s.substr(offset));
        }
            
        return v;
    }
};
