
// COS30008, Tutorial 12, 2021

#pragma once

#include "IntSorter.h"

class BubbleSort : public IntSorter
{
public:
    
    void operator()( IntVector& aContainer ) const override;
};
