/*The following iterative sequence is defined for the set of positive integers:
 *
 * n → n/2 (n is even)
 * n → 3n + 1 (n is odd)
 *
 * Using the rule above and starting with 13, we generate the following sequence:
 *
 * 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
 * It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
 *
 * Which starting number, under one million, produces the longest chain?
 *
 * NOTE: Once the chain starts the terms are allowed to go above one million.
 */


#include <iostream>
#define MAXNUM 1e6

typedef long long int ll;

using namespace std;

ll ChainLength(int num){
	ll counter = 1;
	ll temp_num = num;
	while (temp_num != 1){
		if (temp_num%2 == 0)
		  temp_num = temp_num/2;
		else
		  temp_num = 3*temp_num+1;
		counter++;
	}
	return counter;
}
int main(){

  ll longest = 1;
  ll longest_chain = 1;
  for (int c = 2; c < MAXNUM; c++){
	ll chain_lenght = ChainLength(c);
	if (chain_lenght > longest_chain){
	  longest_chain = chain_lenght;
	  longest = c;
	}
  }

  cout << "The longest chain lenght under " << MAXNUM << " belongs to " << longest 
	   << " and the length is " << longest << endl;

  return 0;

}
