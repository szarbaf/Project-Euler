#include <iostream>
#include <vector>
#include "combinatorial.h"

using namespace std;

int main(){

  int num = 4;
  Choose choose(5,3);

  vector<int> temp(num);
  for (int c = 1; c < num+1; c++)
	temp[c-1] = c;

  for (int c = 0; c < choose.Size(); c++){
  	cout << "The current permutation is ";
	vector<int> test = choose.Next();
	//choose.Next();
	for (int i = 0; i < test.size(); i++)
	  cout << test[i] << " ";
	cout << endl;

  }

  return 0;

}

