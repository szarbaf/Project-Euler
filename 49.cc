/* The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways: (i) each of the three terms are prime, and, (ii) each of the 4-digit numbers are permutations of one another.
 *
 * There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property, but there is one other 4-digit increasing sequence.
 *
 * What 12-digit number do you form by concatenating the three terms in this sequence?
 */

#include <iostream>
#include <vector>

#include "my_lib.h"
#include "combinatorial.h"

using namespace std;

int main(){

  Choose choose(9, 4);
  Permutate perm(4);

  vector<bool> is_prime = IsPrime(1e4+1);

  vector<vector<ll>> out;

  for (int choose_c = 0; choose_c < choose.size(); choose_c++){
  	vector<int> digits = choose.next();

	vector<ll> cur_out;
	for (int perm_c = 0; perm_c < 4; perm_c++){
	  	perm.Permute(digits);
		// Checking whether the first digit is zero. If true, it is not actually a 4 digit number.
		if (digits[0] == 0)
		  continue;
		ll num = GetNum(digits);
		
		if (is_prime[num-1])
			cur_out.push_back(num);
		perm.Next();
	}
	if (cur_out.size() == 3)
	  out.push_back(cur_out);
  }

  cout << "The interesting series of numbers are : " << endl;
  int counter = 1;
  for (auto s : out){
	cout << counter << "- ";
  	for (auto s_n : s)
		cout << s_n;
	cout << endl;
	counter++;
  }

  return 0;

}
