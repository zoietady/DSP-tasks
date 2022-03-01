
// COS30008, Problem Set 4, 2021

#pragma once

#include <stdexcept>

template<typename S>
struct BNode
{
    S key;
    BNode<S>* left;
    BNode<S>* right;
    
    static BNode<S> NIL;
    
    const S& findMax() const
    {
        if ( empty() )
        {
            throw std::domain_error( "Empty tree encountered." );
        }
        
        return right->empty() ? key : right->findMax();
    }

    const S& findMin() const
    {
        if ( empty() )
        {
            throw std::domain_error( "Empty tree encountered." );
        }
        
        return left->empty() ? key : left->findMin();
    }

    bool remove( const S& aKey, BNode<S>* aParent )
    {
        BNode<S>* x = this;
        BNode<S>* y = aParent;

        while ( !x->empty() )
        {
            if ( aKey == x->key )
            {
                break;
            }

            y = x;                                      // new parent
            
            x = aKey < x->key ? x->left : x->right;
        }

        if ( x->empty() )
        {
            return false;                               // delete failed
        }
        
        if ( !x->left->empty() )
        {
            const S& lKey = x->left->findMax();         // find max to left
            x->key = lKey;
            x->left->remove( lKey, x );
        }
        else
        {
            if ( !x->right->empty() )
            {
                const S& lKey = x->right->findMin();    // find min to right
                x->key = lKey;
                x->right->remove( lKey, x );
            }
            else
            {
                if ( y->left == x )
                {
                    y->left = &NIL;
                }
                else
                {
                    y->right = &NIL;
                }
                
                delete x;                               // free deleted node
            }
        }

        return true;
    }

    // PS4 starts here
    
    BNode() : key(S()), left(&NIL), right(&NIL)
    {}                                                                      // (6)
    
    BNode( const S& aKey ) : key(aKey), left(&NIL), right(&NIL)             // (6)
    {}

    BNode( S&& aKey ) : key(std::move(aKey)), left(&NIL), right(&NIL)       // (8)
    {}

    ~BNode()
    {
        if ( !left->empty() )                                               // 6
        {
            delete left;                                                    // 2
        }

        if ( !right->empty() )                                              // 6
        {
            delete right;                                                   // 2(16)
        }
    }
    
    bool empty() const
    {
        return this == &NIL;                                                // (4)
    }

    bool leaf() const
    {
        return left->empty() && right->empty();                             // (6)
    }

    size_t height() const
    {
        if ( leaf() )                                                       // 4
        {
            return 0;                                                       // 2
        }
        else
        {
            return max( left->height(), right->height() ) + 1;              // 10(16)
        }
    }

    bool insert( const S& aKey )
    {
        BNode<S>* x = this;
        BNode<S>* y = &BNode<S>::NIL;
     
        while ( !x->empty() )
        {
            y = x;
            
            if ( aKey == x->key )
            {
                return false;         // duplicate key - error
            }

            x = aKey < x->key ? x->left : x->right;
        }

        BNode<S>* z = new BNode<S>( aKey );

        if ( y->empty() )
        {
            return false;           // insert failed (NIL)
        }
        else
        {
            if ( aKey < y->key )
            {
                y->left = z;
            }
            else
            {
                y->right = z;
            }
        }
        
        return true;                 // insert succeeded
    }                                                                       // (10) - lecture slide
};                                                                          // 6+6+8+16+4+6+16+10=72

template<typename S>
BNode<S> BNode<S>::NIL;
