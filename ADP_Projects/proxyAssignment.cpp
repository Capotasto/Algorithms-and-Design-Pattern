//
//  proxyAssignment.cpp
//  ADP_Projects
//
//  Created by Norio Egi on 4/18/16.
//  Copyright © 2016 Capotasto. All rights reserved.
//

#include "proxyAssignment.hpp"

using std::cout;
using std::endl;

#include "interface.h"

void proxyAssignment(){
    
    Interface i;
    
    std::string name1;
    int balance;
    
    puts("Enter the name!");
    std::cin >> name1;
    
    cout << "Interface contains: " << i.getValue(name1) << " before setValue" << endl;
 
    puts("How match money do you wwant!?");
    std::cin >> balance;
    
    i.setValue(name1, balance);
    
    int after;
    
    after = i.getValue(name1);
    
    cout << "Interface contains: " << after << " after setValue" << endl;

}