/*We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.
 *
 * What is the largest n-digit pandigital prime that exists?
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#include "my_lib.h"

using namespace std;

constexpr ll kMaxNum = 987654321;

vector<int> GetNums(int num){
	vector<int> out;
	while (num > 0){
		out.push_back(num%10);
		num /= 10;
	}
	reverse(out.begin(), out.end());
	return out;
}

bool IsPanDigital(int num){
	vector<int> digits = GetNums(num);
	sort(digits.begin(), digits.end());
	for (int c = 1; c < static_cast<int>(digits.size())+1; c++)
	  if ( !(digits[c-1] == c) )
		return false;

	return true;
}

int main(){


  	ll last_prime_index,last_prime;
	vector<bool> is_prime = IsPrime(kMaxNum, kMaxNum, &last_prime_index, &last_prime);

	cout << "Calculated all the primes, moving onto the real buisness!" << endl;

	for (int c = kMaxNum; c > 0; c--){
		if (is_prime[c-1] && IsPanDigital(c)){
			cout << "The largest pandigital prime number is " << c << endl;
			break;
		}
	}

	return 0;
}

