/*
 * Config.cc
 *
 *  Created on: Feb 14, 2013
 *      Author: skfeng36@163.com
 */

#include "Config.h"

namespace SuperK {

    Config::Config(std::string filename){
        filename_=filename;
        Init();
        ToString();
    }
    Config::~Config(){
        ;
    }
    void Config::Init(){
        std::string process_path;
        char path[128];
        memset(path, 0x00, sizeof(path));    
        getcwd(path, sizeof(path)-1);
        process_path=std::string(path);
        process_path=process_path.substr(0,process_path.length()-3);
        fields_.insert(std::pair<std::string,std::string>("process_path",process_path));
        if(filename_.empty()){
            filename_=process_path.append("/conf/config.ini");
        }
        fields_.insert(std::pair<std::string,std::string>("config_path",filename_));
        
        std::ifstream in(filename_.c_str()); 
        std::string content; 
        if (!in.is_open()){ 
            printf("open %s file failure, error code %d\n",filename_.c_str(),errno);
            exit(0); 
        } 
        while(getline(in,content)){ 
            std::vector<std::string> s;
            std::string::size_type pos;
            if(content.find("#")!=std::string::npos){
                continue;
            }else{
                if((pos=content.find_first_of("="))!=std::string::npos){
                    std::string key=content.substr(0,pos);
                    std::string value=content.substr(pos+1,content.size()-pos);
                    fields_.insert(std::pair<std::string,std::string>(key,value));
  
                }
            } 
       }
       in.close(); 
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

    void Config::ToString(){
         for(std::map<std::string, std::string>::iterator it=fields_.begin(); it!=fields_.end();++it){
             printf("%s:%s\n",it->first.c_str(),it->second.c_str());
         }
    }
};

