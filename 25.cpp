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
#include <ostream>
#include <math.h>

using namespace std;
typedef long long int lli;

#define NUM_DIGITS 1000

class BigNumber{

	public:
		BigNumber() {}
		BigNumber(lli);

		BigNumber operator+(const BigNumber&);
		int NumDigits() {return digits_.size();}

		// The digits are stored reversely in digits_:
		// 321 -> digits[0] = 3, digits[1] = 2, digits[2] = 3
		vector<int> digits_;

};

BigNumber::BigNumber(lli num){

	while( num > 0){
		digits_.push_back(num%10);
		num = num / 10;
	}

}

BigNumber BigNumber::operator+(const BigNumber& that){

	BigNumber out;

	int common_num_digits = max(this->digits_.size(), that.digits_.size());
	int carry_over = 0;
	for (int c = 0; c < common_num_digits; c++){
		int sum = carry_over;
		if (c < this->digits_.size())
			sum += this->digits_[c];
		if(c < that.digits_.size())
			sum += that.digits_[c];

		if (sum >= 10){
			sum -= 10;
			carry_over = 1;
		}
		else
			carry_over = 0;

		out.digits_.push_back(sum);
	}

	if (carry_over == 1)
		out.digits_.push_back(1);

	return out;

}

ostream& operator<< (ostream& out, const BigNumber& num){

	for (auto it = num.digits_.rbegin(); it != num.digits_.rend(); it++)
		out << *it;

	return out;
}

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
