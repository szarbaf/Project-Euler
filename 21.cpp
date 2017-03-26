//Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
//If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.
//
//For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
//
//Evaluate the sum of all the amicable numbers under 10000.

#include "iostream"
#include "vector"
#include "algorithm"
#include "math.h"

using std::vector;		using std::upper_bound;

#define MAXNUM 10000


vector<long> sumDevisors(long maxNumber){
	
	//This function calculates the sum of devisors for numbers from 1 to maxNumber
	//To calculate the sum, it starts from one and add the current number to all the devisors higher upto MAXNUM 

	//One is the proper devisor for all numbers except itself.
	vector<long> sums(maxNumber, 1);


	for (vector<long>::size_type counter = 1; counter < maxNumber; counter++){
		long curNum = counter+1;
		for (vector<long>::size_type j = 2*curNum-1 ; j < MAXNUM; j += curNum){
			sums[j] += curNum;
		}
		printf("The sum of devisors for number %ld is : %ld\n", curNum, sums[counter]);

	}

	return sums;	

}

int main(){

	//Calculating the sum of primes for numbers from 1 to MAXNUM.
	vector<long> d = sumDevisors(MAXNUM);
	long sumAmicable = 0 ;
	for (long counter = 1; counter < MAXNUM; counter++){
		
		long curD = d[counter];
		if (curD < MAXNUM && counter+1 != curD && counter+1 == d[curD-1]){
			sumAmicable += counter+1;
			printf("Amicable pairs found: %ld %ld\n", counter+1, curD);
		}

	}

	printf("The sum of Amicable numbers is %ld\n", sumAmicable);
	return 0;

}
