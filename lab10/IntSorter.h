
// COS30008, Tutorial 12, 2021

#pragma once

// forward declaration for container
class IntVector;

class IntSorter
{
public:
    
    virtual ~IntSorter() {}
    
    virtual void operator()( IntVector& aContainer ) const {}
};
