
// COS30008, Problem Set 4, 2021

#pragma once

#include "BNode.h"

template<typename T>
class BinarySearchTreeIterator;

template<typename T>
class BinarySearchTree
{
private:
    BNode<T>* fRoot;
    
public:
    
    using Iterator = BinarySearchTreeIterator<T>;

    BinarySearchTree()
    {
        fRoot = &BNode<T>::NIL;                                 // (4)
    }

    ~BinarySearchTree()
    {
        if ( !empty() )                                         // 4
        {
            delete fRoot;                                       // 2(6)
        }
    }

    bool empty() const
    {
        return fRoot == &BNode<T>::NIL;                         // (6)
    }
    
    bool insert( const T& aKey )
    {
        if ( empty() )                                          // 4
        {
            fRoot = new BNode<T>( aKey );                       // 6

            return true;                                        // 2
        }
        else
        {
            return fRoot->insert( aKey );                       // 4(16)
        }
    }

    bool remove( const T& aKey )
    {
        return fRoot->remove( aKey, &BNode<T>::NIL );           // (6)
    }

    size_t height() const
    {
        return fRoot->height();                                 // (4)
    }
        
    Iterator begin() const
    {
        return Iterator( fRoot );                               // (4)
    }
    
    Iterator end() const
    {
        return begin().end();                                   // (4)
    }
};                                                              // 4+6+6+16+6+4+4+4=50
