#include <vector>
#include <cmath>
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
