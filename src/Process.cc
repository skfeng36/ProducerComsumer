/*
 * Process.cc
 *
 *  Created on: Feb 14, 2013
 *      Author: skfeng36@163.com
 */

#include <errno.h>
#include "Process.h"

namespace SuperK {

    Process::Process(Config * config){
        config_=config;
    }

    Process::~Process(){
        ;
    }
    void Process::Init(){
        SetDaemon();
        RecordPid();
    }
    void Process::RecordPid(){
        if(NULL!=config_){
            std::string pid_path=config_->GetStringValue("process_path");
            std::string process_name=config_->GetStringValue("process_name");
            pid_path.append("/logs/");
            pid_path.append(process_name);
            pid_path.append(".pid");
            std::ofstream out;
            out.open(pid_path.c_str()); 
 
            if(!out.is_open ()){
                printf("Open pid %s failure, error code %d\n",pid_path.c_str(),errno);
            }
            out<<pid_;
        }

    }
    void Process::SetDaemon(){
        int pid = fork();
        if(pid < 0){
            printf("SetDaemon fork error!\n");
	    exit(0);
        }if(pid > 0){
	    exit(0);
	}    
        if(setsid()<0){
            printf("SetDaemon setsid error\n");
	    exit(0);
        }
        chdir("/");
        umask(0);
        pid_=getpid();  
    }
    void Process::MonitorState(){
        ;
    }


};
