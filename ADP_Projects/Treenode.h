//
//  Treenode.h
//  ADP_Projects
//
//  Created by Norio Egi on 4/20/16.
//  Copyright © 2016 Capotasto. All rights reserved.
//

#ifndef Treenode_h
#define Treenode_h

// forward declaration of class Tree
template< class NODETYPE > class Tree;

template< class NODETYPE >
class TreeNode {
    friend class Tree< NODETYPE >;
    
public:
    
    // constructor
    TreeNode( const NODETYPE &d ):
    leftPtr( 0 ),
    data( d ),
    rightPtr( 0 ),
    middlePtr( 0 ){
        
    } // end TreeNode constructor
    
    // return copy of node's data
    NODETYPE getData() const
    {
        return data;
        
    } // end getData function
    
private:
    TreeNode< NODETYPE > *leftPtr;  // pointer to left subtree
    NODETYPE data;
    TreeNode< NODETYPE > *rightPtr; // pointer to right subtree
    TreeNode< NODETYPE > *middlePtr;
    
}; // end class TreeNode


#endif /* Treenode_h */