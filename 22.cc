//Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

//For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

//What is the total of all the name scores in the file?

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctype.h>
#include <algorithm>

using namespace std;

bool IsNameSmaller(string first, string second){
	auto compare_val = first.compare(second);
	if (compare_val < 0)
		return 1;
	else
		return 0;
}



vector<string> ReadFileNamesAndSort(string filename){

	ifstream fp;
	fp.open(filename);

	if (!fp.is_open()){
		cout << "Could not open the file : " << filename << endl;
		return vector<string>();
	}

	vector<string> output;

	while(!fp.eof()){
		char temp[100];
		fp.getline(temp, 100, ',');
		string temp_string(temp);
		output.push_back(temp_string.substr(1, temp_string.size() - 2));
	}
	sort(output.begin(), output.end(), IsNameSmaller);
	return output;
}


long CalculateScore(string name){

	if (name.size() == 0)
		return 0;

	long score = 0;
	for (auto it = name.begin(); it != name.end(); it++)
		score += tolower(*it) - 'a' + 1;

	return score;
}

int main(){

	//Reading the input file.
	auto names = ReadFileNamesAndSort("p022_names.txt");
	//Going through the names and calculating the total scores.
	long total_score = 0;
	long counter = 1;
	for (auto it = names.begin(); it != names.end(); it++){
		long score = CalculateScore(*it);
		total_score += score*counter;
		counter++;
	}
	cout << total_score << endl;
	return 0;
}
