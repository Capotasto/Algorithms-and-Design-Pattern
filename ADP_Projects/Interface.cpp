//
//  Interface.cpp
//  ADP_Projects
//
//  Created by Norio Egi on 4/18/16.
//  Copyright © 2016 Capotasto. All rights reserved.
//

#include "Interface.h"
#include "Implementation.h"

Interface::Interface()
: ptr(new Implementation()){}

// call Implementation's setValue function
void Interface::setValue(std::string name, int v){
    ptr -> setValue(name, v);
}

// call Implementation's getValue function
int Interface::getValue(std::string name) const {
    return ptr->getValue(name);
}

Interface::~Interface() { delete ptr; }
