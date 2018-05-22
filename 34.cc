/*145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.
 *
 * Find the sum of all numbers which are equal to the sum of the factorial of their digits.
 *
 * Note: as 1! = 1 and 2! = 2 are not sums they are not included.
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// There can be no number greater that 1e8 where the conditions holds : 10^(n-1) < n*9!
const int kMaxNum = pow(10, 8);
const vector<int> kFctorials = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

vector<int> GetDigits(int num){
	vector<int> out;
	while (num != 0){
		out.push_back(num%10);
		num /= 10;
	}
	return out;
}

bool IsCuriousNum(int num){

		vector<int> digits = GetDigits(num);
		int sum = 0;
		for (int d : digits)
				sum += kFctorials[d];

		if (sum == num)
				return true;
		else
				return false;
}

int main(){
	
		long long int out = 0;
		for (int c = 10; c < kMaxNum; c++)
				if (IsCuriousNum(c)){
					cout << c << " is a curious number!" << endl;
					out += c;
				}

		cout << "The sum of the curious numbers is : " << out << endl;
		return 0;


}
