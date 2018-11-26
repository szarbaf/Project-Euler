/*
	 A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:

	 1/2	=	0.5
	 1/3	=	0.(3)
	 1/4	=	0.25
	 1/5	=	0.2
	 1/6	=	0.1(6)
	 1/7	=	0.(142857)
	 1/8	=	0.125
	 1/9	=	0.(1)
	 1/10	=	0.1
	 Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.

	 Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
	 */

#include <iostream>
#include <cmath>

using namespace std;

#define MAXNUM 1000
#define MAXTRY 1e4


int CalcCycleLength(int num){

	int pow = 1;
	int remainder = 10 % num;

	while(remainder != 1 && pow < MAXTRY){
		remainder *= 10;
		remainder %= num;
		pow += 1;
	}

	if (pow != MAXTRY)
		return pow;
	else
		return -1;

}




int main(){

	
	int max_cycle_length = 0, max_d = -1;

	for (int c = 3; c < MAXNUM+1; c++){
	
		if (c % 2 ==0 || c % 5 == 0)
			continue;

		int cycle_length = CalcCycleLength(c);

		if (cycle_length > max_cycle_length){
			max_d = c;
			max_cycle_length = cycle_length;
		}
	}


	cout << "The number with the largest pattern is : " << max_d << endl;
	cout << "The pattern lenght is : " << max_cycle_length << endl;


	return 0;
}

