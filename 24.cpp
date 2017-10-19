/*
A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
*/

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


#define NUM 1000000
#define NUMDIGS 10
#define NUMFACS 10

typedef long int l;

void PermHelper(int rem_num, const vector<int> &rem_digits, const vector<l> &facs, vector<int> *out){
	if (rem_num <= 0 || rem_digits.size() == 0)
		return;
	if (rem_digits.size() == 1){
		out->push_back(rem_digits[0]);
		return ;
	}
	
	
	int size = rem_digits.size();
	l fac = facs[size-2];
	int num_rep = ceil(rem_num / (double)fac) - 1;
	out->push_back(rem_digits[num_rep]);
	auto new_rem_digits = rem_digits;
	new_rem_digits.erase(new_rem_digits.begin() + num_rep);
	PermHelper(rem_num - num_rep*fac, new_rem_digits, facs, out);

}

vector<int> Perm(l num, int num_digits){

	vector<l> facs;
	facs.push_back(1);
	for(int i = 1; i < NUMFACS; i++)
		facs.push_back(facs[i-1]*(i+1));

	vector<int> rem_digits;
	for (int i = 0; i < NUMDIGS; i++)
		rem_digits.push_back(i);

	vector<int> out;
	PermHelper(num, rem_digits, facs, &out);

	return out;
}

int main(){


	auto out = Perm(NUM, NUMDIGS);
	cout << "The " << NUM << " permutation using " 
		<< NUMDIGS << " digits is : " ;
	for (auto it = out.begin(); it != out.end(); it++)
		cout << *it;
	cout << endl;

	return 0;

}
