
// COS30008, Tutorial 12, 2021

#include "FisherAndYatesSort.h"
#include "IntVector.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

void FisherAndYatesSort::shuffle( IntVector& aContainer ) const
{
    // Fisher & Yates shuffling
    size_t n = aContainer.size();

    while ( n > 1 )
    {
        // new random index in the range 0 to n
        int k = rand() % n;
        n--;                        // n last pertinent index
        aContainer.swap( n, k );    // algorithm library
    }
}

void FisherAndYatesSort::operator()( IntVector& aContainer ) const
{
    bool lIsSorted = false;
    
    do
    {
        lIsSorted = true;
        
        for ( size_t i = 1; i < aContainer.size(); i++ )
        {
            if ( aContainer[i-1] > aContainer[i] )
            {
                lIsSorted = false;
                break;
            }
        }

        cout << "Stage: " << aContainer << endl;

        if ( !lIsSorted )
        {
            shuffle( aContainer );
        }
    } while ( !lIsSorted );
}

FisherAndYatesSort::FisherAndYatesSort()
{
    srand( (unsigned int)time( NULL ) );
}
