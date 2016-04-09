//
//  Assignment1.cpp
//  ADP1_Assignment1
//
//  Created by Norio Egi on 4/9/16.
//  Copyright © 2016 Capotasto. All rights reserved.
//

#include "Assignment1.hpp"

const int ROW_NUM = 16;
const int COLUMN_NUM = 16;
const int STONE_NUM = 100;

int rowOfAloneStone = 0;
int colOfAloneStone = 0;

string gridArray[ROW_NUM][COLUMN_NUM];

void makeGrid(void){
    
    //Initialisze Stone plce
    int stoneCount = 0;
    while (stoneCount <= STONE_NUM) {
        int row = rand() % ROW_NUM;
        int col = rand() % COLUMN_NUM;
        
        if (gridArray[row][col].compare("") == 0) {
            gridArray[row][col] = " X";
            stoneCount++;
        }
    }
    
    bool isStoneFilledPerfectly = false;
    
    while(!isStoneFilledPerfectly){
        if(checkTheAdjacentCells()){
            isStoneFilledPerfectly = true;
        }else{
            chageTheAloneStonePlace();
        }
    }
    
    //Initialize data
    //int z = 0;
    for (int i = 0; i < ROW_NUM; i++) {
        for (int j = 0; j < COLUMN_NUM; j++) {
            
            if (gridArray[i][j].compare("") == 0) {
                gridArray[i][j] = " *";
                
            }
        }
    }
    
}

void showGrid(){
    //output
    for (int i = 0; i < ROW_NUM; i++) {
        if(i == 0){
            printf("xx 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16\n");
        }
        
        for (int j = 0; j < COLUMN_NUM; j++) {
            
            if (j == 0) {
                printf("%02d ", i+1);
            }
            printf("%s ", gridArray[i][j].c_str());
            
            if (j == COLUMN_NUM-1) {
                printf("\n");
            }
        }
    }
}

void chageTheAloneStonePlace(){
    for (int i = 0; i < ROW_NUM; i++) {
        for (int j = 0; j < COLUMN_NUM; j++) {
            
            if (gridArray[i][j].compare("") == 0) {
                gridArray[i][j] = gridArray[rowOfAloneStone][colOfAloneStone];
                gridArray[rowOfAloneStone][colOfAloneStone] = " *";
                goto LABEL;
            }
        }
    }
LABEL:;
}

void storeAloneStonePlace(int row, int col){
    rowOfAloneStone = row;
    colOfAloneStone = col;
}

