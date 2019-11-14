/*
 * Process.cc
 *
 *  Created on: Feb 14, 2013
 *      Author: skfeng36@163.com
 */

#include <errno.h>
#include "Process.h"

namespace SuperK {

    Process::Process(){
        ;
    }

    Process::~Process(){
        ;
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
    }


};
