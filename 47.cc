/*The first two consecutive numbers to have two distinct prime factors are:
 *
 * 14 = 2 × 7
 * 15 = 3 × 5
 *
 * The first three consecutive numbers to have three distinct prime factors are:
 *
 * 644 = 2² × 7 × 23
 * 645 = 3 × 5 × 43
 * 646 = 2 × 17 × 19.
 *
 * Find the first four consecutive integers to have four distinct prime factors each. What is the first of these numbers?
 */
#include <iostream>
#include <vector>
#include <tuple>
#include <list>
#include <cmath>

using namespace std;

typedef vector<tuple<int, int>> factor_t;

constexpr int kConsecutiveNum = 5;

factor_t GetFactors(int num){

  factor_t out;
  for (int c = 2; c <= sqrt(num); c++){
	if (num%c == 0){
	  int factor_count = 0;
	  while(num%c==0){
		num /= c;
		factor_count++;
	  }
	  out.push_back(make_tuple(c, factor_count));
	}
  }

  if (num != 1)
	out.push_back(make_tuple(num, 1));

  return out;

}

int main(){

  list<int> num_factors, nums;
  int cur_num_consecs = 0;
  for (int c = 1; c < kConsecutiveNum+1; c++){
	factor_t factors = GetFactors(c);
	num_factors.push_back(factors.size());
	nums.push_back(c);
	if (num_factors.back() == kConsecutiveNum)
	  cur_num_consecs++;
  }

  int cur_num = kConsecutiveNum+1;
  while(cur_num_consecs < kConsecutiveNum){
	factor_t factors = GetFactors(cur_num);

	if (num_factors.front() == kConsecutiveNum)
	  cur_num_consecs--;
	num_factors.pop_front();
	nums.pop_front();

	num_factors.push_back(factors.size());
	nums.push_back(cur_num);
	if (num_factors.back() == kConsecutiveNum)
	  cur_num_consecs++;

	cur_num++;
  }

  cout << "The " << kConsecutiveNum << " numbers with " 
	<< kConsecutiveNum << " prime factors are : " << endl;
  for (auto num : nums)
	cout << num << endl;

  return 0;

}
