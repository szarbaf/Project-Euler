/*In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:
 *
 * 1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
 * It is possible to make £2 in the following way:
 *
 * 1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
 * How many different ways can £2 be made using any number of coins?
 */

#include <iostream>
#include <vector>

using namespace std;

#define SUM 200

void CalcCointCounts(int sum, int currency_index, const vector<int> &currency, 
	vector<int> *cur_coin_counts, vector<vector<int>> *all_coin_counts){

  if(sum == 0){
	for (int c = 0; c < currency.size()-currency_index; c++)
	  cur_coin_counts->push_back(0);
	all_coin_counts->push_back(*cur_coin_counts);
	return;
  }

  if (currency_index >= currency.size())
	return;
  
  int cur_currency = currency[currency_index];
  for (int c = 0; sum-c*cur_currency>=0; c++){
  	auto new_coin_counts = *cur_coin_counts;
	new_coin_counts.push_back(c);
	CalcCointCounts(sum-c*cur_currency, currency_index+1, currency,
		&new_coin_counts, all_coin_counts);
  }


  
}

int main(){
  const vector<int> currency = {1, 2, 5, 10, 20, 50, 100, 200};
  vector<vector<int>> all_coin_counts;
  vector<int> cur_coin_counts;
  CalcCointCounts(SUM, 0, currency, 
	  &cur_coin_counts, &all_coin_counts);

  cout << "The number of different coin counts for the sum " << SUM << " is " << all_coin_counts.size() << endl;

  return 0;

}
