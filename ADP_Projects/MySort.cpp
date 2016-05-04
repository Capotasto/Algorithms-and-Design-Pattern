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

/**
 doBulleSort
 */
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

/**
 doTagSort
 */
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

/**
 doBucketSort
 */
void MySort::doBucketSort(int *array){
    
    int arraySorted[SIZE_SORT];
    int arrayBucket[ROW_SORT][COL_SORT];
    
    //init
    for (int i = 0 ; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            arrayBucket[i][j] = -1;
        }
    }
    
    //addBucket ones
    for (int i = 0;  i < SIZE_SORT; i++) {
        int temp = *(array+i) % 10;
        addToBucket(array, arrayBucket, temp ,i);
    }
    
    //Back to SortedArray.
    backToArray(arrayBucket, arraySorted);
    
    //Init
    for (int i = 0 ; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            arrayBucket[i][j] = -1;
        }
    }
    
    //addBucket tens
    for (int i = 0;  i < SIZE_SORT; i++) {
        int temp = *(arraySorted+i) / 10;
        addToBucket(arraySorted, arrayBucket, temp ,i);
    }
    
    backToArray(arrayBucket, arraySorted);
    
    
    for (int i = 0 ; i < SIZE_SORT; i++) {
        printf("arraySorted[%d] = %d\n", i , arraySorted[i]);
    }
    
}

/**
 doIndexSort
 */
void MySort::doIndexSort(int *array){
    
    int arrayIndex[ROW_SORT * COL_SORT];
    
    //init
    for (int i = 0 ; i < ROW_SORT * COL_SORT; i++) {
        for (int j = 0; j < SIZE_SORT; j++) {
            if (i == *(array + j)) {
                arrayIndex[i] = *(array+ j);
                break;
            }else{
                arrayIndex[i] = -999;
            }
        }
    }
    
    //print
    for (int i = 0 ; i < ROW_SORT * COL_SORT; i++) {
        if (arrayIndex[i] != -999) {
            printf("%2d ", arrayIndex[i]);
        }
    }
    puts("");
}

void MySort::doShellSort(int *array){
    
    int count = 1;
    while (1) {
        int space = SIZE_SORT /(2*count);
        if (space == 1 ) {
            break;
        }
        
        for(int i = 0; i + space < SIZE_SORT ; i++) {
            if (*(array + i) > *(array+i+space)) {
                int temp = *(array+i+space);
                *(array+i+space) = *(array + i);
                *(array + i) = temp;
            }
        }
        //print
        for (int i = 0 ; i < SIZE_SORT; i++) {
            printf("%3d ", array[i]);
        }
        puts("");
        count++;
    }
    
    doInsertionSort(array, SIZE_SORT);
    
    //print
    for (int i = 0 ; i < SIZE_SORT; i++) {
        printf("%3d ", array[i]);
    }
    puts("");
    
    
}

void MySort::doQuickSort(int *array){
    
    int resultArray[SIZE_SORT];
    
    searchPivot(array, SIZE_SORT, resultArray);
    
    for (int i = 0 ; i < SIZE_SORT; i++) {
        printf("resultArray[%d] = %d\n",i, *(resultArray+i));
    }
}


void MySort::doMergeSort(int *array){
    
    mergeTwoElements(array);
    
}



