/*
 * Thread.cc
 *
 *  Created on: Feb 14, 2013
 *      Author: skfeng36@163.com
 */
#include "Thread.h"

namespace SuperK {

   Thread::Thread(void* (*func)(void*),void* data) {
	    pthread_attr_init(&attr_);
	    pthread_attr_setdetachstate(&attr_, PTHREAD_CREATE_DETACHED);
	    pthread_create(&id_, &attr_, func, data);
    }
    Thread::~Thread() {
	    pthread_attr_destroy(&attr_);
    }
    void Thread::Cancel(){
	    pthread_cancel(id_);
    }
    pthread_t  Thread::GetId(){
	    return id_;
    }
};
