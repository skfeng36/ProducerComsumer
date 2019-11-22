/*
 * ProducerConsumer.cc
 *
 *  Created on: Feb 14, 2013
 *      Author: skfeng36@163.com
 */
#include "ProducerConsumer.h"


namespace SuperK {

   ProducerConsumer::ProducerConsumer() {
        context_=new Context();
        process_=new Process(context_->GetConfig());
    }
    ProducerConsumer::~ProducerConsumer() {
	    SAFE_DELETE(context_);
    }
    void ProducerConsumer::Init(){
	    process_->Init();
    }

};

int32_t main(int32_t argc, char * argv[]){
    SuperK::ProducerConsumer pro_con;
    pro_con.Init();


    return 0;
}

