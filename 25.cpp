/*
The Fibonacci sequence is defined by the recurrence relation:

Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
Hence the first 12 terms will be:

F1 = 1
F2 = 1
F3 = 2
F4 = 3
F5 = 5
F6 = 8
F7 = 13
F8 = 21
F9 = 34
F10 = 55
F11 = 89
F12 = 144
The 12th term, F12, is the first term to contain three digits.

What is the index of the first term in the Fibonacci sequence to contain 1000 digits?
*/

#include <iostream>
#include <vector>
#include <math.h>
#include "big_number.h"

using namespace std;
typedef long long int lli;

#define NUM_DIGITS 1000

int main(){

	BigNumber first(1), second(1);
	int first_index = 1;
	int second_index = 2;
	while(second.NumDigits() < NUM_DIGITS){
		BigNumber tmp = first;
		first = second;
		second = first + tmp;
		first_index++;
		second_index++;
	}

	cout << "The index for the first Fibonacci number to contain " << NUM_DIGITS << " digits is : \n" 
		<< second_index << endl << "And the number is : " << second << endl;

	return 0;



}
