/*The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order, but it also has a rather interesting sub-string divisibility property.
 *
 * Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:
 *
 * d2d3d4=406 is divisible by 2
 * d3d4d5=063 is divisible by 3
 * d4d5d6=635 is divisible by 5
 * d5d6d7=357 is divisible by 7
 * d6d7d8=572 is divisible by 11
 * d7d8d9=728 is divisible by 13
 * d8d9d10=289 is divisible by 17
 * Find the sum of all 0 to 9 pandigital numbers with this property.
 */

#include <iostream>
#include <vector>
#include <algorithm>

#include "my_lib.h"

constexpr long int kMaxNum = 9876543210;

typedef long long ll;

using namespace std;


bool operator >= (vector<int> a, vector<int> b){
	if (a.size() > b.size())
	  return true;
	else if (a.size() < b.size())
	  return false;

	int num_d = a.size();
	for (int c = 0; c < num_d; c++){
	  if (a[c] < b[c])
		return false;
	  else if (a[c] > b[c])
		return true;

	}


	return true;
}


ll GetSum( vector<int> num){
	ll out = 0;
	for (auto d : num)
	  out = 10*out + d;

	return out;
}

bool IsInteresting(vector<int> digits){

	vector<int> div = {2, 3, 5, 7, 11, 13, 17};
	for (int c = 1; c < 8; c++){
		int sum = 100*digits[c]+10*digits[c+1]+digits[c+2];
		if (!(sum%div[c-1] == 0) )
		  return false;

	}

	return true;
}

int main(){
	
  ll sum = 0;
  vector<int> cur_pan_digital = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  vector<int> lower_limit = {1, 0, 2, 3, 4, 5, 6, 7, 8, 9};
  while (cur_pan_digital >= lower_limit){
	if (IsInteresting(cur_pan_digital)){
	  ll num = GetSum(cur_pan_digital);
	  cout << "Found interesting PanDigital " << num << endl;
	  sum += num;

	}

	NextLargestPanDigital(cur_pan_digital);
  }

  cout << "The sum of all the pandigital numbers with the interesting property is : " << sum << endl;

  return 0;

}
