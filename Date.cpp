#include "Date.h"
#include <string>
#include <iostream>

string monthName[13] = { "January", "February", "March", "April", "May", "June",
                             "July", "August", "September", "October", "November", "December" };

// mutator that sets the variables month, day, year, and hour to the parameter values
void Date::set(int month_, int day_, int year_, int hour_)
{
    month = month_;
    day = day_;
    year = year_;
    hour = hour_;
} //end function set()

// Prints the date in the format "Month dd, yyyy, hh:00". This function should use the static array monthName
void Date::print() const
{
    string output = "";
    output += (monthName[(month - 1)] + " ");
    output += (to_string(day) + ", ");
    output += (to_string(year) + ", ");
    output += (to_string(hour) + ":00");
    cout << output;
} //end function print()

// accessor that returns the month
int Date::getMonth() const
{
    return month;
} //end function getMonthFromDate()

// accessor that returns the day
int Date::getDay() const
{
    return day;
} //end function getDayFromDate()

// accessor that returns the year
int Date::getYear() const
{
    return year;
} //end function getYearFromDate()

// accessor that returns the hour
int Date::getHour() const
{
    return hour;
} //end function getHourFromDate()