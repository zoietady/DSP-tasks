
// COS30008, Tutorial 12, 2021

#include "IntVector.h"
#include "IntVectorIterator.h"
#include "IntSorter.h"

#include <iostream>

using namespace std;

#define P0
#define P1
//#define P2

#ifdef P0

void runP0()
{
    cout << "Test output operator:" << endl;

    int lArray[] = { 34, 65, 890, 86, 16, 218, 20, 49, 2, 29 };
    size_t lArrayLength = sizeof(lArray) / sizeof(int);

    IntVector lVector( lArray, lArrayLength );
            
    cout << "Vector: " << lVector <<  endl;
}

#endif

#ifdef P1

#include "BubbleSort.h"

void runP1()
{
    cout << "Test bubble sort:" << endl;

    int lArray[] = { 34, 65, 890, 86, 16, 218, 20, 49, 2, 29 };
    size_t lArrayLength = sizeof(lArray) / sizeof(int);

    IntVector lVector( lArray, lArrayLength );
    
    cout << "Before sorting: " << lVector <<  endl;

    lVector.sort( BubbleSort() );
    
    cout << "After sorting: " << lVector << endl;
}

#endif

#ifdef P2

#include "FisherAndYatesSort.h"

void runP2()
{
    cout << "Test Fisher&Yates sort:" << endl;

    int lArray[] = { 34, 65, 890, 86, 16, 218, 20, 49, 2, 29 };
    size_t lArrayLength = sizeof(lArray) / sizeof(int);

    IntVector lVector( lArray, lArrayLength );
    
    cout << "Before sorting: " << lVector <<  endl;

    lVector.sort( FisherAndYatesSort() );
    
    cout << "After sorting: " << lVector <<  endl;
}

#endif

int main()
{
#ifdef P0
    
    runP0();
    
#endif

#ifdef P1
    
    runP1();
    
#endif
    
#ifdef P2
    
    runP2();
    
#endif

    return 0;
}
