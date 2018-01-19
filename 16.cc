/*
 * 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 *
 * What is the sum of the digits of the number 2^1000?
 */

#include <iostream>
#include "big_number.h"

using namespace std;

#define POWER 1000

int main(){

	BigNumber big_num = 1;
	for(int c = 0; c < POWER; c++)
	  big_num = big_num * 2;

	int sum_of_digits = 0;
	for (int c = 0; c < big_num.NumDigits(); c++)
	  sum_of_digits += big_num.digits_[c];

	cout << "The sum of digits for " << POWER << "th power of 2 is " << sum_of_digits << endl;
	return 0;

}
