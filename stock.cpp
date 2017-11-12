#include <iomanip>
#include <cstring>
#include "stock.h"

using namespace std;

const int   Stock::columnWidths[4] = {0, 0, 0, 0};

Stock::Stock(char const * const symbol, char const * const name, int sharePrice, Date priceDate) :
    symbol{new char[strlen(symbol) + 1]},
    name{new char[strlen(name) + 1]},
    sharePrice{sharePrice},
    priceDate{priceDate}
{
    strcpy(this->symbol, symbol);
    strcpy(this->name, name);
}

Stock::Stock(void)
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
    symbol = new char[strlen(s.symbol) + 1];
    name = new char[strlen(s.name) + 1];
    sharePrice = s.sharePrice;
    priceDate = s.priceDate;
    strcpy(symbol, s.symbol);
    strcpy(name, s.name);
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
}

// print share price as DOLLARS
// (e.g. 2483 would print out as 24.83 and 200 would print out as 2.00)
ostream& operator<<(ostream& out, const Stock& s)
{
	return out;
}