bool checkTheAdjacentCells(){
    
    for (int i = 0; i < ROW_NUM; i++) {
        for (int j = 0; j < COLUMN_NUM; j++) {
            if(gridArray[i][j].compare(" X") == 0){
                
                if (i == 0 && j == 0) {
                    if(gridArray[i+1][j].compare(" X") != 0 && gridArray[i][j+1].compare(" X") != 0){
                        storeAloneStonePlace(i,j);
                        return false;
                    }
                    
                }else if(i == ROW_NUM-1 && j == 0){
                    if(gridArray[i-1][j].compare(" X") != 0 && gridArray[i][j+1].compare(" X") != 0){
                        storeAloneStonePlace(i,j);
                        return false;
                    }
                    
                }else if(i == 0 && j == COLUMN_NUM-1){
                    if(gridArray[i+1][j].compare(" X") != 0 && gridArray[i][j-1].compare(" X") != 0){
                        storeAloneStonePlace(i,j);
                        return false;
                    }
                    
                }else if(i == ROW_NUM-1 && j == COLUMN_NUM-1){
                    if(gridArray[i-1][j].compare(" X") != 0 && gridArray[i][j-1].compare(" X") != 0){
                        storeAloneStonePlace(i,j);
                        return false;
                    }
                }else if(i == 0 && j != 0 && j != COLUMN_NUM-1){
                    if(gridArray[i][j-1].compare(" X") != 0 && gridArray[i][j+1].compare(" X") != 0 && gridArray[i+1][j].compare(" X") != 0){
                        storeAloneStonePlace(i,j);
                        return false;
                    }
                    
                }else if(i == ROW_NUM-1 && j != 0 && j != COLUMN_NUM-1){
                    if(gridArray[i][j-1].compare(" X") != 0 && gridArray[i][j+1].compare(" X") != 0 && gridArray[i-1][j].compare(" X") != 0){
                        storeAloneStonePlace(i,j);
                        return false;
                    }
                    
                }else if(i != 0 && i != ROW_NUM-1 && j ==0){
                    if(gridArray[i-1][j].compare(" X") != 0 && gridArray[i+1][j].compare(" X") != 0 && gridArray[i][j+1].compare(" X") != 0){
                        storeAloneStonePlace(i,j);
                        return false;
                    }
                    
                }else if(i != 0 && i != ROW_NUM-1 && j ==COLUMN_NUM-1){
                    if(gridArray[i+1][j].compare(" X") != 0 && gridArray[i+1][j].compare(" X") != 0 && gridArray[i][j-1].compare(" X") != 0){
                        storeAloneStonePlace(i,j);
                        return false;
                    }
                    
                }else{
                    if(gridArray[i][j-1].compare(" X") != 0 && gridArray[i][j+1].compare(" X") != 0 &&
                       gridArray[i-1][j].compare(" X") != 0 && gridArray[i+1][j].compare(" X") != 0 ){
                        storeAloneStonePlace(i,j);
                        return false;
                    }
                }
            }
        }
    }
    
    return true;
}
//TODO
bool checkTheAdjacentCellsForGameOver(){
    
    for (int i = 0; i < ROW_NUM; i++) {
        for (int j = 0; j < COLUMN_NUM; j++) {
            if(gridArray[i][j].compare(" X") == 0){
                
                if (i == 0 && j == 0) {
                    if(gridArray[i+1][j].compare(" X") == 0 || gridArray[i][j+1].compare(" X") == 0){
                        return false;
                    }
                    
                }else if(i == ROW_NUM-1 && j == 0){
                    if(gridArray[i-1][j].compare(" X") == 0 || gridArray[i][j+1].compare(" X") == 0){
                        return false;
                    }
                    
                }else if(i == 0 && j == COLUMN_NUM-1){
                    if(gridArray[i+1][j].compare(" X") == 0 || gridArray[i][j-1].compare(" X") == 0){
                        return false;
                    }
                    
                }else if(i == ROW_NUM-1 && j == COLUMN_NUM-1){
                    if(gridArray[i-1][j].compare(" X") == 0 || gridArray[i][j-1].compare(" X") == 0){
                        return false;
                    }
                }else if(i == 0 && j != 0 && j != COLUMN_NUM-1){
                    if(gridArray[i][j-1].compare(" X") == 0 || gridArray[i][j+1].compare(" X") == 0 || gridArray[i+1][j].compare(" X") == 0){
                        return false;
                    }
                    
                }else if(i == ROW_NUM-1 && j != 0 && j != COLUMN_NUM-1){
                    if(gridArray[i][j-1].compare(" X") == 0 || gridArray[i][j+1].compare(" X") == 0 || gridArray[i-1][j].compare(" X") == 0){
                        return false;
                    }
                    
                }else if(i != 0 && i != ROW_NUM-1 && j ==0){
                    if(gridArray[i-1][j].compare(" X") == 0 || gridArray[i+1][j].compare(" X") == 0 || gridArray[i][j+1].compare(" X") == 0){
                        return false;
                    }
                    
                }else if(i != 0 && i != ROW_NUM-1 && j ==COLUMN_NUM-1){
                    if(gridArray[i+1][j].compare(" X") == 0 || gridArray[i+1][j].compare(" X") == 0 || gridArray[i][j-1].compare(" X") == 0){
                        return false;
                    }
                    
                }else{
                    if(gridArray[i][j-1].compare(" X") == 0 || gridArray[i][j+1].compare(" X") == 0 ||
                       gridArray[i-1][j].compare(" X") == 0 || gridArray[i+1][j].compare(" X") == 0 ){
                        storeAloneStonePlace(i,j);
                        return false;
                    }
                }
            }
        }
    }
    
    return true;
}


