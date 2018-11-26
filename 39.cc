/* If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.

{20,48,52}, {24,45,51}, {30,40,50}

For which value of p ≤ 1000, is the number of solutions maximised?
*/

#include <iostream>
#include <vector>
#include <cmath>

constexpr int kMaxNum = 1000;
constexpr double kRe = 1e-6;

using namespace std;

int main(){

	vector<int> counts(kMaxNum, 0);

	for (int a = 1; a < kMaxNum/2; a++)
	  for (int b = a+1; b < kMaxNum; b++){
	  	double c2 = a*a + b*b;
		double c = sqrt(c2);

		if (a+b+c <= kMaxNum && c - floor(c) < kRe){
		  counts[a+b+static_cast<size_t>(c) - 1] += 1;
		  //cout << "Found a:" << a << " b:" << b << " c:" << c << endl;
		}

	  }


	int max_i = -1, max = -1;
	for (int counter = 0; counter< kMaxNum;  counter++)
	  if (counts[counter] > max){
	  	max = counts[counter];
		max_i = counter+1;
	  }

	cout << "The number of possibilities for p=120 is : " << counts[119] << endl;

	cout << "The circumference with the highest number of side possibilities is " << max_i << endl;
	cout << "The count is " << max << endl;



	return 0;

}
