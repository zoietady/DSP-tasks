
// COS30008, Problem Set 4, 2021

#pragma once

#include <stack>

#include "BNode.h"

template<typename T>
class BinarySearchTreeIterator
{
private:
    const BNode<T>* fBNodeTree;
    std::stack<const BNode<T>*> fStack;
    
public:
    
    using Iterator = BinarySearchTreeIterator<T>;
    
    BinarySearchTreeIterator( const BNode<T>* aBNodeTree )
    {
        fBNodeTree = aBNodeTree;                                // 2

        const BNode<T>* lNode = fBNodeTree;                     // 4
        
        while ( !lNode->empty() )                               // 4
        {
            fStack.push( lNode );                               // 3
            lNode = lNode->left;                                // 3(16)
        }
    }

    const T& operator*() const
    {
        return fStack.top()->key;                               // (6)
    }

    Iterator& operator++()
    {
        BNode<T>* lNode = fStack.top()->right;                  // 6
        
        fStack.pop();                                           // 2
        
        if ( !lNode->empty() )                                  // 4
        {
            fStack.push( lNode );                               // 4

            lNode = lNode->left;                                // 3

            while ( !lNode->empty() )                           // 6
            {
                fStack.push( lNode );                           // 3
                lNode = lNode->left;                            // 3
            }
        }
        
        return *this;                                           // 3(34)
    }

    Iterator operator++(int)
    {
        Iterator old = *this;                                   // 3
        
        ++(*this);                                              // 3
        
        return old;                                             // 2(8)
    }

    bool operator==( const Iterator& aOtherIter ) const
    {
        return
            fBNodeTree == aOtherIter.fBNodeTree &&              // 6
            fStack.size() == aOtherIter.fStack.size();          // 6(12)
    }

    bool operator!=( const Iterator& aOtherIter ) const
    {
        return !(*this == aOtherIter);                          // (4)
    }
    
    Iterator begin() const
    {
        return Iterator( fBNodeTree );                          // (4)
    }
    
    Iterator end() const
    {
        Iterator iter = *this;                                  // 4
        
        iter.fStack = std::stack<const BNode<T>*>();            // 6
        
        return iter;                                            // 2(12)
    }
};                                                              // 16+6+34+8+12+4+4+12=96
