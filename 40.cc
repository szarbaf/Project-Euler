/* An irrational decimal fraction is created by concatenating the positive integers:
 *
 * 0.123456789101112131415161718192021...
 *
 * It can be seen that the 12th digit of the fractional part is 1.
 *
 * If dn represents the nth digit of the fractional part, find the value of the following expression.
 *
 * d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000
 */

#include <iostream>
#include <string>

using namespace std;

constexpr int kMaxNum = 1e6;

int main(){

	string all_nums(kMaxNum, '*');

	int total_size = 0;
	for (int c = 1; total_size < kMaxNum; c++){
		string cur_num = to_string(c);
		int cur_size = cur_num.size();

		all_nums.replace(total_size, cur_size, cur_num);
		total_size += cur_size;
	}

	int pos = 1;
	double out = 1;
	for (int c = 0; c < 7; c++){
		out *= all_nums[pos-1] - '0';
		pos *= 10;
	}


	cout << "The desired product is : " << out << endl;
	return 0;

}
