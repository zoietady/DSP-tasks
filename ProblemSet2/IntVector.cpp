
#include "IntVector.h"
#include "IntSorter.h"

#include <stdexcept>                                                    // (4)

using namespace std;

IntVector::IntVector( const int aArrayOfIntegers[], size_t aNumberOfElements )
{
    fNumberOfElements = aNumberOfElements;
    fElements = new int[fNumberOfElements];
    
    for ( size_t i = 0; i < fNumberOfElements; i++ )
    {
        fElements[i] = aArrayOfIntegers[i];
    }
}

IntVector::~IntVector()
{
    delete [] fElements;                                                // (4)
}

size_t IntVector::size() const
{
    return fNumberOfElements;                                           // (2)
}

void IntVector::swap( size_t aSourceIndex, size_t aTargetIndex )
{
    if ( aSourceIndex < fNumberOfElements &&
         aTargetIndex < fNumberOfElements )                             // 8
    {
        // classical swap
        int lTemp = fElements[aSourceIndex];                            // 4
        
        fElements[aSourceIndex] = fElements[aTargetIndex];              // 4
        fElements[aTargetIndex] = lTemp;                                // 4
    }
    else
    {
        throw out_of_range( "Illegal vector indices" );                 // 2(22)
    }
}

void IntVector::sort( const IntSorter& aSorter )
{
    aSorter( *this );                                                   // (4)
}

const int IntVector::operator[]( size_t aIndex ) const
{
    if ( aIndex < fNumberOfElements )                                   // 4
    {
        return fElements[aIndex];                                       // 4
    }
    
    throw out_of_range( "Illegal vector index" );                       // 2(10)
}

IntVectorIterator IntVector::begin() const
{
    return IntVectorIterator( *this );                                  // (4)
}

IntVectorIterator IntVector::end() const
{
    return begin().end();                                               // (4)
}                                                                       // T = (54)
