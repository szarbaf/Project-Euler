/*Euler discovered the remarkable quadratic formula:
 *
 * n2+n+41
 * It turns out that the formula will produce 40 primes for the consecutive integer values 0≤n≤390. However, when n=40,402+40+41=40(40+1)+41n=40,402+40+41=40(40+1)+41 is divisible by 41, and certainly when n=41,412+41+41n=41,412+41+41 is clearly divisible by 41.
 *
 * The incredible formula n2−79n+1601 was discovered, which produces 80 primes for the consecutive values 0≤n≤79. The product of the coefficients, −79 and 1601, is −126479.
 *
 * Considering quadratics of the form:
 *
 * n2+an+b where |a|<1000 and |b|≤1000
 *
 * where |n| is the modulus/absolute value of nn
 * e.g. |11|=11 and |−4|=4
 * Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n=0.
 */

#include <iostream>
#include <vector>

#include "my_lib.h"

#define MAXN 1000
#define MAXNUM 1e7
#define MAXPRIMEINDEX 1e5
using namespace std;

typedef long long int ll;

int main(){

  ll last_prime_index, last_prime;
  vector<bool> is_prime = IsPrime(MAXNUM, MAXPRIMEINDEX, &last_prime_index, &last_prime);
  int max_n = -1, max_a = -1, max_b = -1;

  for (int a = -999; a < 1000; a++){
	for (int b = -1000; b < 1001; b++){
	  for (int n = 0; n < MAXN; n++){
		ll temp = n*n + a*n + b;
		//cout << temp << " ";
		if (temp < 1 || !is_prime[temp-1]){
		  if (max_n < n){
			max_n = n;
			max_a = a;
			max_b = b;
		  }
		  break;
		}

	  }
	  //cout << endl;
	}

  }

  cout << "The maximum n is : " << max_n << endl;
  cout << "The maximum a is : " << max_a << endl;
  cout << "The maximum b is : " << max_b << endl;
  cout << "The maximum (a*b) is : " << max_a*max_b << endl;

  return 0;
}

