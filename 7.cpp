//By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

//What is the 10 001st prime number?
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>

#define LASTNUM 10001

using std::vector;		using std::lower_bound;

int main(){
	
	//Creating a list containing the prime numbers.
	vector<long> primes;
	primes.reserve(LASTNUM);

	//The current number checked for being prime.
	long primeCounter = 0;
	//Loop invarinat: primeCounter contains the current number of prime numbers in primes.
	for (long currentNum = 2 ; primeCounter < LASTNUM; currentNum++){
		
		//Finding the next prime number by performing a binary search for each new number on primes.
		//Finding the closets number to currentNum in primes by performing a binary search on primes.
		vector<long>::const_iterator closestNum = lower_bound(primes.begin(), primes.end(), sqrt(currentNum));
		//Checking currentNum against all the numbers from the start to closestNum.
		bool isPrime = true;
		//In case sqrt(currentNum) == *closetNum
		if (closestNum != primes.end() && sqrt(currentNum) == *closestNum)
			isPrime = false;
		else{
			for (vector<long>::const_iterator it = primes.begin(); it != closestNum; it++){
				if(currentNum % *it == 0){
					isPrime = false;
					break;
				}
			}
		}
		if (isPrime == true){
			primes.push_back(currentNum);
			primeCounter++;
		}
	}
	
	printf("The %dst prime number is : %ld \n", LASTNUM, *(primes.end()-1) );

	return 0;

}
