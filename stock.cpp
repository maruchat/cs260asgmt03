#include <iomanip>
#include <cstring>
#include "stock.h"

using namespace std;

const int   Stock::columnWidths[4] = {8, 41, 8, 5 };

Stock::Stock(char const * const symbol, char const * const name, int sharePrice, Date priceDate) :
    symbol{new char[strlen(symbol) + 1]},
    name{new char[strlen(name) + 1]},
    sharePrice{sharePrice},
    priceDate{priceDate}
{
    strcpy(this->symbol, symbol);
    strcpy(this->name, name);
}

Stock::Stock(void) :
    symbol{NULL},
    name{NULL},
    sharePrice{-1},
    priceDate{Date()}
{
}

Stock::~Stock(void)
{
    delete [] symbol;
    delete [] name;
}

char const * const Stock::getSymbol(void) const
{
	return symbol;	// change this to return the actual stock symbol
}

/*
you can choose to implement any of the next 3 items if necessary --
if not, feel free not to implement them
*/

Stock::Stock(const Stock& s) :
    symbol{new char[strlen(s.symbol) + 1]},
    name{new char[strlen(s.name) + 1]},
    sharePrice{s.sharePrice},
    priceDate{s.priceDate}
{
    strcpy(symbol, s.symbol);
    strcpy(name, s.name);
}

Stock& Stock::operator=(const Stock& s)
{
    if(this == &s){ return *this; }
    if(symbol != NULL){ delete symbol; }
    if(name != NULL){ delete name; }
    if(!s.symbol)
    {
        symbol = NULL;
    }else
    {
        symbol = new char[strlen(s.symbol) + 1];    
        strcpy(symbol, s.symbol);
    }
    if(!s.name)
    {
        name = NULL;
    }else
    {
        name = new char[strlen(s.name) + 1];
        strcpy(name, s.name);
    }
    sharePrice = s.sharePrice;
    priceDate = s.priceDate;
	return *this;
}

Stock& Stock::operator=(Stock const * const s)
{ 
    symbol = new char[strlen(s->symbol) + 1];
    name = new char[strlen(s->name) + 1];
    sharePrice = s->sharePrice;
    priceDate = s->priceDate;
    strcpy(symbol, s->symbol);
    strcpy(name, s->name);
	return *this;
}


// display column headers for printout of stocks
void Stock::displayHeaders(ostream& out)
{
	// print something like this:
	//
	//  symbol  name                                      price   date
	//  ------  ----                                      -----   ----
    out << dec << setfill(' ')
        << left 
        << setw(8) << "symbol"
        << setw(6) << "name"
        << right << setw(41) << "price"
        << setw(7) << "date" << endl;
    out << dec << setfill(' ')
        << left 
        << setw(8) << "------"
        << setw(6) << "----"
        << right << setw(41) << "-----"
        << setw(7) << "----" << endl;


}

// print share price as DOLLARS
// (e.g. 2483 would print out as 24.83 and 200 would print out as 2.00)
ostream& operator<<(ostream& out, const Stock& s)
{
    out << left << setfill(' ')
        << setw(8) << s.symbol
        << setw(42) << s.name
        << right
        << setw(2) << ( s.sharePrice / 100 )
        << '.';
   
    if( ( s.sharePrice % 100 ) < 10 )
        out << '0';        
    out << ( s.sharePrice % 100 );
    /*if( ( s.sharePrice % 100 ) == 0 )
        out << '0';
    */
    out << "   " << right << setfill(' ')
        << s.priceDate;
	return out;
}
