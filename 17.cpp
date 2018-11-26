//If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
//
//If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
//
//
//NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.

#include <iostream>
#include <vector>
#include <map>
#include <string>

using std::cout;		using std::endl;
using std::vector;		using std::map;
using std::string;		using std::to_string;
using std::cin;

int numberOfLetters(string number, map<string, int> *mp);
map<string, int> num2numLetters();
bool testNumberOfLetters();

int main(){

	long sum = 0;

	//Creating a map of numbers to number of letters.
	map<string, int> mp = num2numLetters();

	//Testing numberOfLetters function.
	bool pass = testNumberOfLetters();
	if (!pass)
		return -1;
	cout << "All the test cases passed!" << endl;

	int totalNumber;
	cout << "Please enter the total number." << endl;
	cin >> totalNumber;

	//Going from 1 through totalNumber adding the number of letters.
	for (int numberCounter = 0; numberCounter < totalNumber; numberCounter++){
		int test = numberOfLetters(to_string(numberCounter+1), &mp);
		if (test == -1)
			return -1;
		sum += test;

	}

	cout << "The total number of letters for numbers 1 through " << totalNumber << " is : " << sum << endl;
}

map<string, int> num2numLetters(){

	map<string, int> mp;
	
	//Adding single digit numbers.
	mp["1"] = 3;
	mp["2"] = 3;
	mp["3"] = 5;
	mp["4"] = 4;
	mp["5"] = 4;
	mp["6"] = 3;
	mp["7"] = 5;
	mp["8"] = 5;
	mp["9"] = 4;

	//Adding two digit numbers.
	mp["10"] = 3;
	mp["11"] = 6;
	mp["12"] = 6;
	mp["13"] = 8;
	mp["14"] = 8;
	mp["15"] = 7;
	mp["16"] = 7;
	mp["17"] = mp["7"] + 4;
	mp["18"] = 8;
	mp["19"] = mp["9"] + 4;
	
	mp["20"] = 6;
	mp["30"] = 6;
	mp["40"] = 5;
	mp["50"] = 5;
	mp["60"] = mp["6"] + 2;
	mp["70"] = mp["7"] + 2;
	mp["80"] = 6;
	mp["90"] = mp["9"] + 2;

	//Adding three digits numbers.
	mp["100"] = 7;

	//Adding four digits numbers.
	mp["1000"] = 8;

	return mp;

}

int numberOfLetters(string number, map<string, int> *mp){

	int numDigits = number.size();
	int sum = 0;

	map<string, int>::iterator it;
	//Special case: Single digit number.
	if (numDigits == 1){
		it = mp->find(number);
		if (it == mp->end()){
			cout << "Number " << number << "not found." << endl;
			return -1;
		}
		return it->second;
	}

	//For counting the number of "and".
	int andCounter = 0;

	//Adding the number of letters of the two last digits
	string twoLast = number.substr(numDigits-2, 2);
	int num = std::stoi(twoLast);

	if (num < 20 && num >= 10){
		it = mp->find(twoLast);
		if (it == mp->end()){
			cout << "Two last number " << twoLast << "not found." << endl;
			return -1;
		}
		andCounter++;
		sum += it->second;
	}
	else if (number.substr(numDigits-2,2) != "00"){
		//First digit
		if (number.substr(numDigits-1,1) != "0"){
			it = mp->find(number.substr(numDigits-1, 1));
			if (it == mp->end()){
				cout << "Two last number's firt one: " << twoLast << "not found." << endl;
				return -1;
			}
			andCounter++;
			sum += it->second;
		}

		//Second digit
		if (number.substr(numDigits-2,1) != "0"){
			it = mp->find(number.substr(numDigits-2, 1)+"0");
			if (it == mp->end()){
				cout << "Two last number's second one: " << twoLast << "not found." << endl;
				return -1;
			}	
			sum += it->second;
		}
	}

	//Other numbers.
	if (numDigits >= 3 && number.substr(numDigits-3, 3) != "000"){
		string third = number.substr(numDigits-3, 1);
		it = mp->find(third);
		if (it == mp->end()){
			cout << "The third last number " << third << "not found." << endl;
			return -1;
		}
		//Adding "hundred" and "and"
		sum += it->second + mp->find("100")->second + andCounter*3;
		andCounter = 1;
	}

	if (numDigits == 4){
		string fourth = number.substr(numDigits-4, 1);
		it = mp->find(fourth);
		if (it == mp->end()){
			cout << "The fourth last number " << fourth << "not found." << endl;
			return -1;
		}
		//Adding "thousand" and "and"
		sum += it->second + mp->find("1000")->second + andCounter*3;
	}

	return sum;

}

typedef struct test{
	string number;
	int count;
} test_t;


#define NUMTESTCASES 5
bool testNumberOfLetters(){
	
	test_t tcs[] = {{"3", 5}, {"13", 8}, {"124", 23}, {"201", 16}, {"1000", 11}};
	map<string, int> mp = num2numLetters();

	for (int testCounter = 0; testCounter < NUMTESTCASES; testCounter++){
		test_t tc = tcs[testCounter];
		int numberLetters = numberOfLetters(tc.number, &mp);
		if (tc.count != numberLetters){
			cout << "numberOfLetters(" << tc.number << ") = " << numberLetters << " expected : " << tc.count << endl;
			return false;
		}
	}

	return true;
	
}
