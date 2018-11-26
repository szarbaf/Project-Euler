/*
 * We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.
 *
 * The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.
 *
 * Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.
 *
 * HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.
 */


#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

constexpr long int kMaxNum = 987654321;
//constexpr long int kMaxNum = 1e5;

typedef long long int ll;

vector<int> GetDigits(unsigned long num){
		vector<int> out;
		while (num != 0){
				out.push_back(num%10);
				num /= 10;
		}
		return out;
}

inline int CrossDigits(vector<bool> &all_digits, const vector<int> &cur_digits){
		int out = 0;
		for (auto d : cur_digits){
				if (d != 0 && all_digits[d-1] == true)
						return -1;
				if (d != 0)
				{
						all_digits[d-1] = true;
						out += 1;
				}
		}

		return out;
}

bool IsPanDigital(long i, long j, long ixj){
		auto i_digits = GetDigits(i);
		auto j_digits = GetDigits(j);
		auto ixj_digits = GetDigits(ixj);

		vector<bool> digits(9, false);
		int total_num = 0;

		int temp = CrossDigits(digits, i_digits);
		if (temp != -1)
				total_num += temp;
		else
				return false;
		temp = CrossDigits(digits, j_digits);
		if (temp != -1)
				total_num += temp;
		else
				return false;
		temp = CrossDigits(digits, ixj_digits);
		if (temp != -1)
				total_num += temp;
		else
				return false;

		if (total_num == 9)
				return true;
		else
				return false;
}

template<class T>
void PermutateHelper(
				const vector<T> &cur_vals, 
				const vector<T> &rem, 
				vector<vector<T>> &output){
		if (rem.size() == 0){
				output.push_back(cur_vals);
				return;
		}

		for (int c = 0; c < rem.size(); c++){
			vector<int> new_cur_vals = cur_vals;
			new_cur_vals.push_back(rem[c]);
			vector<T> new_rem(rem.begin(), rem.begin()+c);
			if (c != rem.size()-1 )
			   	new_rem.insert(new_rem.end(), rem.begin()+c+1, rem.end());

			//cout << "c : " << c << " rem.size() : " << rem.size() << endl;
			PermutateHelper(new_cur_vals, new_rem, output);
		}
}

template<class T>
vector<vector<T> >Permutate(const vector<T>& in){
	
	vector<vector<T> > output;
	vector<T> cur_vals;
	PermutateHelper(cur_vals, in, output);
	return output;

}


ll FromDigits(vector<int> in){
	ll out = 0;
	for (auto num : in){
		out = 10*out + num;
	}

	return out;
}

int main(){

		unordered_set<ll> seen;
		long long out = 0;
		vector<vector<int> > perms = Permutate(vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9}) );
		for (auto perm : perms){
			for(int i = 1; i < 9; i++)
					for (int j = i+1; j < 9; j++){
				
				ll a = FromDigits( vector<int>(perm.begin(), perm.begin()+i) );
				ll b = FromDigits( vector<int>(perm.begin()+i, perm.begin()+j) );
				ll aXb = FromDigits( vector<int>(perm.begin()+j, perm.end()) );
				if (a*b == aXb && IsPanDigital(a, b, aXb) && seen.find(aXb) == seen.end()){
					seen.insert(aXb);
					if (aXb < kMaxNum)
						cout << a << " " << b << " " << aXb << endl;
					out += aXb;
				}

					}
		}

		cout << "The sum of pandigital products under " << kMaxNum << " is " << out << endl;
		return 0;

}
