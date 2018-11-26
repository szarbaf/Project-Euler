/* The series, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.
 *
 * Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.
 */

#include <iostream>
#include <cmath>
#include "my_lib.h"



using namespace std;

constexpr int kMaxNum = 1000;
constexpr int last_num_digits = 11;

int main(){

	ll output = 0;
	ll last_digits_mod = static_cast<ll> (pow(10, last_num_digits));

	//MyMultiplyLastDigits(1234567891, 9087654321, 10);

	for (int c = 1; c < kMaxNum+1; c++){
		ll powered = MyPowerLastDigits(c, c, last_num_digits);
		output = (output + powered) % last_digits_mod;
	}

	cout << "The sum of the powered series 1^1 + 2^2 + ... + " 
	  << kMaxNum << "^" << kMaxNum << " last " << last_num_digits << " number of digits is : " << output << endl;

	return 0;

}
