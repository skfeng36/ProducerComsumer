/*
 * Mutex.h
 *
 *  Created on: Feb 14, 2013
 *      Author: skfeng36@163.com
 */
#ifndef _MUTEX_H_
#define _MUTEX_H_
#include <pthread.h>
#include "Util.h"

namespace SuperK {
    class Mutex {
    public:
	    Mutex(){
            pthread_mutex_init(&mutex_, NULL);
        }
	    virtual ~Mutex(){
            pthread_mutex_destroy(&mutex_);
        }
        int32_t Lock(){
	        return pthread_mutex_lock(&mutex_);
        }
        int32_t TryLock(){
	        return pthread_mutex_trylock(&mutex_);
        }

        int32_t UnLock(){
	        return pthread_mutex_unlock(&mutex_);
        }
    private:
	    pthread_mutex_t mutex_;
    };
};
#endif 

