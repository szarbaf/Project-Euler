#include <iostream>
#include <vector>

#include "day_of_week.h"

using namespace std;

typedef struct CurTest{
	Date start_date, end_date;
	int num_days_to_add;
} Test_t;

int main(){

	vector<Test_t> test_cases = {{{2, 9, 1990, Monday}, {2, 10, 1990, Tuesday}, 1}};

	for (auto it = test_cases.begin(); it != test_cases.end(); it++){
		auto start_date = &it->start_date;
		auto test_case = Date(start_date->GetMonth(), start_date->GetDay(), start_date->GetYear(), start_date->GetDayOfWeek());
		test_case.AddDay(it->num_days_to_add);


		auto end_date = it->end_date;
		if (test_case != end_date){
			cout << "Expected " << end_date << " but got " << test_case << endl;
		}
	}
	return 0;

}



