/*
   The four adjacent digits in the 1000-digit number that have the greatest product are 9 × 9 × 8 × 9 = 5832.

   73167176531330624919225119674426574742355349194934
   96983520312774506326239578318016984801869478851843
   85861560789112949495459501737958331952853208805511
   12540698747158523863050715693290963295227443043557
   66896648950445244523161731856403098711121722383113
   62229893423380308135336276614282806444486645238749
   30358907296290491560440772390713810515859307960866
   70172427121883998797908792274921901699720888093776
   65727333001053367881220235421809751254540594752243
   52584907711670556013604839586446706324415722155397
   53697817977846174064955149290862569321978468622482
   83972241375657056057490261407972968652414535100474
   82166370484403199890008895243450658541227588666881
   16427171479924442928230863465674813919123162824586
   17866458359124566529476545682848912883142607690042
   24219022671055626321111109370544217506941658960408
   07198403850962455444362981230987879927244284909188
   84580156166097919133875499200524063689912560717606
   05886116467109405077541002256983155200055935729725
   71636269561882670428252483600823257530420752963450

   Find the thirteen adjacent digits in the 1000-digit number that have the greatest product. What is the value of this product?
   */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctype.h>

using namespace std;
typedef long long int ll;

#define NUMDIGITS 13

vector<int> ReadData(string filename){

		ifstream fp(filename);
		char c;
		vector<int> out;
		int counter = 0;
		while(fp.peek() != EOF){
				c = fp.get();
				if (isdigit(c))
						out.push_back(c - '0');
				counter++;
		}

		fp.close();
		return out;
}

int main(){

		//Reading the data
		auto nums = ReadData("9_data");
		vector<int> max_nums(NUMDIGITS);
		ll cur_product, max_product = -1;

		int first_index = 0, second_index = NUMDIGITS;
		while(second_index < 1000){
				cur_product = 1;
				for(int c = first_index; c < second_index; c++)
						cur_product *= nums[c];


				if (cur_product > max_product){
						for (int i = 0; i < NUMDIGITS; i++)
								max_nums[i] = nums[i+first_index];
						max_product = cur_product;
				}
				second_index++;
				first_index++;
		}

		cout << "The consecutive numbers with maximum product are : ";
		for (int c = 0; c < NUMDIGITS; c++)
				cout << max_nums[c];
		cout << endl;
		cout << "The maximu product is : " << max_product << endl;

		return 0;

}
