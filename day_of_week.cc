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
	stream << date.GetMonth() << "/" << date.GetDay() << "/" << date.GetYear();
	return stream;
}

