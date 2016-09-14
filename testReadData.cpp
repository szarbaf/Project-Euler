#include <iostream>
#include "readData.h"

using std::vector;		using std::cout;
using std::endl;		using std::string;

int main(){

		int numRows;
		vector<vector<int> > testOut = ReadData(string("18.dat"), numRows);
		for (vector<vector<int> >::iterator it = testOut.begin(); it != testOut.end(); it++)
			cout << (*it)[0] << endl;

		return 0;

}
