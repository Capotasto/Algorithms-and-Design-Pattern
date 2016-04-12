//
//  stdLibraryClass.cpp
//  ADP_Projects
//
//  Created by Norio Egi on 4/11/16.
//  Copyright © 2016 Capotasto. All rights reserved.
//

#include "stdLibraryClass.hpp"

void mainStdLibraryCalss(){
    
    cout << "Enter first integers: ";
    istream_iterator<int> inputInt(cin);
    
    int number1, number2;
    number1 = *inputInt; // read first int from standard input
    ++inputInt; // move iterator to next input value
    
    cout << "Enter second integers: ";
    number2 = *inputInt; // read next int from standard input
    
    cout << "The sum is: ";
    ostream_iterator< int > outputInt( cout );
    
    *outputInt = number1 + number2; // output result to cout
    
    cout << endl;

}