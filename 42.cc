/* The nth term of the sequence of triangle numbers is given by, tn = ½n(n+1); so the first ten triangle numbers are:
 *
 * 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
 *
 * By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value. For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a triangle number then we shall call the word a triangle word.
 *
 * Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand common English words, how many are triangle words?
 */

#include <iostream>
#include <unordered_set>
#include <vector>
#include <fstream>
#include <cstring>

using namespace std;

constexpr int kMaxNum = 100;
const string input_name = "./p042_words_processed.txt";

unordered_set<int> CalcTriangleNums(int max_order){
	unordered_set<int> out;
	for (int c = 1; c < max_order+1; c++){
		int num = c*(c+1)/2;
		out.insert(num);
	}

	return out;
}

int GetWordCode(string word){
	int out = 0;
	for (auto c : word){
		out += c - 'a' + 1;
	}
	return out;
}

vector<string> ReadWordFile(string filename){
  //It is assumed the input file words are enclosed by "" and separated by commas.
  ifstream fp(filename, ifstream::in);
  vector<string> out;
  constexpr int kMaxWordSize = 100;
  char word[kMaxWordSize+1];
  while(fp.getline(word, kMaxNum))
	out.push_back(word);

  return out;
}

int main(){

	unordered_set<int> triangle_nums = CalcTriangleNums(kMaxNum);
	vector<string> words = ReadWordFile(input_name);

	int count = 0;
	for (auto word : words){
	  int word_code = GetWordCode(word);
	  if (triangle_nums.find(word_code) != triangle_nums.end())
		count++;
	}

	cout << "The number of words having triangle number code is " << count << endl;

	return 0;

}
