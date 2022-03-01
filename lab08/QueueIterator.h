
// COS30008, Tutorial 10, 2021

#pragma once

#include "Queue.h"

template<typename T>
class QueueIterator
{
private:
    Queue<T> fQueue;

public:
    QueueIterator( const Queue<T>& aQueue ) :
        fQueue(aQueue)
    {}

    const T& operator*()
    {
        return fQueue.top();
    }

    QueueIterator& operator++()
    {
        fQueue.dequeue();

        return *this;
    }

    QueueIterator operator++(int)
    {
        QueueIterator temp = *this;

        ++(*this);

        return temp;
    }

    bool operator==( const QueueIterator& aOtherIter ) const
    {
        return fQueue.size() == aOtherIter.fQueue.size();
    }

    bool operator!=( const QueueIterator& aOtherIter ) const
    {
        return !(*this == aOtherIter);
    }
    
    QueueIterator end() const
    {
        return QueueIterator( Queue<T>() );
    }
};

template<typename T>
QueueIterator<T> Queue<T>::begin() const
{
    return QueueIterator<T>( *this );
}

template<typename T>
QueueIterator<T> Queue<T>::end() const
{
    return begin().end();
}
