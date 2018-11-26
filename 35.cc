/*The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.
 *
 * There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.
 *
 * How many circular primes are there below one million?
 */

#include <iostream>
#include <vector>
#include <algorithm>

#include "my_lib.h"

using namespace std;

constexpr long long int kMaxNum = 1e6;

vector<int> GetCircular(int c){
	vector<int> digits;
	while(c != 0){
		digits.push_back(c%10);
		c /= 10;
	}

	reverse(digits.begin(), digits.end());

	size_t num_digits = digits.size();
	vector<int> out(num_digits);
	for (size_t c = 0; c < num_digits; c++){
		int cur_num = 0;
		for (size_t i = 0; i < num_digits; i++)
				cur_num = 10*cur_num + digits[(c+i)%num_digits];
		out[c] = cur_num;
	}
	return out;
}

int main(){

	long long int last_prime_index, last_prime;
	vector<bool> is_prime = IsPrime(kMaxNum, kMaxNum, &last_prime_index, &last_prime);
	int total_count = 0;
	for (int c = 2; c < kMaxNum; c++){
		if (is_prime[c-1]){
			vector<int> circulars = GetCircular(c);
			bool is_prime_circular = true;
			for (int num : circulars){

				if (!is_prime[num-1]){
					is_prime_circular = false;
					break;
				}
			}
			if (is_prime_circular){
					cout << "The circular numbers for " << c << " are ";
					for (int num : circulars)
						cout << num << " ";
					cout << endl;
					cout << "The number " << c << " is circular prime!" << endl;
					total_count++;
			}
		}
	}

	cout << "The count of circular primes under " << kMaxNum << " is " << total_count << endl;
	return 0;
}
