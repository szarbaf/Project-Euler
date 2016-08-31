//By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

//What is the 10 001st prime number?
#include <iostream>
#include <vector>

#define LASTNUM 10001

using std::vector;

int main(){
	
	//Creating a list containing the prime numbers.
	vector<long> primes;
	primes.reserve(LASTNUM);

	//The current number checked for being prime.
	long currentNum = 2;
	//Loop invarinat: primeCounter contains the current number of prime numbers in primes.
	for (int primeCounter = 0; primeCounter < LASTNUM; primeCounter++){
		
		//Finding the next prime number by performing a binary search for each new number on primes.
		bool isPrime = false;
		while (!isPrime){
			//Finding the closets number to currentNum in primes by performing a binary search on primes.
			
			//Checking currentNum against all the numbers from the start to closestNum.
		}
		
	}

	return 0;

}
