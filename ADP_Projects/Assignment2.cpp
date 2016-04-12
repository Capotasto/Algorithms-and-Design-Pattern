//
//  Assignment2.cpp
//  ADP_Projects
//
//  Created by Norio Egi on 4/11/16.
//  Copyright © 2016 Capotasto. All rights reserved.
//

#include "Assignment2.hpp"

using std::cout;
using std::cin;

void printOptions(void){

    //Print options
    cout << "Choose the option number below\n";
    cout << "1. Demonstrating Vectors\n";
    cout << "2. Demonstrating Lists\n";
    cout << "3. Demonstrating Deques\n";
    cout << "4. Demonstrating Maps\n";
    cout << "5. Demonstrating MultiMaps\n";
    cout << "6. Demonstrating Sets\n";
    cout << "7. Demonstrating Multisets\n";
    cout << "8. Demonstrating Stacks\n";
    cout << "9. Demonstrating Queues\n";
    cout << "10. Demonstrating Priority Queues\n";

}

enum optionNum{
    VECTORS,//0
    LISTS,//1
    DEQUES,//2
    MAPS,//3
    MULTI_MAPS,//4
    SETS,//5
    MULTI_SETS,//6
    STACKS,//7
    QUEUES,//8
    PRIORITY_QUEUES//9

};


void mainAssignment2(void){
    
    int inputNum;

    //Print options
    printOptions();
    
    //Input the number
    cin >> inputNum;
    
    //printf("%d", inputNum);
    
    switch (inputNum-1) {
        case VECTORS:
            
            
            break;
        case LISTS:
            break;

        case DEQUES:
            
            break;

        case MAPS:
            break;

        case MULTI_MAPS:
            
            break;

        case SETS:
            
            break;

        case MULTI_SETS:
            
            break;

        case STACKS:
            
            break;

        case QUEUES:
            
            break;

        case PRIORITY_QUEUES:
            
            break;
            
        default:
            cout << "That's wrong number.\n";
            break;
    }

}