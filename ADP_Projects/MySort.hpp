//
//  MySort.hpp
//  ADP_Projects
//
//  Created by Norio Egi on 4/21/16.
//  Copyright © 2016 Capotasto. All rights reserved.
//

#ifndef MySort_hpp
#define MySort_hpp

#include <iostream>

#endif /* MySort_hpp */

const int SIZE_SORT = 20;
const int ROW_SORT = 10;
const int COL_SORT = 10;

class MySort{
public:
    MySort();
    void doSelectionSort(int *, int);
    void doInsertionSort(int *, int );
    void doBubbleSort(int *, int );
    void doTagSort(int *, int);
    void doBucketSort(int *);
    void doIndexSort(int *);
    void doShellSort(int *);
    void doQuickSort(int *);
    void doMergeSort(int *);
    void doHeapSort(int *);
    ~MySort();

private:
    void searchPivot(int *array, int size, int *resultArray);
    void addToBucket(int *array, int arrayBucket[ROW_SORT][COL_SORT], int digit, int index);
    void backToArray(int arrayBucket[ROW_SORT][COL_SORT], int *array);
    int getMinimumPostion(int *array, int *tagArray);
    bool hasIndex(int *array, int num);
    void mergeTwoElements(int *array);
};