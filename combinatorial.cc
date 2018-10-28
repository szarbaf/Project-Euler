#include <vector>
#include <climits>
#include <algorithm>

#include "combinatorial.h"


using namespace std;


//-----------------Permutate Class-----------------//

Permutate::Permutate(int n){
	state.reserve(n+1);
	for (int c = 0; c < n+1; c++)
	  state.push_back(c);
}

void Permutate::Next(){
	if (state.size() < 2)
		return;

	const int kMaxDigits = state.size();
	int i = kMaxDigits - 1, min_index, min_val = INT_MAX;
	bool found = false;
	while(i >= 0 && !found){
		i--;
		for (int j = i+1; j < kMaxDigits; j++)
			if (state[i] < state[j]){
				found = true;
				if (state[j] < min_val){
					min_val = state[j];
					min_index = j;
				}
			}
	}

	if (!found)
		return;

	// Swapping the values.
	iter_swap(state.begin()+i, state.begin()+min_index);

	// Sorting values of the array from i+1 to the end in an acsending order.
	sort(state.begin()+i+1, state.end()) ;

	return;
}

vector<int> Permutate::Permute(const vector<int>& digits){
	int size = digits.size();
	vector<int> out(size);

	for (int c = 0; c < size; c++)
	  out[c] = digits[state[c]];

	return out;
}

//-----------------Choose Class-----------------//
