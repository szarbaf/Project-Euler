#include <vector>
#include "big_number.h"
#include <ostream>

using namespace std;
typedef long long int lli;

BigNumber::BigNumber(lli num){

	while( num > 0){
		digits_.push_back(num%10);
		num = num / 10;
	}

}

BigNumber BigNumber::operator+(const BigNumber& that){

	BigNumber out;

	vector<int>::size_type common_num_digits = max(this->digits_.size(), that.digits_.size());
	int carry_over = 0;
	for (vector<int>::size_type c = 0; c < common_num_digits; c++){
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