void MySort::mergeTwoElements(int *array){
    
    int mergeMax = 2;
    int count = SIZE_SORT/mergeMax;
    int subArray1[2];
    int subArray2[2];
    
    for (int i = 0; i < count; i++) {
        subArray1[0] = *(array + mergeMax*i);
        subArray1[1] = *(array + mergeMax*i+1);
        subArray2[0] = *(array + mergeMax*i+2);
        subArray2[1] = *(array + mergeMax*i+3);
        
        if (subArray1[0] > subArray1[1]) {
            int temp = subArray1[1];
            subArray1[1] = subArray1[0];
            subArray1[0] = temp;
        }
        
        if (subArray2[0] > subArray2[1]) {
            int temp = subArray2[1];
            subArray2[1] = subArray2[0];
            subArray2[0] = temp;
        }
        
        //merge
        if(subArray1[0] < subArray2[0]){
            if(subArray2[0] < subArray1[1]){
                if(subArray1[1] < subArray2[1]){
                    *(array + mergeMax*i) = subArray1[0];
                    *(array + mergeMax*i+1) = subArray2[0];
                    *(array + mergeMax*i+2) = subArray1[1];
                    *(array + mergeMax*i+3) = subArray2[1];
                }else if(subArray1[1] > subArray2[1]){
                    *(array + mergeMax*i) = subArray1[0];
                    *(array + mergeMax*i+1) = subArray2[0];
                    *(array + mergeMax*i+2) = subArray2[1];
                    *(array + mergeMax*i+3) = subArray1[1];
                }
            }else if(subArray2[0] > subArray1[1]){{
                if(subArray2[0] < subArray2[1]){
                    *(array + mergeMax*i) = subArray1[0];
                    *(array + mergeMax*i+1) = subArray1[1];
                    *(array + mergeMax*i+2) = subArray2[0];
                    *(array + mergeMax*i+3) = subArray2[1];
                }else if(subArray2[0] > subArray2[1]){
                    *(array + mergeMax*i) = subArray1[0];
                    *(array + mergeMax*i+1) = subArray1[1];
                    *(array + mergeMax*i+2) = subArray2[1];
                    *(array + mergeMax*i+3) = subArray2[0];
                }
            }
        }else if(subArray1[0] > subArray2[0]){
            if(subArray1[0] > subArray2[1]){
                if (subArray1[0] > subArray1[1]) {
                    *(array + mergeMax*i) = subArray1[0];
                    *(array + mergeMax*i+1) = subArray2[0];
                    *(array + mergeMax*i+2) = subArray1[1];
                    *(array + mergeMax*i+3) = subArray2[1];
                }
            }else if(subArray1[0] < subArray2[1]){
                
            }
        }
    }
    

    }
}

void MySort::searchPivot(int *array, int size, int *resultArray){
    
    int pivot = *array;
    
    int size1 = 0, size2 =0;
    
    int *array1 = (int *)malloc(size1 * sizeof(int));
    int *array2 = (int *)malloc(size2 * sizeof(int));
    
    for (int i = 1; i < size; i++) {
        
        if (*(array + i) <= pivot) {
            size1++;
            array1 = (int *)realloc(array1, size1 * sizeof(int));
            if (array1 == NULL) {
                puts("Pointer Exception array1");
                exit(0);
            }
            *(array1+size1-1) = *(array + i);
            printf("*(array1 + %d ) = %d\n", size1-1, *(array1+size1-1));
            
            
        }else{
            size2++;
            array2 = (int *)realloc(array2, size2 * sizeof(int));
            if (array2 == NULL) {
                puts("Pointer Exception array2");
                exit(0);
            }
            *(array2+size2-1) = *(array + i);
            printf("*(array2 + %d ) = %d\n", size2-1, *(array2+size2-1));
        }
    }
    
    int *resultArray1 = NULL;
    if (size1 > 1) {
        resultArray1 = (int*)malloc(size1 * sizeof(int));
        if (resultArray1 == NULL) {
            puts("Pointer Exception resultArray1");
            exit(0);
        }
        searchPivot(array1, size1, resultArray1);
    }else{
        resultArray1 = array1;
    }
    
    int *resultArray2 = NULL;
    if (size2 > 1) {
        resultArray2 = (int*)malloc(size2 * sizeof(int));
        if (resultArray2 == NULL) {
            puts("Pointer Exception resultArray2");
            exit(0);
        }
        searchPivot(array2, size2, resultArray2);
    }else{
        resultArray2 = array2;
    }
    
    int j = 0;
    for (int i = 0 ; i < size; i++) {
        if (i < size1) {
            *(resultArray+i) = *(resultArray1 + i);
        }else if(i == size1 ){
            *(resultArray+i) = pivot;
        }else if(size1 < i){
            *(resultArray+i) = *(resultArray2 + j);
            j++;
        }
    }
    
    free(array1);
    free(array2);
    if (size1 > 1) {
        free(resultArray1);
    }
    if (size2 > 1) {
        free(resultArray2);
    }
}


void MySort::addToBucket(int *array, int arrayBucket[ROW_SORT][COL_SORT], int digit, int index){
    
    for (int i = 0; i < COL_SORT; i++) {
        if(arrayBucket[digit][i] != -1){
            continue;
        }else{
            arrayBucket[digit][i] = *(array + index);
            break;
        }
    }
}

void MySort::backToArray(int arrayBucket[ROW_SORT][COL_SORT], int *array){
    int k = 0;
    for (int i = 0; i < ROW_SORT; i++) {
        for (int j = 0; j< COL_SORT; j++) {
            if (arrayBucket[i][j] != -1) {
                array[k] = arrayBucket[i][j];
                k++;
            }else{
                break;
            }
        }
    }
    
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
