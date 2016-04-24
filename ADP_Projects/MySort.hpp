//
//  MySort.hpp
//  ADP_Projects
//
//  Created by Norio Egi on 4/21/16.
//  Copyright © 2016 Capotasto. All rights reserved.
//

#ifndef MySort_hpp
#define MySort_hpp

#include <stdio.h>

#endif /* MySort_hpp */

const int SIZE_SORT = 5;
const int ROW_SORT = 10;
const int COL_SORT = 10;

class MySort{
public:
    MySort();
    void doSelectionSort(int *, int);
    void doInsertionSort(int *, int );
    void doBubbleSort(int *, int );
    void doTagSort(int *, int);
    void doBucketSort(int *, int );
    void doIndexSort(int *, int );
    void doShellSort(int *, int );
    ~MySort();

private:
    int getMinimumPostion(int *array, int *tagArray);
    bool hasIndex(int *array, int num);
};