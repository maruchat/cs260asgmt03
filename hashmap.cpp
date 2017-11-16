#include "hashmap.h"
#include <cstring>
using namespace std;

// change the value of this variable to be your own name instead of "I. Forgot"
const char	HashMap::YOUR_NAME[] = "Thomas Marucha";

HashMap::HashMap(int capacity) :
    slots{new Slot[capacity]},
    capacity{capacity},
    nStocks{0}  
{
}

HashMap::~HashMap(void)
{
    delete [] slots;
}

bool HashMap::get(char const * const symbol, Stock& s,
				  unsigned int& symbolHash, unsigned int& hashIndex,
				  unsigned int& usedIndex, unsigned int& seqLength)
	 const
{
	// If the symbol is not found, this function is required
	// to set usedIndex to -1 before it returns false.

	// recode these to return the right things
	symbolHash = hashStr( s.getSymbol() );
	hashIndex =  ( symbolHash % capacity );
    for(unsigned int i = 0; i < capacity; i++)
    {
        if( !slots[(hashIndex + i) % capacity].occupied)
        {
            usedIndex = -1;
            return false;
        }
        if( strcmp( slots[(hashIndex + i) & capacity].slotStock.getSymbol(), s.getSymbol()) == 0)
        {
            seqLength = (i + 1);
            usedIndex = (hashIndex + i) % capacity;
        }
    }
	usedIndex =  0xFFFFFFFF;
	seqLength =  0xFFFFFFFF;

	return false;
}

bool HashMap::put(const Stock& s,
				  unsigned int& symbolHash, unsigned int& hashIndex,
				  unsigned int& usedIndex, unsigned int& seqLength)
{
	// recode these to return the right things
	symbolHash = hashStr( s.getSymbol() );
	hashIndex =  ( symbolHash % capacity );
    for(unsigned int i = 0; i < capacity; i++)
    {
        if( !(slots[ ( hashIndex + i ) % capacity ].occupied) )
        {
            usedIndex = ( hashIndex + i ) % capacity;
            seqLength = (i + 1);
            slots[usedIndex].occupied = true;
            slots[usedIndex].slotStock = s;
            return true;
        }
        seqLength++;        
    }
    
    
    usedIndex =  0xFFFFFFFF;

	return false;
}

bool HashMap::remove(char const * const symbol, Stock& s,
					 unsigned int& symbolHash, unsigned int& hashIndex,
					 unsigned int& usedIndex, unsigned int& seqLength)
{
	// recode these to return the right things
	symbolHash = 0xFFFFFFFF;
	hashIndex =  0xFFFFFFFF;
	usedIndex =  0xFFFFFFFF;
	seqLength =  0xFFFFFFFF;

	return false;
}

unsigned int HashMap::hashStr(char const * const s)
{
	// Hash C string argument using the formula in java.lang.String.hashCode():
	//
	//   s[0]*(31^(n-1)) + s[1]*(31^(n-2)) + ... + s[n-1]
	//
	// s is the array of characters, n is the number of characters in the string,
	// and 31^n means 31 to the nth power.
	//
	// This function is declared static because its result depends
	// only on the characters in the string. You will need to apply
	// the modulo operator to the result of this function to generate
	// the required table index. The place to do this is in the functions
	// that call this function.
	//
	// You can and should do this computation entirely with integers. In other
	// words, there is no need to use floating point values. In particular, you
	// should not use the pow() function from <math.h> in this lab.
    int hashValue = 0;
    int multiplier;
    for(unsigned int i = 0; i < strlen(s); i++)
    {   
        multiplier = 31;
        for(int j = ( strlen(s) - i - 1 ); j > 0; j--)
        {
            multiplier *= 31;
        } 
        hashValue += (multiplier * s[i]);
    }
	return hashValue;
}

ostream& operator<<(ostream& out, const HashMap &h)
{
    Stock::displayHeaders(out);
	out << "<print the contents of the HashMap>" << endl;
    return out;
}
