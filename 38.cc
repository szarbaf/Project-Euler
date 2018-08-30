/*
 * Take the number 192 and multiply it by each of 1, 2, and 3:
 *
 * 192 × 1 = 192
 * 192 × 2 = 384
 * 192 × 3 = 576
 * By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated product of 192 and (1,2,3)
 *
 * The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).
 *
 * What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2, ... , n) where n > 1?
 */

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

void NextLargestPanDigital(vector<int> &cur_pan_digital){

	// This function returns the next permutation of a pandigital number. Specifically, it modifies the input
	// to contain largest pandigital number that is smaller than cur_pan_digital.


	// Starting from the one to the last digit, finding the highest index i for which there is at least
	// an index j where 
	// 1- cur_pan_digital[i] < cur_pan_digital[j] 
	// 2- j > i, i.e. j \in [i+1, i+2, ..., size-1].
	// Among all the indices j for a praticular value of i, the j with the highest value of cur_pan_digital[j] is returned.
	// For example for 15342 the max_index is 3 corresponding to the digit 4.
	
	if (cur_pan_digital.size() < 2)
		return;
	const int kMaxDigits = cur_pan_digital.size();
	int i = kMaxDigits - 1, max_index, max_val = INT_MIN;
	bool found = false;
	while(i >= 1 && !found){
		i--;
		for (int j = i+1; j < kMaxDigits; j++)
			if (cur_pan_digital[i] > cur_pan_digital[j]){
				found = true;
				if (cur_pan_digital[j] > max_val){
					max_val = cur_pan_digital[j];
					max_index = j;
				}
			}
	}

	if (!found)
		return;

	// Swapping the values.
	iter_swap(cur_pan_digital.begin()+i, cur_pan_digital.begin()+max_index);

	// Sorting values of the array from i+1 to the end in a descending order.
	sort(cur_pan_digital.begin()+i+1, cur_pan_digital.end(), greater<int>()) ;

	return;

	
}

int main() {

	vector<int> cur_pan_digital = {9, 8, 7, 6, 5, 4, 3, 2, 1};
	while (!IsConcatProduct(cur_pan_digital))
		NextLargestPanDigital(cur_pan_digital);

	cout << " The largest pan digital as a concatenation form is : ";
	for (auto d : cur_pan_digital)
		cout << d;
	cout << endl;

	return 0;
	

}
