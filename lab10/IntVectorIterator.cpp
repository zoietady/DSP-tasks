
// COS30008, Tutorial 12, 2021

#include "IntVectorIterator.h"
#include "IntVector.h"

IntVectorIterator::IntVectorIterator( const IntVector& aContainer, size_t aStart ) :
    fContainer(aContainer),
    fPosition(aStart)
{}

const int IntVectorIterator::operator*() const
{
    return fContainer[fPosition];
}

IntVectorIterator& IntVectorIterator::operator++()
{
    fPosition++;
    
    return *this;
}

IntVectorIterator IntVectorIterator::operator++(int)
{
    IntVectorIterator old = *this;
    
    ++(*this);
    
    return old;
}

bool IntVectorIterator::operator==( const IntVectorIterator& aRHS ) const
{
    return
        &fContainer == &aRHS.fContainer &&
        fPosition == aRHS.fPosition;
}

bool IntVectorIterator::operator!=( const IntVectorIterator& aRHS ) const
{
    return !(*this == aRHS);
}

IntVectorIterator IntVectorIterator::begin() const
{
    IntVectorIterator result = *this;
    
    result.fPosition = 0;
    
    return result;
}

IntVectorIterator IntVectorIterator::end() const
{
    IntVectorIterator result = *this;
    
    result.fPosition = result.fContainer.size();
    
    return result;
}
