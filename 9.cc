/*
   A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

   a2 + b2 = c2
   For example, 32 + 42 = 9 + 16 = 25 = 52.

   There exists exactly one Pythagorean triplet for which a + b + c = 1000.
   Find the product abc.
   */ 

#include <iostream>
#include <cmath>

#define MAXNUM 1000
#define SUM 1000

using namespace std;

int main(){

		int out[3] = {0};
		double c_squared;
		for(int a = 1; a < MAXNUM+1; a++){
				for(int b = a; b < MAXNUM+1; b++){
						c_squared = a*a + b*b;
						double c = sqrt(c_squared);
						if (floor(c) == c && ( (a+b+sqrt(c_squared)) == SUM ) ){
								out[0] = a;
								out[1] = b;
								out[2] = sqrt(c_squared);
						}
				}
		}
		cout << "The product of the numbers are : " << out[0]*out[1]*out[2] << endl;
		return 0;
}
