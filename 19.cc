/*You are given the following information, but you may prefer to do some research for yourself.
 *
 * 1 Jan 1900 was a Monday.
 * Thirty days has September,
 * April, June and November.
 * All the rest have thirty-one,
 * Saving February alone,
 * Which has twenty-eight, rain or shine.
 * And on leap years, twenty-nine.
 * A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
 * How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
 */

#include <iostream>

#include "day_of_week.h"

using namespace std;


int main(){
	
  const Date date_one(1, 1, 1900, Monday), date_two(1, 1, 1901), end_date(12, 31, 2000);
  int num_sundays_startOfMonth = 0;
  // Iterating through first of the months and checking whether they are sundays.
  for (Date cur_date = date_one; cur_date <= end_date; cur_date.AddMonth(1)){
  	if (cur_date.GetDayOfWeek() == Sunday)
	  num_sundays_startOfMonth++;
  }

  //Removing the sundays in the range [date_one date_two)
  for (Date cur_date = date_one; cur_date < date_two; cur_date.AddMonth(1)){
  	if (cur_date.GetDayOfWeek() == Sunday)
	  num_sundays_startOfMonth--;
  }

  cout << "The number of sundays between " << date_two << " and " << end_date
	<< " is " << num_sundays_startOfMonth << endl;

  return 0;
  

}
