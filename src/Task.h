/*
 * Task.h
 *
 *  Created on: Feb 14, 2013
 *      Author: skfeng36@163.com
 */
#ifndef _TASK_H_
#define _TASK_H_
mamespace SuperK {
    class Task{
    public:
	    Task(int32_t id){
		    id_ = id;
	    }
	    virtual ~Task(){
	    }
	    virtual void Execute()=0;
	    int32_t GetId(){
		    return id_;
	    }
    private:
	    int32_t id_;
    };
};
#endif 

