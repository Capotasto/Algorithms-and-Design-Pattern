//
//  Tree.hpp
//  ADP_Projects
//
//  Created by Norio Egi on 4/20/16.
//  Copyright © 2016 Capotasto. All rights reserved.
//

#ifndef Tree_hpp
#define Tree_hpp

#include <iostream>
#include <new>
#include "Treenode.h"

using std::endl;
using std::cout;

template< class NODETYPE >
class Tree {
    
public:
    Tree();
    void insertNode( const NODETYPE & );
    void preOrderTraversal() const;
    void inOrderTraversal() const;
    void postOrderTraversal() const;
    virtual ~Tree();
    
private:
    TreeNode< NODETYPE > *rootPtr;
    
    // utility functions
    void insertNodeHelper( TreeNode< NODETYPE > **, const NODETYPE & );
    void preOrderHelper( TreeNode< NODETYPE > * ) const;
    void inOrderHelper( TreeNode< NODETYPE > * ) const;
    void postOrderHelper( TreeNode< NODETYPE > * ) const;
    
}; // end class Tree

// constructor
template< class NODETYPE >
Tree< NODETYPE >::Tree(){
    rootPtr = 0;
}

template< class NODETYPE >
Tree<NODETYPE>::~Tree(){
    
}

// insert node in Tree
template< class NODETYPE >
void Tree< NODETYPE >::insertNode( const NODETYPE &value ){
    insertNodeHelper( &rootPtr, value );
    
}

// begin preorder traversal of Tree
template< class NODETYPE >
void Tree< NODETYPE >::preOrderTraversal() const{
    preOrderHelper( rootPtr );
    
}

// begin inorder traversal of Tree
template< class NODETYPE >
void Tree< NODETYPE >::inOrderTraversal() const{
    inOrderHelper( rootPtr );
    
}

// begin postorder traversal of Tree
template< class NODETYPE >
void Tree< NODETYPE >::postOrderTraversal() const{
    postOrderHelper( rootPtr );
    
}


// utility function called by insertNode; receives a pointer
// to a pointer so that the function can modify pointer's value
template< class NODETYPE >
void Tree< NODETYPE >::insertNodeHelper(TreeNode< NODETYPE > **ptr, const NODETYPE &value ){
    // subtree is empty; create new TreeNode containing value
    if ( *ptr == 0 ){
        *ptr = new TreeNode< NODETYPE >( value );
        
    }else{
        
        // data to insert is less than data in current node
        if ( value < (*ptr)->data ){
            insertNodeHelper( &((*ptr) -> leftPtr), value );
            
        }else if(value > (*ptr)->data ){
            insertNodeHelper( &((*ptr)->rightPtr), value );
            
        }else if (value == (*ptr)->data){
            insertNodeHelper(&((*ptr)->middlePtr), value);
            
        }
    }
    
}

template< class NODETYPE >
void Tree< NODETYPE >::preOrderHelper(TreeNode< NODETYPE > *ptr ) const{
    if ( ptr != 0 ) {
        cout << ptr->data << ' ';         // process node
        preOrderHelper( ptr->leftPtr );   // go to left subtree
        preOrderHelper( ptr->middlePtr );
        preOrderHelper( ptr->rightPtr );  // go to right subtree
        
    }
}

// utility function to perform inorder traversal of Tree
template< class NODETYPE >
void Tree< NODETYPE >::inOrderHelper(TreeNode< NODETYPE > *ptr ) const{
    if ( ptr != 0 ) {
        inOrderHelper( ptr->leftPtr );   // go to left subtree
        inOrderHelper( ptr->middlePtr );
        cout << ptr->data << ' ';        // process node
        inOrderHelper( ptr->rightPtr );  // go to right subtree
        
    }
    
}

template< class NODETYPE >
void Tree< NODETYPE >::postOrderHelper(TreeNode< NODETYPE > *ptr ) const{
    if ( ptr != 0 ) {
        postOrderHelper( ptr->leftPtr );   // go to left subtree
        postOrderHelper( ptr->middlePtr );
        postOrderHelper( ptr->rightPtr );  // go to right subtree
        cout << ptr->data << ' ';          // process node
        
    }
    
}


#endif /* Tree_hpp */
