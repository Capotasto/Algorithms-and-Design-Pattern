//
//  sortingExercise.cpp
//  ADP_Projects
//
//  Created by Norio Egi on 4/21/16.
//  Copyright © 2016 Capotasto. All rights reserved.
//

#include "sortingExercise.hpp"
#define STR(var) #var
#include "MySort.hpp"
#include <stdbool.h>
#include <time.h>
#include "HeapSort.hpp"
#include "QuickSort.hpp"

using std::cout;
using std::cin;
using std::endl;

const int MAX_SORT = 10;

enum sort_option{
    SELECTION,//0
    INSERTION,//1
    BUBBLE,//2
    TAG,//3
    BUCKET,//4
    INDEX,//5
    SHELL,//6
    QUICK,//7
    MERGE,//8
    HEAP//9
    
};

void showOption(){
    puts("\nPlease select your choice:\n"
         "1: Selection sort\n"
         "2: Insertion sort\n"
         "3: Bubble sort \n"
         "4: Tag sort \n"
         "5: Bucket sort \n"
         "6: Index sort\n"
         "7: Shell sort\n"
         "8: Quick sort\n"
         "9: Merge sort\n"
         "10: Heap sort\n"
);
    
}

void makeRandomArray(int *array){
    
    //srand((int)time_t(NULL));
    srand(time_t(NULL));
    int random;
    
    for (int i = 0; i < MAX_SORT; i++) {
        random = rand() % 100;
        bool isDublicated = false;
        for(int j = 0; array[j] != -1 ; j++) {
            if (array[j] == random) {
                i--;
                isDublicated = true;
                break;
            }
        }
        if (!isDublicated) {
            *(array + i) = random;
        }
    }
    
    printf("OK! You array is ...:\n");
    for (int i = 0; i < MAX_SORT; i++) {
        printf("%3d", array[i]);
    }
    puts("\n");
    
}

void sortingExercise(){
    
    int input;
    int array[MAX_SORT] = {-1};
    
    showOption();
    
    while (1) {
        cin >> input;
        if (SELECTION <= input-1 && input-1 <= HEAP) {
            break;
        }else{
            cout << "Wrong Number!" << endl;
        }
    }
    
    puts("Making Random array....");
    makeRandomArray(array);
    
    MySort mysort;
    
    switch (input-1) {
        case SELECTION:
            mysort.doSelectionSort(array, MAX_SORT);
            break;
        case INSERTION:
            mysort.doInsertionSort(array, MAX_SORT);
            break;
        case BUBBLE:
            mysort.doBubbleSort(array, MAX_SORT);
            break;
        case TAG:
            mysort.doTagSort(array, MAX_SORT);
            break;
        case BUCKET:
            mysort.doBucketSort(array);
            break;
        case INDEX:
            mysort.doIndexSort(array);
            break;
        case SHELL:
            mysort.doShellSort(array);
            break;
        case QUICK:
            mainQuickSort(array, MAX_SORT);
            break;
        case MERGE:
            mysort.doMergeSort(array);
            break;
        case HEAP:
            mainHeapSort(array, MAX_SORT);
            break;
            
            
        default:
            cout << "Somting is wrong." << endl;
            break;
    }
}