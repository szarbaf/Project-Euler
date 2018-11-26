/*
   By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

   What is the 10 001st prime number?
   */

#include <iostream>
#include <vector>
#include "my_lib.h"

using namespace std;

#define MAXNUM 1e8
#define MAXPRIME 10001

typedef long long int ll;

int main(){

  		ll last_prime_index, last_prime;
		auto is_prime = IsPrime(MAXNUM, MAXPRIME, &last_prime_index, &last_prime);

		if (last_prime_index == MAXPRIME)
				cout << "The " << MAXPRIME << "th prime number is : " 
						<< last_prime << endl;
		else
				cout << "The maximum number is insufficient. The current prime number counter is "
						<< last_prime_index << endl;

		return 0;
}
