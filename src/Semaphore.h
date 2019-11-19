/*
 * Semaphore.h
 *
 *  Created on: Feb 14, 2013
 *      Author: skfeng36@163.com
 */
#ifndef _SEMAPHORE_H_
#define _SEMAPHORE_H_
#include <semaphore.h>
#include <pthread.h>
#include "Util.h"

namespace SuperK {
    class Semaphore {
    public:
	    Semaphore(){
	        sem_init(&sem_, 0, 0);
            }
	    virtual ~Semaphore(){
	        sem_destroy(&sem_);
            }
            int32_t SemPost(){
	        return sem_post(&sem_);
            }

            int32_t SemWait(){
	        while(true){
		    if(sem_wait(&sem_) == 0){
			    return 0;
		    }else if(errno == EINTR){
			    continue;
		    }else{
			    return -1;
		    }
	        }
           }
    private:
	    sem_t sem_;
    };
};/* Superk*/
#endif 

