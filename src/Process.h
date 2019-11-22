/*
 * Process.h
 *
 *  Created on: Feb 14, 2013
 *      Author: skfeng36@163.com
 */


#ifndef _PROCESS_H_H
#define _PROCESS_H_H

#include <unistd.h>
#include <stdint.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include "Config.h"
namespace SuperK {

    class Process{
    public:
	    Process(Config * config);
	    virtual ~Process();
	    void SetDaemon();
            void RecordPid();
            void CheckOptions(int32_t argc, char *argv[]);
            void MonitorState();
            void Restart();
            void Stop();
            virtual void Init();
            void SignalHander();

    private:
	    int32_t pid_;
            Config * config_;
    };
};

#endif

