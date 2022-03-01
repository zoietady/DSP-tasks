
#include "IntVectorIterator.h"
#include "IntVector.h"                                                      // (4)

IntVectorIterator::IntVectorIterator( const IntVector& aContainer, size_t aStart ) :
    fContainer(aContainer),                                                 // 4
    fPosition(aStart)                                                       // 2(6)
{}

const int IntVectorIterator::operator*() const
{
    return fContainer[fPosition];                                           // (4)
}

IntVectorIterator& IntVectorIterator::operator++()
{
    fPosition++;                                                            // 2
    
    return *this;                                                           // 4(6)
}
IntVectorIterator IntVectorIterator::operator++(int)
{
    IntVectorIterator old = *this;                                          // 4
    
    ++(*this);                                                              // 4
    
    return old;                                                             // 2(10)
}

bool IntVectorIterator::operator==( const IntVectorIterator& aRHS ) const
{
    return
        &fContainer == &aRHS.fContainer &&                                  // 6
        fPosition == aRHS.fPosition;                                        // 4(10)
}

bool IntVectorIterator::operator!=( const IntVectorIterator& aRHS ) const
{
    return !(*this == aRHS);                                                // (6)
}

IntVectorIterator IntVectorIterator::begin() const
{
    IntVectorIterator result = *this;                                       // 4
    
    result.fPosition = 0;                                                   // 3
    
    return result;                                                          // 1(8)
}

IntVectorIterator IntVectorIterator::end() const
{
    IntVectorIterator result = *this;                                       // 4
    
    result.fPosition = result.fContainer.size();                            // 5
    
    return result;                                                          // 1(10)
}                                                                           // T = (64)
