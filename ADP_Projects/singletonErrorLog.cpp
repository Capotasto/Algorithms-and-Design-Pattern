//
//  singletonErrorLog.cpp
//  ADP_Projects
//
//  Created by Norio Egi on 4/19/16.
//  Copyright © 2016 Capotasto. All rights reserved.
//

#include "singletonErrorLog.hpp"

SingletonErrorLog* SingletonErrorLog::m_Instance = 0;


SingletonErrorLog::SingletonErrorLog()
{
    
}

SingletonErrorLog::~SingletonErrorLog()
{
    
}

SingletonErrorLog* SingletonErrorLog::Instance()
{
    if (m_Instance == 0)
        m_Instance = new SingletonErrorLog;
    
    return m_Instance;
}

void SingletonErrorLog::output(string tag, string detail) {
    ofstream outputfile(F, ios::app);
    outputfile << tag <<", "<<detail << endl;
    cout << "Output has done!!! "<< F << endl;
    outputfile.close();
}