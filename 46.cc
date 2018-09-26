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

	const ll max_try = last_prime + 2*max_square*max_square;
	vector<bool> found(max_try, false);


	for (ll prime_counter = 2; prime_counter < last_prime+1; prime_counter++)
	  for (ll square_counter = 1; square_counter < max_square+1; square_counter++){
	  	if (is_prime[prime_counter-1]) {
			ll cur_num = prime_counter + 2*square_counter*square_counter;
			if (cur_num < max_try)
				found[cur_num-1] = true;
		}
	  }

	bool smallest_found = false;
	ll out;
	for (int c = 3; (c < max_try) && !smallest_found; c++)
	  if (!is_prime[c] && (c+1)%2 == 1){
		if (!found[c]){
		  out = c+1;
		  smallest_found = true;
		}
		else
		  cout << "Composite odd number with the property : " << c+1 << endl;
	  }

	if (smallest_found)
	  cout << "The smallest interesting composite odd number is : " << out << endl;
	else
	  cout << "No composite odd number was found." << endl;

	return 0;
}



