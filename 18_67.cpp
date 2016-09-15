//By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.
//
//3
//7 4
//2 4 6
//8 5 9 3
//
//That is, 3 + 7 + 4 + 9 = 23.
//
//Find the maximum total from top to bottom of the triangle below:
//
//75
//95 64
//17 47 82
//18 35 87 10
//20 04 82 47 65
//19 01 23 75 03 34
//88 02 77 73 07 63 67
//99 65 04 28 06 16 70 92
//41 41 26 56 83 40 80 70 33
//41 48 72 33 47 32 37 16 94 29
//53 71 44 65 25 43 91 52 97 51 14
//70 11 33 28 77 73 17 78 39 68 17 57
//91 71 52 38 17 14 91 43 58 50 27 29 48
//63 66 04 68 89 53 67 30 73 16 69 87 40 31
//04 62 98 27 23 09 70 98 73 93 38 53 60 04 23
//
//NOTE: As there are only 16384 routes, it is possible to solve this problem by trying every route. However, Problem 67, is the same challenge with a triangle containing one-hundred rows; it cannot be solved by brute force, and requires a clever method! ;o)

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

#include "readData.h"

using std::vector;		using std::max_element;
using std::string;		

vector<vector<int> > ReadData(string filename, int &numRow);

int main(){
		//Reading the data.
		int numRow;
		vector<vector<int> > numbers = ReadData("p067_triangle.txt", numRow);
		//Defining a vector containing the best sums for each element of each row.
		vector<vector<long> > bestSums(numRow);

		//For each row, calculating the best sum for each element by comparing the value of the parents.
		//The only element on the first row.
		bestSums[0].push_back(numbers[0][0]);
		for (int rowCounter = 1; rowCounter < numRow; rowCounter++){
				vector<long> &prevRow = bestSums[rowCounter-1];
				vector<long> &curRow = bestSums[rowCounter];
				//Special case: First element:
				curRow.push_back(prevRow[0]+numbers[rowCounter][0]);
				//General case:
				int rowSize = numbers[rowCounter].size();
				for (int elementCounter = 1; elementCounter < rowSize-1; elementCounter++){
						long bestPreviousSum = prevRow[elementCounter-1] > prevRow[elementCounter] ? prevRow[elementCounter-1] :  prevRow[elementCounter];
						curRow.push_back(bestPreviousSum+numbers[rowCounter][elementCounter]);
				}

				//Special case: last element
				curRow.push_back(prevRow[rowSize-2]+numbers[rowCounter][rowSize-1]);	
		}

		//Outputting the max sum as the largest element in the last row.
		vector<long>::iterator max_elem = max_element(bestSums[numRow-1].begin(), bestSums[numRow-1].end());

		std::cout << "The largest path sum is : " << *max_elem << std::endl;
		
		return 0;
}

