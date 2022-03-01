
// COS30008, Tutorial 12, 2021

#include "IntVector.h"
#include "IntSorter.h"

#include <stdexcept>

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
    delete [] fElements;
}

size_t IntVector::size() const
{
    return fNumberOfElements;
}

void IntVector::swap( size_t aSourceIndex, size_t aTargetIndex )
{
    if ( aSourceIndex < fNumberOfElements &&
         aTargetIndex < fNumberOfElements )
    {
        // classical swap
        int lTemp = fElements[aSourceIndex];
        
        fElements[aSourceIndex] = fElements[aTargetIndex];
        fElements[aTargetIndex] = lTemp;
    }
    else
    {
        throw out_of_range( "Illegal vector indices" );
    }
}

void IntVector::sort( const IntSorter& aSorter )
{
    aSorter( *this );
}

const int IntVector::operator[]( size_t aIndex ) const
{
    if ( aIndex < fNumberOfElements )
    {
        return fElements[aIndex];
    }
    
    throw out_of_range( "Illegal vector index" );
}

IntVectorIterator IntVector::begin() const
{
    return IntVectorIterator( *this );
}

IntVectorIterator IntVector::end() const
{
    return begin().end();
} 

ostream& operator<<( ostream& aOStream, const IntVector& aObject )
{
    size_t i = 0;
    
    if ( i < aObject.size() )
    {
        while( true )
        {
            aOStream << aObject[i++];
            
            if ( i < aObject.size() )
            {
                aOStream << ' ';
            }
            else
            {
                break;
            }
        }
    }

    return aOStream;
}
