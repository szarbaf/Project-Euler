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
	
  const Date start_date(1, 1990, 1, Monday), end_date(12, 2000, 31);
  int num_sundays_startOfMonth = 0;
  // Iterating through first of the months and checking whether they are sundays.
  for (Date cur_date = start_date; cur_date <= end_date; cur_date.AddMonth(1)){
  	if (cur_date.GetDayOfWeek() == Sunday)
	  num_sundays_startOfMonth++;
  }

  cout << "The number of sundays between " << start_date << " and " << end_date
	<< " is " << num_sundays_startOfMonth << endl;

  return 0;
  

}
