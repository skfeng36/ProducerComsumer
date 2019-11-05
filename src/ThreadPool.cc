/*
 * ThreadPool.cc
 *
 *  Created on: Feb 14, 2013
 *      Author: skfeng36@163.com
 */

#include <errno.h>
#include "ThreadPool.h"

namespace SuperK {
    void *ThreadPool::ThreadFunc(void *arg){
	    ThreadPool *thread_pool = (ThreadPool *) arg;
	
	    while(true){
		    Task *task = thread_pool->RemoveTask();
		    thread_pool->Run(task);
		    SAFE_DELETE(task);
	    }

	    return NULL;
    }

    ThreadPool(int32_t max_task_num, int32_t thread_num){
	    max_task_num_ = max_task_num;
	    for(int32_t i = 0; i < thread_num; i++){
		    Thread *thread = new Thread(ThreadFunc, this);
		    threads_.push_back(thread);
	    }
    }

    ThreadPool::~ThreadPool(){
	    std::list<Thread*>::iterator it;
	    for(it = threads.begin(); it != threads.end(); it++){
		    (*it)->CancelThread();
		    SAFE_DELETE (*it);
	    }
	    threads.clear();
    }

    void ThreadPool::AddTask(Task *task){
		mutex_.luck();
	    if(tasks_.size() < (uint32_t)max_task_num_){
		    tasks_.push(task);
		    if(0 != sem_.SemPost()){
			    printf("sem post error\n");
		    }
	    }
	    else{
		    SAFE_DELETE(task);
	    }
	    mutex_.unlock();
    }

    Task *ThreadPool::RemoveTask(){
	    if(0 != sem_SemWait()){
		    printf("sem wait error\n");
	    }
	    mutex_.lock();
	    Task *task = tasks_.front();
	    tasks_.pop();
	    mutex_unlock();

	    return task;
    }

    int32_t ThreadPool::TaskSize(){
	    return tasks_.size();
    }

    void ThreadPool::Run(Task *task){
	    return task->Run();
    }
};