void showUserInput(void){
    
    int rowNumForCurrent = 0;
    int colNumForCurrent = 0;
    int rowNumForNext = 0;
    int colNumForNext = 0;
    
    bool isStone = false;
    while (!isStone) {
        printf("\nEnter the Row Number of Current Stone that you wanna move : ");
        scanf("%d", &rowNumForCurrent);
        printf("\nEnter the Column Number of Current Stone that you wanna move : ");
        scanf("%d", &colNumForCurrent);
        
        if (rowNumForCurrent == -1 || colNumForCurrent == -1) {
            continue;
        }
        
        rowNumForCurrent -= 1;
        colNumForCurrent -= 1;
        
        if (gridArray[rowNumForCurrent][colNumForCurrent].compare(" X") ==0) {
            isStone = true;
        }else{
            printf("Wrong place!!! Try Again!!");
        }
    }
    
    bool isCorrectPlace = false;
    while (!isCorrectPlace) {
        printf("\nEnter the Row Number of Place that you wanna move the stone : ");
        scanf("%d", &rowNumForNext);
        printf("\nEnter the Column Number of Place that you wanna move the stone : ");
        scanf("%d", &colNumForNext);
        
        rowNumForNext -= 1;
        colNumForNext -= 1;
        
        if (gridArray[rowNumForNext][colNumForNext].compare(" *") == 0) {
            if(rowNumForCurrent == rowNumForNext){
                if (colNumForCurrent < colNumForNext) {
                    if (gridArray[rowNumForNext][colNumForNext-1].compare(" X") == 0) {
                        gridArray[rowNumForCurrent][colNumForCurrent] = " *";
                        gridArray[rowNumForNext][colNumForNext-1] = " *";
                        gridArray[rowNumForNext][colNumForNext] = " X";
                        isCorrectPlace = true;
                        
                    }else{
                        printf("Wrong place!!! Try Again!!");
                    }
                }else{
                    if (gridArray[rowNumForNext][colNumForNext+1].compare(" X") == 0) {
                        gridArray[rowNumForCurrent][colNumForCurrent] = " *";
                        gridArray[rowNumForNext][colNumForNext+1] = " *";
                        gridArray[rowNumForNext][colNumForNext] = " X";
                        isCorrectPlace = true;
                        
                    }else{
                        printf("Wrong place!!! Try Again!!");
                    }
                }
                
            }else if(colNumForCurrent == colNumForNext){
                
                if (rowNumForCurrent < rowNumForNext) {
                    if (gridArray[rowNumForNext-1][colNumForNext].compare(" X") == 0) {
                        gridArray[rowNumForCurrent][colNumForCurrent] = " *";
                        gridArray[rowNumForNext-1][colNumForNext] = " *";
                        gridArray[rowNumForNext][colNumForNext] = " X";
                        isCorrectPlace = true;
                        
                        
                    }else{
                        printf("Wrong place!!! Try Again!!");
                    }
                }else{
                    if (gridArray[rowNumForNext+1][colNumForNext].compare(" X") == 0) {
                        gridArray[rowNumForCurrent][colNumForCurrent] = " *";
                        gridArray[rowNumForNext+1][colNumForNext] = " *";
                        gridArray[rowNumForNext][colNumForNext] = " X";
                        isCorrectPlace = true;
                        
                    }else{
                        printf("Wrong place!!! Try Again!!");
                    }
                }
            }
            
        }else{
            printf("Wrong place!!! Try Again!!");
        }
        
    }
}

int checkStoneCount(){
    
    int stoneCount = 0;
    
    for (int i = 0; i < ROW_NUM; i++) {
        for (int j = 0; j < COLUMN_NUM; j++) {
            if(gridArray[i][j].compare(" X") == 0){
                stoneCount++;
            }
        }
    }
    
    return stoneCount;
}

void executeAssignment1(void){
    makeGrid();
    showGrid();
    while (!checkTheAdjacentCellsForGameOver()) {
        showUserInput();
        printf("\n");
        showGrid();
        printf("\n");
    }
    
    printf("Game Over!!! Your stones are %d!!!\n", checkStoneCount());
}


