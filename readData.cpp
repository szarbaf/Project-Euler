#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <locale>

#include "readData.h"

using std::string;		using std::find_if;
using std::vector;		using std::getline;
using std::ifstream;	using std::find_if_not;
using std::isalnum;

vector<vector<int> > ReadData(string filename, int &numRow){

		std::ifstream filep(filename.c_str());

		vector <vector<int> > out;

		string line;
		numRow = 0;
		while(getline(filep, line)){
				numRow++;
				vector<string> tmp = split(line, ' ');
				vector<int> tmpNum;
				for(vector<string>::iterator it = tmp.begin(); it != tmp.end(); it++)
						tmpNum.push_back(std::stoi(*it));

				out.push_back(tmpNum);
		}

		return out;

}

bool is_alphanum(char in){
	return isalnum(in);
}

vector<string> split(string &line, char delim){

		string::iterator first, second, end;
		first = line.begin();
		end = line.end();

		vector<string> out;

		while( first != end ){
				//first is set to next alphanum char.
				if ((first = find_if(first, end, is_alphanum)) == end )
						break;
				//second is set to the next non alphanum char.
				if ((second = find_if_not(first, end, is_alphanum)) == end )
						break;

				out.push_back(string(first, second));
				first = second;

		}
		return out;
}
