//
//  Implementation.h
//  ADP_Projects
//
//  Created by Norio Egi on 4/18/16.
//  Copyright © 2016 Capotasto. All rights reserved.
//

#ifndef Implementation_h
#define Implementation_h

#include <iostream>
#include <map>

class Implementation{
public:
    Implementation() {
        init();
    }
    void setValue(std::string name, int v){
        updateBalance(name, v);
    }
    int getValue(std::string name){
        return search(name);
    }
    
private:
    std::map<std::string, int> clientMap;
    
    int search(std::string name){
        
        int result = -1;
        std::map<std::string, int>::iterator it = clientMap.begin();
        
        while (it != clientMap.end()) {
            if (((std::string)(*it).first).compare(name) == 0) {
                return (*it).second;
            }
        }
        return result;
    }
    
    void updateBalance(std::string name, int v){
        if (search(name) > 0) {
            clientMap[name] = v;
        }else{
            puts("Wrong Number.");
        }
    }
    
    void init(){
        clientMap.insert(std::map<std::string, int>::value_type("Andy", 100));
        clientMap.insert(std::map<std::string, int>::value_type("Bob", 500));
        clientMap.insert(std::map<std::string, int>::value_type("Candy", 1000));
        clientMap.insert(std::map<std::string, int>::value_type("Dan", 4000));
        clientMap.insert(std::map<std::string, int>::value_type("Eddie", 100));
        clientMap.insert(std::map<std::string, int>::value_type("Frank", 500));
        clientMap.insert(std::map<std::string, int>::value_type("Greg", 1000));
        clientMap.insert(std::map<std::string, int>::value_type("Henry", 4000));
        clientMap.insert(std::map<std::string, int>::value_type("Ian", 100));
        clientMap.insert(std::map<std::string, int>::value_type("Jessy", 500));
 
    }


};

#endif /* Implementation_h */
