
// COS30008, Tutorial 12, 2021

#include "BubbleSort.h"

#include "IntVector.h"

#include <iostream>

using namespace std;

void BubbleSort::operator()( IntVector& aContainer ) const
{
    for ( size_t i = aContainer.size() - 1; i > 0 ; i-- )
    {
        for ( int j = 0; j < i; j++ )
        {
            if ( aContainer[j+1] < aContainer[j] )
                aContainer.swap( j+1, j );
        }
        
        cout << "Stage: " << aContainer << endl;
    }
}
