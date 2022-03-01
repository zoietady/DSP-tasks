
// COS30008, Tutorial 12, 2021

#pragma once

#include "IntSorter.h"

class FisherAndYatesSort : public IntSorter
{
private:
    void shuffle( IntVector& aContainer ) const;
    
public:
    FisherAndYatesSort();
    
    void operator()( IntVector& aContainer ) const override;
};
