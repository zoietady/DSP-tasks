
// COS30008, Tutorial 10, 2021

#pragma once

#include <vector>
#include <stdexcept>

template<typename T>
class StackIterator;

template<typename T>
class Stack
{
private:
	std::vector<T> fElements;

public:
    
    // conversion operator
    explicit operator bool() const
    {
        return empty();
    }
    
	bool empty() const
    {
        return fElements.empty();
    }
    
	size_t size() const
    {
        return fElements.size();
    }
    
	void push( const T& aItem )
    {
        fElements.push_back( aItem );
    }
    
    void push( T&& aItem )
    {
        fElements.push_back( std::move(aItem) );
    }

	void pop()
    {
        if ( size() > 0 )
        {
            fElements.pop_back();
        }
        else
        {
            throw underflow_error( "Stack empty." );
        }
    }
    
	const T& top() const
    {
        if ( size() > 0 )
        {
            return fElements[size() - 1];
        }
        else
        {
            throw underflow_error( "Stack empty." );
        }
    }
    
    StackIterator<T> begin() const;
    StackIterator<T> end() const;
};
