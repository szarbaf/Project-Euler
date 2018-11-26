#include <iostream>
#include <fstream>

#include "day_of_week.h"

using namespace std;

bool operator<=(const Date &first, const Date &second){
	if (first.GetYear() < second.GetYear())
	  return true;
	else if (first.GetYear() <= second.GetYear() && first.GetMonth() < second.GetMonth())
	  return true;
	else if(first.GetYear() <= second.GetYear() && first.GetMonth() <= second.GetMonth() 
		&&  first.GetDay() <= second.GetDay())
	  return true;

	return false;
}

ostream& operator<<(ostream& stream, const Date& date){
	stream << date.GetMonth() << "/" << date.GetDay() << "/" << date.GetYear() << " " << day_of_week_names[date.GetDayOfWeek()];
	return stream;
}


int GetTotalNumDays(int month, int year){

		switch(month){
				case January:
				case March:
				case May:
				case July:
				case August:
				case October:
				case December:
						return 31;

				case September:
				case April:
				case June:
				case November:
						return 30;

				case February:
						if (year % 4 == 0 &&
										(year % 100 != 0 || year %400 == 0)
						   )
								return 29;
						else
								return 28;
				default:
						return 0;

		}

}

void Date::AddDay(int new_days){

	int total_num_days_in_current_month = GetTotalNumDays(month_, year_);
	
	int rem_days = total_num_days_in_current_month-day_;
	if (new_days <= rem_days){
		day_ += new_days;
		day_of_week_ = (day_of_week_+new_days)%7;
		return;
	}
	else{
		month_++;
		day_ = 1;
		day_of_week_ = (day_of_week_+rem_days+1)%7;
		if (month_ > December){
			month_ = January;
			year_++;
		}
		AddDay(new_days - rem_days - 1);
	}
}

void Date::AddMonth(int new_months){ 
	for (int m = 0; m < new_months; m++){
		int total_num_days_in_current_month = GetTotalNumDays(month_, year_);
		AddDay(total_num_days_in_current_month);
	}
}
bool operator==(const Date &first, const Date &second){
	return (first.GetDay() == second.GetDay()
					&& first.GetMonth() == second.GetMonth()
					&& first.GetYear() == second.GetYear()
					&& first.GetDayOfWeek() == second.GetDayOfWeek() );

}
bool operator!=(const Date &first, const Date &second){
	return !(first == second);
}

bool operator<(const Date &first, const Date &second){
	return (first <= second && first != second);
}
