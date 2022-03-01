
// COS30008, Tutorial 5, 2021

#pragma once

#include <string>

#include "EasterEggIterator.h"

using DataMap =
    struct
    {
        unsigned int fIndex;
        unsigned int fDatum;
    };

class EasterEgg
{
private:
    size_t fSize;
    DataMap* fData;

public:
        
    EasterEgg();
    ~EasterEgg();
        
    bool load( const std::string& aFileName );

    size_t size() const;
    
    const DataMap& operator[]( size_t aIndex ) const;
    
    EasterEggIterator begin() const;
    EasterEggIterator end() const;
};
