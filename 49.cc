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
  Permutate perm;

  vector<bool> is_prime = IsPrime(1e4+1);

  vector<vector<ll>> out;

  for (int choose_c = 0; choose_c < choose.Size(); choose_c++){
  	vector<int> digits = choose.Next();

	perm.Reset(3);

	vector<ll> cur_out;
	for (int perm_c = 0; perm_c < perm.Size(); perm_c++){
	  	vector<int> temp = perm.Permute(digits);

		perm.Next();
		// Checking whether the first digit is zero. If true, it is not actually a 4 digit number.
		if (temp[0] == 0)
		  continue;
		ll num = GetNum(temp);
	


		if (is_prime[num-1])
			cur_out.push_back(num);
	}
	if (cur_out.size() >= 3){
	  for (int i = 0; i < cur_out.size(); i++){
		for (int j = i+1; j < cur_out.size(); j++)
		  for (int k = j+1; k < cur_out.size(); k++)
			if ( (cur_out[k]-cur_out[j]) == (cur_out[j]-cur_out[i]) )
		  out.push_back({cur_out[i], cur_out[j], cur_out[k]});
	  }
	}
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
