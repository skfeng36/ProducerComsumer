/*
 * BlockQueue.h
 *
 *  Created on: Feb 14, 2013
 *      Author: skfeng36@163.com
 */
#ifndef _BLOCKQUEUE_H_
#define _BLOCKQUEUE_H_

#include <queue>
#include <semaphore.h>
#include <pthread.h>
#include <sys/errno.h>
#include <stdio.h>
#include "Uitl.h"
#include "Mutex.h"
#include "Semaphore.h"
namespace SuperK {

    template <class T>
    class BlockQueue{
    public:
	    BlockQueue();
	    ~BlockQueue();
	    T *Get();
	    void Add(T *data);
	    int32_t Length();
    private:
	    Semaphore sem_;
	    Mutex mutex_;
	    std::queue<T *> queue_;
    };

    template <class T>
    BlockQueue<T>::BlockQueue(){
    ;
    }

    template <class T>
    BlockQueue<T>::~BlockQueue(){
	    while(!queue_.empty()){
		    T *data = queue_.front();
		    queue_.pop();
		    SAFE_DELETE(data);
	    }
    }

    template <class T>
    int32_t BlockQueue<T>::Length(){
	    return queue_.size();
    }

    template<class T>
    T* BlockQueue<T>::Get(){
	    if(0 != sem_.SemWait()){
		    printf("sem_wait error\n");
	    }
	    mutex_.Lock();
	    T *data = queue_.front();
	    queue_.pop();
	    mutex_.Unlock();;

	    return data;
    }

    template<class T>
    void BlockQueue<T>::Add(T *data){
	    mutex_.Lock();
	    queue_.push(data);
	    if(0 != PostSem(sem_)){
		    printf("sem_post error\n");
	    }
	    mutex_.Unlock();;
    }
};
#endif // _BLOCKQUEUE_H_
