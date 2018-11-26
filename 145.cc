/* Some positive integers n have the property that the sum [ n + reverse(n) ] consists entirely of odd (decimal) digits. For instance, 36 + 63 = 99 and 409 + 904 = 1313. We will call such numbers reversible; so 36, 63, 409, and 904 are reversible. Leading zeroes are not allowed in either n or reverse(n).
 *
 * There are 120 reversible numbers below one-thousand.
 *
 * How many reversible numbers are there below one-billion (109)?
 */

#include <iostream>


using namespace std;

constexpr int kMaxNum = 1e9;

int ReverseNum(int c){
	int out = 0;
	while (c != 0){
		out = 10*out + c%10;
		c /= 10;
	}
	return out;
}

bool IsOddDigits(int num){
	while (num != 0){
		if (num%2 == 0)
		  return false;
		num /= 10;
	}
	return true;
}

int main(){
	
  	size_t total_num = 0;
  	for (int c = 1; c < kMaxNum; c++){
		if (c % 10 != 0 && IsOddDigits(c + ReverseNum(c))){
			//cout << "Reversible number " << c << " found." << endl;
			total_num++;
		}
	}

	cout << "The total number of reversible numbers under " << kMaxNum << " is " << total_num << endl;

	return 0;
}
