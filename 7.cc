/*
   By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

   What is the 10 001st prime number?
   */

#include <iostream>
#include <vector>

using namespace std;

#define MAXNUM 1e8
#define MAXPRIME 10001

typedef long long int ll;

void SetNotPrime(vector<bool> *is_prime, ll num){
		for (ll c = (num+1)*(num+1)-1; c < MAXNUM; c += num+1)
				is_prime->at(c) = false;
}

int main(){
		vector<bool> is_prime(MAXNUM, true);

		is_prime[1] = true;
		ll cur_prime = -1;
		ll cur_prime_counter = 0;
		for (int num = 1; num < MAXNUM; num++){
				if (is_prime[num]){
						SetNotPrime(&is_prime, num);
						cur_prime = num;
						cur_prime_counter += 1;
						if (cur_prime_counter == MAXPRIME)
								break;
				}

		}

		if (cur_prime_counter == MAXPRIME)
				cout << "The " << MAXPRIME << "th prime number is : " 
						<< cur_prime+1 << endl;
		else
				cout << "The maximum number is insufficient. The current prime number counter is "
						<< cur_prime_counter << endl;

		return 0;
}
