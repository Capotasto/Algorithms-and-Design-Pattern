//
//  ternaryTree.cpp
//  ADP_Projects
//
//  Created by Norio Egi on 4/20/16.
//  Copyright © 2016 Capotasto. All rights reserved.
//

#include "ternaryTree.hpp"
#include "Tree.hpp"

void ternaryTree(){
    
    Tree<int> intTree;
    
    int input;
    cout << "Enter the lot size (It should be 1 ~ 100)." << endl;
    cin >> input;
    
    //int lotArray[input];
    
    for (int i = 0; i < input; i++) {
        int rand = std::rand() % input + 1;
        printf("%d, ", rand);
        const int cons = rand;
        intTree.insertNode(cons);
    }
    puts("\n");
    
    cout << "\nPreorder traversal\n";
    intTree.preOrderTraversal();
    
    cout << "\nInorder traversal\n";
    intTree.inOrderTraversal();
    
    cout << "\nPostorder traversal\n";
    intTree.postOrderTraversal();
    
    cout << "\n";
}
