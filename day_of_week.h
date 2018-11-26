
#include <fstream>
#include <vector>
#include <string>

enum DayOfWeek{
	Monday = 0,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday
};

const std::vector<std::string> day_of_week_names = {
	"Monday",
	"Tuesday",
	"Wednesday",
	"Thursday",
	"Friday",
	"Saturday",
	"Sunday"
};

enum Months{
	January = 1,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December
};

class Date{
  public:
	Date() : year_(1), month_(1), day_(1), day_of_week_(Monday) {}
	Date(int month, int day, int year) : year_(year), month_(month), day_(day), day_of_week_(Monday) {}
	Date(int month, int day, int year, int day_of_week) : year_(year), month_(month), day_(day), day_of_week_(day_of_week) {}


	
	void AddDay(int new_days);
	//Add months till the same day first of the next months.
	//e.g. 02/15/2017, AddMonth(2) -> 04/015/2017
	void AddMonth(int new_months);
	
	int GetDay() const {return day_;}
	int GetMonth() const {return month_;}
	int GetYear() const {return year_;}
	int GetDayOfWeek() const {return day_of_week_;}

	//friend std::ostream& operator<< (std::ostream &stream, const Date& date);
  
  private:
	int year_, month_, day_, day_of_week_;
};
bool operator<=(const Date &first, const Date &second);
bool operator==(const Date &first, const Date &second);
bool operator!=(const Date &first, const Date &second);
bool operator<(const Date &first, const Date &second);
std::ostream& operator<< (std::ostream &stream, const Date& date);


