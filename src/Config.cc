/*
 * Config.cc
 *
 *  Created on: Feb 14, 2013
 *      Author: skfeng36@163.com
 */

#include "Config.h"

namespace SuperK {

    Config::Config(std::string filename){
        if(filename.empty()){
            char path[128];
            memset(path, 0x00, sizeof(path));    
            getcwd(path, sizeof(path)-1);
            filename=std::string(path);
            filename.append("/conf");
        }
        fields_.insert(std::pair<std::string,std::string>("config_path",filename));
        std::ifstream in(filename.c_str()); 
        std::string content; 
        if (!in.is_open()){ 
            printf("open file error"); 
        } 
        while(getline(in,content)){ 
            std::vector<std::string> s;
            std::string::size_type pos;
            if(content.find("#")!=std::string::npos){
                continue;
            }else{
                if((pos=content.find_first_of("="))!=std::string::npos){
                    std::string key=content.substr(0,pos);
                    std::string value=content.substr(pos,content.size()-pos);
                    fields_.insert(std::pair<std::string,std::string>(key,value));
                }
            } 
            in.close(); 
       }
    }
    Config::~Config(){
        ;
    }

    std::string Config::GetStringValue(const std::string &key){
        std::map<std::string,std::string>::iterator it;
        if((it=fields_.find(key))!=fields_.end()){
            return it->second;
        }
        return "" ;
    }
    int32_t Config::GetIntValue(const std::string &key){
        std::map<std::string,std::string>::iterator it;
        if((it=fields_.find(key))!=fields_.end()){
            return atoi(it->second.c_str());
        }
        return 0 ;
    }

    void ToString(){
        ;
    }
};

