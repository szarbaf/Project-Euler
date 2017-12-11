#include <vector>
typedef long long int ll;

using namespace std;

void SetNotPrime(vector<bool> *is_prime, ll num, ll max_num){
		for (ll c = (num+1)*(num+1)-1; c < max_num; c += num+1)
				is_prime->at(c) = false;
}

vector<bool> IsPrime(ll max_num, ll max_prime, ll *last_prime_index, ll *last_prime){
		vector<bool> is_prime(max_num, true);

		is_prime[1] = true;
		ll cur_prime = -1;
		ll cur_prime_counter = 0;
		for (int num = 1; num < max_num; num++){
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

