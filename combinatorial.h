#include <vector>

typedef long long int ll;
ll Factorial (int c);

class Permutate{
	public :
	  // Initialize an object that can permutate numbers between 0 and n inclusive.
	  Permutate(){}
	  // state is initialized to 0, 1, ..., n
	  Permutate(int n);
	  // Reset the object to permutate n objects;
	  void Reset(int n);
	  // Find the next permutation and return the state.
	  // The next permutation ins the smallest number that is larger than current state.
	  void Next();
	  // Permutate the digits using the state.
	  std::vector<int> Permute(const std::vector<int>& digits);

	  ll Size() {return size_;}

	private:
	  std::vector<int> state_;
	  ll size_;
};

class Choose{

	public:
	  Choose(){}
	  // Initializing to an object for choosing all possible ways of choosing k numbers from 1,...,n.
	  Choose(int n, int k);
	  
	  // Returning the next choose in the series.
	  std::vector<int> Next();

	  ll Size() {return size_;}

	private:
	  std::vector<int> state_;
	  int n_, k_, size_;
};
