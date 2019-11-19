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
            std::string pid_path=config_->GetStringValue("pid_path");
            if(!pid_path.empty()){

            }else{

            }
            
        }

    }
    void Process::SetDaemon(){
        int pid = fork();
        if(pid < 0){
            printf("SetDaemon fork error!");
	    exit(0);
        }if(pid > 0){
	    exit(0);
	}
        if(setsid()<0){
            printf("SetDaemon setsid error");
	    exit(0);
        }
        chdir("/");
        umask(0);
        for(int i=0;i<=/*getdablesize()*/1024;i++){
            close(i);
        }
        pid_=pid;
    }
    void Process::MonitorState(){
        ;
    }


};
