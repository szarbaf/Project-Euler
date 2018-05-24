/* The decimal number, 585 = 10010010012 (binary), is palindromic in both bases.
 *
 * Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.
 *
 * (Please note that the palindromic number, in either base, may not include leading zeros.)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


constexpr int kMaxNum = 1e6;


vector<int> GetDigitsInBase(int c, int base){
		vector<int> out;
		while(c != 0){
				out.push_back(c%base);
				c /= base;
		}

		reverse(out.begin(), out.end());

		return out;
}

bool IsPalindrome(vector<int> in){
		int l=0, r=in.size()-1;
		while( l < r)
				if (in[l++] != in[r--])
						return false;

		return true;

}

int main(){

		long long int sum = 0;
		for (int c = 1; c < kMaxNum; c++){

				vector<int>	 decimal_digits = GetDigitsInBase(c, 10);
				vector<int> binary_digits = GetDigitsInBase(c, 2);

				if (IsPalindrome(decimal_digits) && IsPalindrome(binary_digits)){
						cout << "The number " << c << " or in binary format ";
						for (auto d : binary_digits)
								cout << d;
						cout << " is dual palindromic!" << endl;
						sum += c;
				}
				//cout << "Number " << c << " is done." << endl;
		}

		cout << "\n The sum of all dual palindromic numbers under " << kMaxNum << " is " << sum << endl;
		return 0;

}
