//
//  exerSingleton.cpp
//  ADP_Projects
//
//  Created by Norio Egi on 4/19/16.
//  Copyright © 2016 Capotasto. All rights reserved.
//

#include "exerSingleton.hpp"
#include "singletonErrorLog.hpp"

void exerSingleton(){
    
    SingletonErrorLog *pSystemSingleton;
    SingletonErrorLog *pUserSingleton;
    pSystemSingleton = SingletonErrorLog::Instance();
    pUserSingleton = SingletonErrorLog::Instance();
    
    pSystemSingleton->output("SYSTEM", "Fatail Error!!!");
    pSystemSingleton->output("USER", "Password Error!!!");
    
    
}