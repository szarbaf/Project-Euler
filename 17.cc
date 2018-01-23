/*
 * If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
 *
 * If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
 *
 *
 * NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

#define MAXNUM 1000

int NumberOfLetters(int number){

		unordered_map<int,int> one_digit_letter_count = {
				{0, 4}, {1, 3}, {2, 3}, 
				{3, 5}, {4, 4}, {5, 4}, 
				{6, 3}, {7, 5}, {8, 5}, 
				{9, 4}};
		
		unordered_map<int,int> two_digit_letter_count = {
				{10, 3}, {11, 6}, {12, 6}, 
				{13, 8}, {14, 8}, {15, 7}, 
				{16, 7}, {17, 9}, {18, 8}, 
				{19, 8}, {20, 6}, {30, 6},
				{40, 5}, {50, 5}, {60, 5},
				{70, 7}, {80, 6}, {90, 6}
		};

		int letter_count = 0;
		
		if (number == 1000)
				//one thousand
				return 11;

		if (number >= 100){
				// 7 -> hundred
				letter_count += one_digit_letter_count[number/100] + 7;
				if (number % 100 != 0)
						// and -> 3
						letter_count += 3;
		}
		if (number >= 10 && number%100 != 0){
			
			int first_digit = number % 10;
			int second_digit = (number % 100 - first_digit)/10;
			if (second_digit >= 2){
					letter_count += two_digit_letter_count[second_digit*10];
					if (first_digit != 0)
						letter_count += one_digit_letter_count[first_digit];
			}
			else if (second_digit != 0)
					letter_count += two_digit_letter_count[number%100];
			else letter_count +=one_digit_letter_count[first_digit];


		}
		else if (number < 10)
				letter_count += one_digit_letter_count[number];

		return letter_count;
		
} 


int main(){

		int total_letter_count = 0;
		for (int c = 1; c < MAXNUM+1; c++)
				total_letter_count += NumberOfLetters(c);

		cout << "The sum of total number of letters between 1 and " 
				<< MAXNUM << " is " << total_letter_count << endl;

		return 0;
}
