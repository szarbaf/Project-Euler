/* The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.
 *
 * Find the sum of the only eleven primes that are both truncatable from left to right and right to left.
 *
 * NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
 */

#include <iostream>
#include <cmath>
#include "my_lib.h"

using namespace std;


constexpr int kMaxNum = 1e6;
constexpr int kMaxCount = 11;

bool BothPrimeTruncatable(int c, const vector<bool> &is_prime){

		int right_to_left = c, left_to_right = c;
		int num_digits_minus_one = static_cast<int> (floor(log10(c)));
		while(right_to_left != 0 && left_to_right != 0){
				if (!is_prime[right_to_left-1] || !is_prime[left_to_right-1])
						return false;
				right_to_left /= 10;
				left_to_right %= static_cast<int> (pow(10, num_digits_minus_one--));
		}

		return true;
}

int main(){


		int count = 0;
		int total_sum = 0;
		vector<bool> is_prime = IsPrime(kMaxNum);
		for (int c = 11; c < kMaxNum && count < kMaxCount; c++){
				if (BothPrimeTruncatable(c, is_prime)){
						count++;
						total_sum += c;
						//cout << "Both truncatable number " << c << " found." << endl;
				}
		}

		if (count < kMaxCount)
				cout << "Could not find the all the " << kMaxCount << ", only " << count << " found." << endl;
		else
				cout << "The sum of both truncatable prime numbers is " << total_sum << endl;



		return 0;
}
