#include <vector>
#include <ostream>


class BigNumber{

	public:
		BigNumber() {}
		BigNumber(long long int);

		BigNumber operator+(const BigNumber&);
		int NumDigits() {return digits_.size();}

		// The digits are stored reversely in digits_:
		// 321 -> digits_[2] = 3, digits_[1] = 2, digits_[0] = 3
		std::vector<int> digits_;

};

