#include <vector>
#include <climits>
#include <algorithm>

#include "combinatorial.h"


using namespace std;

ll Factorial(int n){
	ll out=1;
	for (int c = 2; c < n+1; c++)
	  out *= c;

	return out;
}

//-----------------Permutate Class-----------------//

Permutate::Permutate(int n){
	state_.reserve(n+1);
	for (int c = 0; c < n+1; c++)
	  state_.push_back(c);

	size_ = Factorial(n+1);
}

void Permutate::Reset(int n){
	state_.clear();
	state_.reserve(n+1);
	for (int c = 0; c < n+1; c++)
	  state_.push_back(c);

	size_ = Factorial(n+1);
}

void Permutate::Next(){
	if (state_.size() < 2)
		return;

	const int kMaxDigits = state_.size();
	int i = kMaxDigits - 1, min_index, min_val = INT_MAX;
	bool found = false;
	while(i > 0 && !found){
		i--;
		for (int j = i+1; j < kMaxDigits; j++)
			if (state_[i] < state_[j]){
				found = true;
				if (state_[j] < min_val){
					min_val = state_[j];
					min_index = j;
				}
			}
	}

	if (!found)
		return;

	// Swapping the values.
	iter_swap(state_.begin()+i, state_.begin()+min_index);

	// Sorting values of the array from i+1 to the end in an acsending order.
	sort(state_.begin()+i+1, state_.end()) ;

	return;
}

vector<int> Permutate::Permute(const vector<int>& digits){
	int size = digits.size();
	vector<int> out(size);

	for (int c = 0; c < size; c++)
	  out[c] = digits[state_[c]];

	return out;
}

//-----------------Choose Class-----------------//
//
Choose::Choose(int n, int k) : n_(n), k_(k){
	state_.reserve(k);
	for (int c = 1; c < k; c++)
  		state_.push_back(c);
	state_.push_back(k-1);
	size_ = Factorial(n) / (Factorial(k)*Factorial(n-k));	
}

vector<int> Choose::Next(){
	
	bool found = false;

	int j = k_-1;
	while (j >= 0){
	  if (state_[j] < (n_ + j + 1 - k_ ) )
	  {
		found = true;
		break;
	  }
	  j--;
	}

	if (j < 0 || !found)
	  return state_;

	state_[j]++;
	for (int i = j; i < k_-1; i++)
	  state_[i+1] = state_[i] + 1;

	return state_;

}
