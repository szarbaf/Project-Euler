/*
 The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

 Find the sum of all the primes below two million.
 */ 

#include <iostream>
#include <vector>
#include "my_lib.h"


using namespace std;

#define MAXNUM 2e6

typedef long long int ll;

int main(){

	ll last_prime, last_prime_index, sum = 0;
	vector<bool> is_prime = IsPrime(MAXNUM, MAXNUM, &last_prime_index, &last_prime);

	for (int c = 1; c < MAXNUM; c++){
		if (is_prime[c])
				sum += c+1;
	}

	cout << "The sum of the primes under " << MAXNUM << " is " << sum << endl;
	return 0;

}
