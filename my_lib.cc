#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

#include "my_lib.h"

typedef long long int ll;

using namespace std;

void SetNotPrime(vector<bool> *is_prime, ll num, ll max_num){
		for (ll c = (num+1)*2-1; c < max_num; c += num+1)
				is_prime->at(c) = false;
}

vector<bool> IsPrime(ll max_num, ll max_prime, ll *last_prime_index, ll *last_prime){
		vector<bool> is_prime(max_num, true);

		is_prime[0] = false;
		ll cur_prime = -1;
		ll cur_prime_counter = 0;
		for (int num = 1; num*num < max_num; num++){
				if (is_prime[num]){
						SetNotPrime(&is_prime, num, max_num);
						cur_prime = num;
						cur_prime_counter += 1;
						if (cur_prime_counter == max_prime)
								break;
				}

		}
		*last_prime_index = cur_prime_counter;
		*last_prime = cur_prime+1;
		return is_prime;
}

vector<bool> IsPrime(ll max_num){

		ll last_prime, last_prime_index;
		return IsPrime(max_num, max_num, &last_prime_index, &last_prime);

}

vector<ll> FindDivisors(ll num){
	ll max_num = sqrt(num);
	vector<ll> output(max_num*2);

	
	ll counter = 0;
	for (ll c = 1; c < max_num+1; c++){
		if (num%c == 0)
				output[counter++] = c;
	}

	//Adding the complements
	for (ll c = 0; c < counter; c++){
		if (output[c] != max_num){
			output[c+counter] = num / output[counter - 1 - c];
		}
	}

	//Resizing
	if (max_num*max_num != num)
			output.resize(2*counter);
	else
			output.resize(2*counter-1);


	return output;
}

vector<int> GetDigits(int num){
	vector<int> out;
	while (num > 0){
		out.push_back(num%10);
		num /= 10;
	}
	reverse(out.begin(), out.end());
	return out;
}

ll GetNum(vector<int> digits){
	ll out = 0;
	for (auto d : digits)
	  out = 10*out + d;

	return out;
}

bool IsPanDigital(int num){
	vector<int> digits = GetDigits(num);
	sort(digits.begin(), digits.end());
	for (int c = 1; c < static_cast<int>(digits.size())+1; c++)
	  if ( !(digits[c-1] == c) )
		return false;

	return true;
}

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

ll MyPowerMod(ll base, ll power, ll mod){
	ll output = 1;
	while (power > 0){
		if (power%2==1)
			output = (output*base) % mod;
		base = (base*base) % mod;
		power /= 2;
	}

	return output;
}

ll MyPowerLastDigits(ll base, ll power, int last_num_digits){
	ll output = 1;
	while (power > 0){
		if (power%2==1)
			output = MyMultiplyLastDigits(output, base, last_num_digits);
		base = MyMultiplyLastDigits(base, base, last_num_digits);
		power /= 2;
	}

	return output;
}

ll MyMultiplyLastDigits(ll a, ll b, int last_num_digits){

  // a = (1e(last_num_digit/2+1) a1 + a2)
  // b = (1e(last_num_digit/2+1) b1 + b2)
  // a*b = 1e(last_num_digit+2)a1*b1 + (a1*b2+a2*b1)*1e(last_num_digit/2+1) + a2*b2 
  // a*b % 1e(last_num_digits) = (a1*b2+a2*b1)*1e(last_num_digit/2+1) + a2*b2

	int half_d = last_num_digits/2+1;
	ll pow_half_d = static_cast<ll> (pow(10, half_d));
	ll pow_d = static_cast<ll> (pow(10, last_num_digits));

	ll a2 = a%pow_half_d, b2 = b%pow_half_d;
	ll a1 = a-a2, b1 = b-b2;

	ll output = ((a1*b2)%pow_d + (a2*b1)%pow_d)%pow_d;
	output = (output + (a2*b2)%pow_d) % pow_d;

	return output;
}


