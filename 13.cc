//Work out the first ten digits of the sum of the following one-hundred 50-digit numbers. (see 13.dat)

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "big_number.h"

using namespace std;

vector<BigNumber> ReadData(string filename){
	ifstream fp(filename);

	string line;
	BigNumber sample_element;
	sample_element.digits_.resize(50);
	vector<BigNumber> out(100, sample_element);
	int counter = 0;
	while (getline(fp, line)){
		int i = 0;
		for (auto c = line.begin(); c != line.end(); c++){
		  out[counter].digits_[50 - i - 1] = *c-'0';
		  i++;
		}
		counter++;
	}

	return out;
}

int main() {

  vector<BigNumber> data = ReadData("13.dat");

  BigNumber result(0);

  for (auto it = data.begin(); it != data.end(); it++)
	result = result + *it;


  cout << "The 10 letters for the sum is ";
  for (int c = 0; c < 10; c++)
	cout << result.digits_[result.NumDigits() - c - 1];
  cout << endl;

  return 0;

}

