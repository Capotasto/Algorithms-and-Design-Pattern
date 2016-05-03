//
//  stdVectors.cpp
//  ADP_Projects
//
//  Created by Norio Egi on 4/11/16.
//  Copyright © 2016 Capotasto. All rights reserved.
//

#include "stdVectors.hpp"

void mainStdVectors(){
    
    const int SIZE = 6;
    int a[SIZE] = { 1, 2, 3, 4, 5, 6 };
    
    std::vector< int > v;
    std::cout << "The initial size of v is: " << v.size()
    << "\nThe initial capacity of v is: " << v.capacity();
    
    v.push_back(2); // method push_back() is in
    v.push_back(3); //every sequence collection
    v.push_back(4);
    
    std::cout << "\nThe size of v is: " << v.size()
    << "\nThe capacity of v is: " << v.capacity();
    
    std::cout << "\n\nContents of array a using pointer notation: ";
    
    for (int *ptr = a; ptr != a + SIZE ; ptr++) {
        std::cout << *ptr << ' ';
        std::cout << "\nContents of vector v using iterator notation: ";
        printVector(v);
        
        std::cout << "\nReversed contents of vector v: ";
        std::vector< int >::reverse_iterator p2;
        for ( p2 = v.rbegin(); p2 != v.rend(); ++p2 ) std::cout << *p2 << ' ';
        std::cout << std::endl;
    }
}

template <class T>
void printVector( const std::vector< T > &vec ) {
    typename std::vector<T>::const_iterator p1;
    for ( p1 = vec.begin(); p1 != vec.end(); p1++ ){
     std::cout << *p1 << ' ';
    }
}