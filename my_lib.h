#include <vector>
typedef long long int ll;

void SetNotPrime(std::vector<bool> *is_prime, ll num, ll max_num);

std::vector<bool> IsPrime(ll max_num, ll max_prime, ll *last_prime_index, ll *last_prime);
std::vector<bool> IsPrime(ll max_num);

std::vector<ll> FindDivisors(ll num);

std::vector<int> GetDigits(int num);

bool IsPanDigital(int num);

void NextLargestPanDigital(std::vector<int> &cur_pan_digital);

ll MyPowerMod(ll base, ll power, ll mod);

ll MyPowerLastDigits(ll base, ll power, int last_num_digits);

ll MyMultiplyLastDigits(ll a, ll b, int last_num_digits);
