/*It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.
 *
 * 9 = 7 + 2×12
 * 15 = 7 + 2×22
 * 21 = 3 + 2×32
 * 25 = 7 + 2×32
 * 27 = 19 + 2×22
 * 33 = 31 + 2×12
 *
 * It turns out that the conjecture was false.
 *
 * What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?
 */

#include <iostream>
#include <vector>

#include "my_lib.h"

using namespace std;

typedef long long int ll;

constexpr ll max_square = 1e4;
constexpr ll max_prime_index = 1e4;

int main(){

	ll last_prime_index, last_prime;
	vector<bool> is_prime = IsPrime(max_prime_index, max_prime_index, &last_prime_index, &last_prime);

	const ll max_try = last_prime + 2*max_square;
	vector<bool> found(max_try, false);

	for (int prime_counter)

}



