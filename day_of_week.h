
#include <fstream>

enum DayOfWeek{
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday
};

class Date{
  public:
	Date(int month, int day, int year) : year_(year), month_(month), day_(day) {}
	Date(int month, int day, int year, enum DayOfWeek day_of_week) : year_(year), month_(month), day_(day), day_of_week_(day_of_week) {}
	
	void AddDay(int new_days);
	void AddMonth(int new_months);
	void AddYear(int new_years);
	
	int GetDay() const {return day_;}
	int GetMonth() const {return month_;}
	int GetYear() const {return year_;}
	int GetDayOfWeek() const {return day_of_week_;}

	friend std::ostream& operator<< (std::ostream &stream, const Date& date);
  
  private:
	int year_, month_,day_;
	enum DayOfWeek day_of_week_;
};
bool operator<=(const Date &first, const Date &second);
