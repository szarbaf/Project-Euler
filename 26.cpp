/*
	 A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:

	 1/2	=	0.5
	 1/3	=	0.(3)
	 1/4	=	0.25
	 1/5	=	0.2
	 1/6	=	0.1(6)
	 1/7	=	0.(142857)
	 1/8	=	0.125
	 1/9	=	0.(1)
	 1/10	=	0.1
	 Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.

	 Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
	 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <math.h>
#include <iomanip>

using namespace std;

#define MAXNUM 1000
#define MAXDIGITS 700
#define MAXNUMREP 10



string FractionDigits(unsigned int num, unsigned int max_digits){
	string out(MAXDIGITS, '0');
	int denominator = num;
	int numerator = 1;
	for (size_t c = 0; c < max_digits; c++){
		numerator *= 10;
		out[c] = numerator / denominator;
		numerator = numerator % denominator;
	}

	return out;
}

/*
	mpf_set_default_prec(MAXDIGITS*2);
	mpf_class a, new_num;
	a = num;
	new_num = 1.0/num;
	mpz_class floored;

	//cout << "1/num is " << setprecision(80) <<new_num << endl;
	//printf("1/num for num=%d is %.40Lf\n", num, new_num);
	for (unsigned int c = 0; c < max_digits; c++){
			new_num *= 10;
			int floored = new_num.get_si();
			if (!(new_num > floored))
					return string();
			out.push_back((char)(floored+'0') );
			new_num -= floored;
	}
*/

/*
bool IsRepeatedString(string &pattern, string &digits){

		bool is_repeated = true;
		int num_reps = digits.size() / pattern.size();
		if (num_reps <= 4)
		  return false;

		for (int c = 0; (is_repeated && c < num_reps); c++){
			for (unsigned int i = 0; i < pattern.size(); i++){
				if (digits[i+c*pattern.size()] != pattern[i]){
					is_repeated = false;
					break;
				}
			}
		}

		if (is_repeated){
			cout << "num_reps: " << num_reps << " Pattern: " << pattern << endl;

		}

		return is_repeated;

}
*/
bool FindPattern(string &digits, string *pattern){

  	

	return !not_found;
}



int main(){

		int max_d = 3;
		unsigned int max_rep = 1;
		for (int i = 4; i < MAXNUM+1; i++){
				auto digits = FractionDigits(i, MAXDIGITS);
				//string digits = to_string(1.0L/i);
				if (digits.size() < MAXDIGITS)
						continue;

				string pattern;
				bool is_patterned = FindPattern(digits, &pattern);
				if (is_patterned){
						if (pattern.size() > max_rep){
								max_d = i;
								max_rep = pattern.size();
						}

				}



		}

		cout << "The number with the largest pattern is : " << max_d << endl;
		cout << "The pattern lenght is : " << max_rep << endl;


		return 0;
}

