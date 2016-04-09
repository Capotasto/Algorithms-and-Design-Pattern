//
//  Assignment1.hpp
//  ADP1_Assignment1
//
//  Created by Norio Egi on 4/9/16.
//  Copyright © 2016 Capotasto. All rights reserved.
//

#ifndef Assignment1_hpp
#define Assignment1_hpp

#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

void makeGrid(void);
void showGrid(void);
bool checkTheAdjacentCells(void);
void showUserInput(void);
void chageTheAloneStonePlace(void);
void storeAloneStonePlace(int row, int col);
int checkStoneCount();
bool checkTheAdjacentCellsForGameOver();
void executeAssignment1(void);

#endif /* Assignment1_hpp */
