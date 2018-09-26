/*Triangle, pentagonal, and hexagonal numbers are generated by the following formulae:
 *
 * Triangle	 	Tn=n(n+1)/2	 	1, 3, 6, 10, 15, ...
 * Pentagonal	 	Pn=n(3n−1)/2	 	1, 5, 12, 22, 35, ...
 * Hexagonal	 	Hn=n(2n−1)	 	1, 6, 15, 28, 45, ...
 * It can be verified that T285 = P165 = H143 = 40755.
 *
 * Find the next triangle number that is also pentagonal and hexagonal.
 */


#include <iostream>
#include <cmath>

using namespace std;

typedef long long int ll;

constexpr ll kStartingNum = 286;
constexpr ll kMaxTry = 1e8;
constexpr double kRes = 1e-8;

bool IsPentagonal(ll num){
	double test = (1 + sqrt(1+24*num)) / 6.0;
	if (test - floor(test) < kRes)
	  return true;
	else
	  return false;
}


bool IsHexagonal(ll num){
	double test = (1 + sqrt(1+8*num)) / 4.0;
	if (test - floor(test) < kRes)
	  return true;
	else
	  return false;
}

int main(){
	
	for (ll c = kStartingNum; c < kMaxTry+kStartingNum; c++){
	  ll num = c*(c+1)/2;
	  if (IsPentagonal(num) && IsHexagonal(num)){
	  	cout << "The first interesting number is " << num << endl;
		return 0;
	  }
	}

	cout << "Could not find any interesting numbers after " << kMaxTry << " tries." << endl;
	return 0;

}
