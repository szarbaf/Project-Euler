/* The radical of n, rad(n), is the product of distinct prime factors of n. For example, 504 = 23 × 32 × 7, so rad(504) = 2 × 3 × 7 = 42.
 *
 * We shall define the triplet of positive integers (a, b, c) to be an abc-hit if:
 *
 * GCD(a, b) = GCD(a, c) = GCD(b, c) = 1
 * a < b
 * a + b = c
 * rad(abc) < c
 * For example, (5, 27, 32) is an abc-hit, because:
 *
 * GCD(5, 27) = GCD(5, 32) = GCD(27, 32) = 1
 * 5 < 27
 * 5 + 27 = 32
 * rad(4320) = 30 < 32
 * It turns out that abc-hits are quite rare and there are only thirty-one abc-hits for c < 1000, with ∑c = 12523.
 *
 * Find ∑c for c < 120000.
 */

const int kMaxNum = 120000;

#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
#include <map>

#include "my_lib.h"

using namespace std;

typedef long long int ll;

set<int> GetSetFactor(int num, map<int, set<int>> &all_factors){

	if (all_factors.find(num) != all_factors.end()){
		//cout << "Returning from hashmap!" << endl;
		return all_factors[num];
	}
	else{
		cout << "Calculating factors!" << endl;
		factor_t tuple_factors = GetFactors(num);
		vector<int> factors = get<0> (tuple_factors);
		all_factors[num] = set<int>(
				make_move_iterator( factors.begin() ),
				make_move_iterator( factors.end() )
				);
		return 	all_factors[num];
	}
}

ll GetSetMultiply(set<int> in){
	ll out = 1;
	for (auto d : in)
		out *= d;
	return out;
}

bool IntersectionIsEmpty(set<int> f, set<int> s){
	vector<int> intersect;
	set_intersection(f.begin(), f.end(), s.begin(), s.end(),
			back_inserter(intersect));

	return intersect.size() == 0;
}

int main(){


	ll out = 0;
	map<int, set<int>> all_factors;
	for (int a = 1; a < kMaxNum; a++)
		for (int b = a+1; b < kMaxNum-a; b++){
			if (a % 2 == 0 && b % 2==0)
				continue;
			int c = a+b;
			if (a%101 == 0 && b % 1001 == 0)
				cout << "a:" << a << ", b : " << b << endl;
			set<int>  a_div = GetSetFactor(a, all_factors),
					  b_div = GetSetFactor(b, all_factors),
					  c_div = GetSetFactor(c, all_factors);
			if (GetSetMultiply(a_div)*GetSetMultiply(b_div)*GetSetMultiply(c_div) < c)
				if(
						IntersectionIsEmpty(a_div, b_div) &&
						IntersectionIsEmpty(a_div, c_div) &&
						IntersectionIsEmpty(b_div, c_div) 
				  )

					out += c;
		}

	cout << "The summation of abc-hits for c < " << kMaxNum << " is " << out << endl;
	return 0;


}

