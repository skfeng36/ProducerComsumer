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
template <class T>
class BlockQueue{
public:
	BlockQueue();
	~BlockQueue();
	T *Get();
	void Add(T *data);
	int32_t Length();
private:
	int32_t WaitSem();
	int32_t PostSem();
	int32_t LockMutex();
	int32_t UnlockMutex();
	sem_t sem_;
	pthread_mutex_t mutex_;
	std::queue<T *> queue_;
};

template <class T>
BlockQueue<
T>::BlockQueue(){
	sem_init(&sem_, 0, 0);
	pthread_mutex_init(&mutex_, NULL);
}

template <class T>
BlockQueue<T>::~BlockQueue(){
	sem_destroy(&sem_);
	pthread_mutex_destroy(&mutex_);
	while(!queue_.empty()){
		T *data = queue_.front();
		queue_.pop();
		SAFE_DELETE(data);
	}
}

template<class T>
int32_t BlockQueue<T>::PostSem(){
	return sem_post(&sem_);
}

template<class T>
int32_t BlockQueue<T>::LockMutex(){
	return pthread_mutex_lock(&mutex_);
}

template<class T>
int32_t BlockQueue<T>::UnlockMutex(){
	return pthread_mutex_unlock(&mutex_);
}

template <class T>
int32_t BlockQueue<T>::Length(){
	return queue_.size();
}

template<class T>
T* BlockQueue<T>::Get(){
	if(0 != WaitSem()){
		printf("sem_wait error\n");
	}
	LockMutex();
	T *data = queue_.front();
	queue_.pop();
	UnlockMutex();

	return data;
}

template<class T>
void BlockQueue<T>::Add(T *data){
	LockMutex();
	queue_.push(data);
	if(0 != PostSem()){
		printf("sem_post error\n");
	}
	UnlockMutex();
}

template<class T>
int32_t BlockQueue<T>::WaitSem(){
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

#endif // _CONFIGREADER_H_
