
// COS30008, Final Exam, 2021

#pragma once

#include "TTree.h"

#include <stack>

template<typename S>
struct TTreeFrontier
{
    size_t stage;                           // frontier stages: 0, 1, 2
    const TTree<S>* node;                   // frontier TTree node
    
    TTreeFrontier( const TTree<S>* aNode ) :
        node(aNode),                        // TTree node
        stage(0)                            // 0 - start right
    {}
};

template<typename T>
class TTreePostfixIterator
{
private:
    const TTree<T>* fTTree;                 // 3-way tree
    std::stack<TTreeFrontier<T>> fStack;    // DFS traversal stack

    using Frontier = TTreeFrontier<T>;

	// push subtree starting with aNode
    void push_nodes(const TTree<T>* aNode) 
    {
        fStack.push(aNode);
    }
    
 public:

    using Iterator = TTreePostfixIterator<T>;
    
    Iterator operator++(int)
    {
        Iterator old = *this;

        ++(*this);
        
        return old;
    }
    
    bool operator!=( const Iterator& aOtherIter ) const
    {
        return !(*this == aOtherIter);
    }

	// iterator constructor
    TTreePostfixIterator(const TTree<T>* aTTree)
    {
        fTTree = aTTree;

        constTTree<T>* lNode = fTTree;

        push_nodes(lNode);

        while (!lNode.empty())
        {
            
            if (!lNode.GetRight().empty())
                push_nodes(lNode.GetRight());
            if (!lNode.GetMiddle().empty())
                push_nodes(lNode.GetMiddle());
            if (!lNode.GetLeft().empty())
                push_nodes(lNode.GetLeft());
            
            lNode = lNode.GetLeft();
        }

    }

	// iterator dereference
	const T& operator*() const
    {
        return *(fStack.top());                              
    }

    // prefix increment
	Iterator& operator++()
    {
        TTree<T>* lNode = fStack.top().GetMiddle();

        fStack.pop();

        if (!lNode->empty())                                  
        {
            fStack.push(lNode);                               

            lNode = lNode.GetMiddle();

            while (!lNode->empty())                           
            {
                fStack.push(lNode);                           
                lNode = lNode.GetMiddle();
            }
        }
        else 
        {
            lNode = fStack.top().GetLeft();
            fStack.push(lNode);

            lNode = lNode.GetLeft();

            while (!lNode->empty())
            {
                fStack.push(lNode);
                lNode = lNode.GetLeft();
            }

        }
        return *this;
    }

	// iterator equivalence
    bool operator==(const Iterator& aOtherIter) const
    {
        return fTTree == aOtherIter.fTTree;
    }

	// auxiliaries
    Iterator begin() const
    {
        return Iterator(fTTree);
    }
	Iterator end() const
    {
        Iterator iter = *this;                                  

        iter.fStack = std::stack<const TTree<T>*>();

        return iter;
    }
};
