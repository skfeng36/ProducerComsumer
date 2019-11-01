/*
 * Thread.h
 *
 *  Created on: Feb 14, 2013
 *      Author: skfeng36@163.com
 */

#ifndef _THREADPOLL_H_
#define _THREADPOLL_H_

#include <stdio.h>
#include <list>
#include <queue>
#include <semaphore.h>

#include "Thread.h"
#include "Task.h"
#include "Mutex.h"
#include "Semaphore.h"
namespace SuperK {
    class ThreadPool {
    public:

	static void *Func(void *);

	ThreadPool(int32_t MaxThreadNum, int32_t MaxTaskNum = 1024);

	virtual ~ThreadPool();

	void AddTask(Task *task);

	Task *RemoveTask();

	void Run(Task *task);

	int32_t TaskSize();

private:

	std::queue<Task *> TaskQueue;
	std::list<Thread*> thread_pool;
	int32_t max_task_num_;
	Semaphore sem_;
	Mutex mutex_;
};

};
#endif
