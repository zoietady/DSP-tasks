
// COS30008, Tutorial 10, 2021

#pragma once

#include <vector>
#include <stdexcept>

template<typename T>
class QueueIterator;

template<typename T>
class Queue
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
    
    void enqueue( const T& aItem )
    {
        fElements.push_back( aItem );
    }
    
    void enqueue( T&& aItem )
    {
        fElements.push_back( std::move(aItem) );
    }

    void dequeue()
    {
        if ( size() > 0 )
        {
            fElements.erase(fElements.begin());
        }
        else
        {
            throw std::underflow_error( "Queue empty." );
        }
    }

    const T& top() const
    {
        if ( size() > 0 )
        {
            return fElements.front();
        }
        else
        {
            throw std::underflow_error( "Queue empty." );
        }
    }
    
    QueueIterator<T> begin() const;
    QueueIterator<T> end() const;
};
