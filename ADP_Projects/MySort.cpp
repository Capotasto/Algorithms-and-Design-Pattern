//
//  MySort.cpp
//  ADP_Projects
//
//  Created by Norio Egi on 4/21/16.
//  Copyright © 2016 Capotasto. All rights reserved.
//

#include "MySort.hpp"
#include <stdbool.h>

MySort::MySort(){
}

MySort::~MySort(){
    
}

void MySort::doSelectionSort(int *array, int max){
    
    puts("\nSelectionSort:");
    
    for (int i = 0; i < max; i++) {
        int min = *(array+i);
        int minPosition = 0;
        for (int j= i; j < max; j++) {
            if (min > *(array+j) ) {
                min = *(array+j);
                minPosition = j;
            }
        }
        
        if (*(array+i) > min) {
            int temp = *(array+i);
            *(array+i) = min;
            *(array + minPosition) = temp;
        }
        
    }
    
    for (int i =0; i < max; i++) {
        printf("%3d", *(array+i));
    }
    puts("\n");
    
}

void MySort::doInsertionSort(int array[20], int max){
    
    puts("\nInsertionSort:");
    
    for (int i = 0; i < max-1; i++) {
        
        if (array[i] <array[i+1]) {
            continue;
        }else{
            if (i == 0) {
                //replace
                int temp = array[i+1];
                array[i+1] = array[i];
                array[i] = temp;
                break;
            }
            
            int temp = array[i+1];
            for (int j = 1; j <= i; j++) {
                if (array[i-j] < array[i+1]) {
                    for (int k = 0; k < j; k++) {
                        array[i+1-k] = array[i-k];
                    }
                    array[i-j+1] = temp;
                    break;
                }else{
                    if(i-j == 0){
                        int temp = array[i+1];
                        for (int k = 0; k <= j; k++) {
                            array[i+1-k] = array[i-k];
                        }
                        array[i-j] = temp;
                    }
                }
            }
            
            for (int i =0; i < max; i++) {
                printf("%3d", *(array+i));
            }
            puts("\n");
            
        }
    }
}

void MySort::doBubbleSort(int *array, int max){
    
    puts("\nBubbleSort:");
    
    //while (!isNeverSorted) {
    for (int j = 1; j < max; j++) {
        for (int i = 0; i < max-j; i++) {
            if (array[i] < array[i+1]) {
                continue;
            }else{
                int temp = array[i+1];
                array[i+1] = array[i];
                array[i] = temp;
            }
            
        }
        
    }
    for (int i =0; i < max; i++) {
        printf("%3d", *(array+i));
    }
    puts("\n");
    
    
}
void MySort::doTagSort(int *array, int max){
    
    //init
    int tagArray[SIZE_SORT];
    for (int i = 0 ; i < SIZE_SORT; i++) {
        tagArray[i] = -1;
    }
    
    //getMinTagArray
    for (int i = 0; i < SIZE_SORT; i++) {
        tagArray[i] = getMinimumPostion(array, tagArray);
    }
    
    //Print index
    puts("Sorted index is:");
    for (int i =0; i < SIZE_SORT; i++) {
        printf("%3d", *(tagArray+i));
        
    }
    puts("\n");
    
    //Print value
    puts("Sorted index is:");
    for (int i =0; i < SIZE_SORT; i++) {
        printf("%3d", array[*(tagArray+i)]);
        
    }
    puts("\n");

}
void MySort::doBucketSort(int *array, int max){
    
    int arrayBucket[10][10];
    for (int i = 0 ; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            arrayBucket[i][j] = -1;
        }
    }
    
    for (int i = 0; i < SIZE_SORT; i++) {
        if (array[i] < 10) {
            for (int j = 0; j < COL_SORT; j++) {
                if (arrayBucket[array[i]][j] != -1) {
                    arrayBucket[array[i]][j] = array[i];
                    break;
                }
            }
        }else{
        
        }
    }
    
    
    
}
void MySort::doIndexSort(int *array, int max){
    
}
void MySort::doShellSort(int *array, int max){
    
}

int MySort::getMinimumPostion(int *array, int *tagArray){
    
    int something = 0;
    for (int i = 0; i < SIZE_SORT; i++) {
        if (hasIndex(tagArray, i)) {
            continue;
        }else{
            something = i;
            break;
        }
    }
    
    int minPostion = something;
    for (int j = 0; j < SIZE_SORT; j++) {
        if (hasIndex(tagArray, j)) {
            continue;
        }
        if (array[minPostion] > array[j]) {
            minPostion = j;
        }
    }
    return minPostion;
    
}

bool MySort::hasIndex(int *array, int num){
    
    for (int i = 0; *(array + i) != -1; i++) {
        if (array[i] == num) {
            return true;
        }
    }
    return false;
    
}
