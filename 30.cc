/*Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:
 *
 * 1634 = 14 + 64 + 34 + 44
 * 8208 = 84 + 24 + 04 + 84
 * 9474 = 94 + 44 + 74 + 44
 * As 1 = 14 is not a sum it is not included.
 *
 * The sum of these numbers is 1634 + 8208 + 9474 = 19316.
 *
 * Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
 */

#include <iostream>
#include <vector>
#include <cmath>

#define POWER 5
typedef long long int ll;

using namespace std;

ll FindUpperLimit(int digit_power){

  int c;  
  for (c = 1; pow(10, c-1) < pow(9, digit_power)*c; c++)
	;

  return pow(10, c-1);
}

bool IsSumOfPowers(ll num, int digit_power){

  ll original_num = num;
  int sum_of_digits_power = 0;
  while (num > 0){
	int digit = num%10;
	sum_of_digits_power += pow(digit, digit_power);
	num = num/10;
  }

  return sum_of_digits_power == original_num;

}

int main(){
  ll upper_limit = FindUpperLimit(POWER);

  ll sum = 0;
  vector<ll> found_nums;
  for (ll c = 2; c < upper_limit; c++){
	if (IsSumOfPowers(c, POWER)){
	  sum += c;
	  found_nums.push_back(c);
	}
  }

  cout << "The sum of all the numbers that can be written as the sum of " << POWER 
	<< "th powers of their digits is : " << sum << endl;

  return 0;


}
