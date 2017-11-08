#include "date.h"

using namespace std;

Date::Date(Month month, int day, int year) :
    month{month},
    day{day},
    year{year}
{
}

Date::Date()
{
}

Date::~Date(void)
{
}

ostream& operator<<(ostream& out, const Date& d)
{
	return out;
}
