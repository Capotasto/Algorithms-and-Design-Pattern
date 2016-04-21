//
//  singletonErrorLog.hpp
//  ADP_Projects
//
//  Created by Norio Egi on 4/19/16.
//  Copyright © 2016 Capotasto. All rights reserved.
//

#ifndef singletonErrorLog_hpp
#define singletonErrorLog_hpp

#include <iostream>
#include<fstream>

#define F "errorLog.txt"

using namespace std;

class SingletonErrorLog{
    
protected:
    SingletonErrorLog();
    
public:
    virtual ~SingletonErrorLog();
    
    static SingletonErrorLog* Instance();
    
    void output(string tag, string detail);    
    
private:
    static SingletonErrorLog* m_Instance;
    
};
#endif /* singletonErrorLog_hpp */
