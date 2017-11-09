#include "date.h"

using namespace std;

Date::Date(Month month, int day, int year) :
    month{month},
    day{day},
    year{year}
{
}

Date::Date():
    month{INVALID},
    day{-1},
    year{-1}
{
}

Date::Date(const Date& d) :
    month{d.month},
    day{d.day},
    year{d.year}
{
}

Date::~Date(void)
{
}

ostream& operator<<(ostream& out, const Date& d)
{ 
    switch(d.month)
    {
        case Date::INVALID:
            break;
        case Date::JANUARY:
            out << "January";
            break;
        case Date::FEBRUARY:
            out << "Febuary";
            break;
        case Date::MARCH:
            out << "March";
            break;
        case Date::APRIL:
            out << "April";
            break;
        case Date::MAY:
            out << "May";
            break;
        case Date::JUNE:
            out << "June";
            break;
        case Date::JULY:
            out << "July";
            break;
        case Date::AUGUST:
            out << "August";
            break;
        case Date::SEPTEMBER:
            out << "September";
            break;
        case Date::OCTOBER:
            out << "October";
            break;
        case Date::NOVEMBER:
            out << "November";
            break;
        case Date::DECEMBER:
            out << "December";
            break;
    }
    out << ' ' << d.day << ", " << d.year;
	return out;
}
