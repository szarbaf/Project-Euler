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
#include <unordered_map>

using namespace std;

#define MAXNUM 10
#define MAXDIGITS 500
#define MAXNUMREP 10

int main(){

	int max_d = 3;
	int max_rep = 1;
	for (int i = 4; i < MAXNUM+1; i++){
		auto digits = FractionDigits(i, MAXDIGITS);
		if (digits.size() < MAXDIGITS)
			continue;
		int c = 0;
		unordered_map<int, vector<int>> seen;
		while (c < MAXDIGITS){
			int d = digits[c];
			if (seen.find(d) == seen.end()){
				seen[d].push_back(c);
				c++;
				continue;
			}
			vector<int> recurrence = seen[d];
			int j;
			bool pattern_found = false;
			int cur_recur;
			for (j = 0; j < recurrence.size(); j++){
				cur_recur = recurrence[j];
				if (CheckPattern(digits, cur_recur, c, MAXDIGITS)){
					pattern_found = true;
					break;
				}
			}

			if (!pattern_found){
				seen[d].push_back(c);
				c++;
				continue;			
			}
			int counter = 1;
			int pattern_length = c-cur_recur;
			bool pattern_violated = false;
			while(!pattern_violated && (c+pattern_length) < MAXDIGITS){
				cur_recur += pattern_length;
				c += pattern_length; 
				pattern_violated = !CheckPattern(digits, cur_recur, c);
			}
			if (pattern_violated)

		}

	}

}
