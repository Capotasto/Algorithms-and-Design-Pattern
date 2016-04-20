//
//  Interface.hpp
//  ADP_Projects
//
//  Created by Norio Egi on 4/18/16.
//  Copyright © 2016 Capotasto. All rights reserved.
//

#ifndef Interface_hpp
#define Interface_hpp

#include <iostream>
//#include "Implementation.h"

class Implementation;

class Interface {
public:
    Interface();
    void setValue(std::string, int);
    int getValue(std::string) const;
    ~Interface();

private:
    Implementation *ptr;

};

#endif /* Interface_hpp */
