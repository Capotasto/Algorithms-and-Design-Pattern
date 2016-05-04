//
//  HeapSort.cpp
//  ADP_Projects
//
//  Created by Norio Egi on 5/3/16.
//  Copyright © 2016 Capotasto. All rights reserved.
//

#include "HeapSort.hpp"


int getParent(int index){

    return (index-1)/2;
}

int getLeftChild(int index){
    
    return 2*index+1;
}

int getRightChild(int index){
    
    return 2*index+2;
}

bool isSorted(int *array, int size){
    
    bool isSorted = true;
    
    for (int i = 0; i < size-1; i++) {
        if (array[i] > array[i+1]) {
            isSorted = false;
            break;
        }
    }
    
    return isSorted;
}

bool swapNode(int* array, int i){
    
    bool swapped = false;

    if (array[getParent(i)] > array[i]) {
        int temp = array[i];
        array[i] = array[getParent(i)];
        array[getParent(i)] = temp;
        swapped = true;
    }
    
    return swapped;

}

void makeHeap(int *array, int *resultArray, int size){
    
    for (int i = 0; i < size; i++) {
        if (array[i] > 0) {
            if(i == 0){
                resultArray[0] = array[0];
            }else if(i > 0){
                resultArray[i] = array[i];
                bool isSwapped = false;
                int index = i;
                do {
                    isSwapped = swapNode(resultArray, index);
                    index = getParent(index);
                } while (isSwapped);
            }
        }
    }
}


void mainHeapSort(int *array, const int size){
    
    int resultArray[size];
    int tempArray[size];
    int *baseArray = array;
    int i = 0;
    do {
        
        makeHeap(baseArray, tempArray, size);
        
        resultArray[i] = tempArray[0];
        //int temp = tempArray[0];
        tempArray[0] = tempArray[size-i-1];
        tempArray[size-i-1] = -1;
        i++;
        for (int j = 0; j < size; j++) {
            if (j > size-i-1) {
                baseArray[j] = -1;
            }else{
                baseArray[j] = tempArray[j];
            }
        }
        
    } while (i != size);
    
    
    for (int i = 0; i < size; i++) {
        std::cout <<resultArray[i] << " ";
    }
    std::cout << std::endl;
    
    
}