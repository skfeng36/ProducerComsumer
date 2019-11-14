/*
 * Thread.h
 *
 *  Created on: Feb 14, 2013
 *      Author: skfeng36@163.com
 */

#ifndef _THREAD_H_
#define _THREAD_H_

#include <pthread.h>
#include <stdio.h>

namespace SuperK {

    class Thread {

    public:
	    Thread (void* (*func)(void*),void* data);
	    virtual ~Thread();
	    void Cancel();
            pthread_t  GetId();
    private:
	    pthread_attr_t attr_;
	    pthread_t id_;  
    };
};
#endif /* THREAD_H_ */

