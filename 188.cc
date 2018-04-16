/*
The hyperexponentiation or tetration of a number a by a positive integer b, denoted by a↑↑b or ba, is recursively defined by:

a↑↑1 = a,
a↑↑(k+1) = a(a↑↑k).

Thus we have e.g. 3↑↑2 = 33 = 27, hence 3↑↑3 = 327 = 7625597484987 and 3↑↑4 is roughly 103.6383346400240996*10^12.

Find the last 8 digits of 1777↑↑1855.
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define HYPER_EXP_POWER 1855
#define BASE 1777
#define MAX_DIGITS 8

typedef unsigned long long int ulli;


ulli CalcPeriod(ulli base, ulli mod_num){
	vector<bool> seen(mod_num, false);
	ulli counter = 0, cur = base%mod_num;
	while (seen[cur-1] != true){
		seen[cur-1] = true;
		cur = (cur*base)%mod_num;
		counter++;
	}

	return counter;
}


ulli PowerMod(ulli base, ulli power, ulli mod_num){
	ulli out = base;
	for (ulli c = 0; c < power-1; c++){
		out *= base;
		out = out%mod_num;
	}

	return out;
}

ulli PowerPeriod(ulli base, ulli num_base_power, ulli last_power, ulli period){

  if (num_base_power > 0 ){
  ulli new_last_power = PowerMod(base, last_power%period, period);
	return PowerPeriod(base, num_base_power-1, new_last_power, period);

  }
  else{
	ulli new_last_power = PowerMod(base, last_power%period, (ulli) pow(10, MAX_DIGITS));
	return new_last_power;
  }
	
}

int main(){
	
	ulli period = CalcPeriod(BASE, pow(10, MAX_DIGITS));

	cout << "The last " << MAX_DIGITS << " digits of " << BASE << "^^" << HYPER_EXP_POWER 
	  << " is " << PowerPeriod(BASE, HYPER_EXP_POWER-2, BASE, period) << "." << endl;

	return 0;
	  

}
