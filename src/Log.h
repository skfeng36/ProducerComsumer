/*
 * Log.h
 *
 *  Created on: Feb 14, 2013
 *      Author: skfeng36@163.com
 */
#ifndef _LOG_H_
#define _LOG_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
#include <string>
#include "Mutex.h"

mamespace SuperK {
    class Log{
    public:
	    Log(std::string filename, int32_t level = 8);
	    virtual ~Log();
	    bool Init(int32_t flags, mode_t mode);
	    int32_t Write(char *buf, int32_t len);
	    int32_t GetLogLevel(){
		    return m_level;
	    }
    private:
	    Mutex mutex_;
	    int32_t fd_;
	    int32_t level_;
	    std::string filename_;
    };
};
#endif
