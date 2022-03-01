
// COS30008, Tutorial 2, 2021

#pragma once

#include <iostream>

class CharacterCounter
{
private:
    size_t fTotalNumberOfCharacters;
	size_t fCharacterCounts[256];           // We count all 256 byte values

public:
  CharacterCounter();

  void count( unsigned char aCharacter );

  friend std::ostream& operator<<( std::ostream& aOStream, 
	                               const CharacterCounter& aCharacterCounter );
};
