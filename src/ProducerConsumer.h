/*
 * ProducerConsumer.h
 *
 *  Created on: Feb 14, 2013
 *      Author: skfeng36@163.com
 */


#ifndef _PRODUCERCONSUMER_H_H
#define _PRODUCERCONSUMER_H_H

#include <unistd.h>
#include <stdint.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include "Context.h"
#include "Util.h"
#include "Process.h"

namespace SuperK {

    class ProducerConsumer {
    public:
	    ProducerConsumer();
	    virtual ~ProducerConsumer();

            virtual void Init();

    private:
            Context * context_;
            Process * process_;
            
    };
};

#endif
