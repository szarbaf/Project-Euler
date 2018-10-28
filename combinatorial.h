#include <vector>

class Permutate{
	public :
	  // Initialize an object that can permutate numbers between 0 and n inclusive.
	  // state is initialized to 0, 1, ..., n
	  Permutate(int n); 
	  // Find the next permutation and return the state.
	  // The next permutation ins the smallest number that is larger than current state.
	  void Next();
	  // Permutate the digits using the state.
	  std::vector<int> Permute(const std::vector<int>& digits);

	private:
	  std::vector<int> state;
};
