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

//constexpr long int kMaxNum = 987654321;
constexpr long int kMaxNum = 1e7;

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

int main(){

		unordered_set<int> seen;
		long long out = 0;
		for (int i = 1; i < kMaxNum+1; i++){
				for (int j = i; i*j < kMaxNum+1; j++)
						if (IsPanDigital(i, j, i*j) && seen.find(i*j) == seen.end()){
								out += i*j;
								seen.insert(i*j);
						}
		}

		cout << "The sum of pandigital products under " << kMaxNum << " is " << out << endl;
		return 0;

}
