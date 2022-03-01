
#include "CocktailShakerSort.h"

#include "IntVector.h"                                                          // 4

void CocktailShakerSort::operator()( IntVector& aContainer ) const
{
    size_t lBeginIndex = 0;                                                     // 2
    size_t lEndIndex = aContainer.size() - 1;                                   // 4
        
        while ( lBeginIndex < lEndIndex )                                       // 4
        {
            for ( size_t i = lBeginIndex; i < lEndIndex; i++ )                  // 6
            {
                if ( aContainer[i] > aContainer[i+1] )                          // 4
                {
                    aContainer.swap( i, i+1 );                                  // 3
                }
            }
            
            lEndIndex--;                                                        // 2

            for ( size_t i = lEndIndex; i > lBeginIndex; i-- )                  // 6
            {
                if ( aContainer[i] < aContainer[i-1] )                          // 4
                {
                    aContainer.swap( i, i-1 );                                  // 3
                }
            }
            
            lBeginIndex++;                                                      // 2
        }
    }                                                                           // (44)
