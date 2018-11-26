/*The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.
 *
 * We shall consider fractions like, 30/50 = 3/5, to be trivial examples.
 *
 * There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.
 *
 * If the product of these four fractions is given in its lowest common terms, find the value of the denominator.
 */
 #include <iostream>

using namespace std;


constexpr double kTolerance = 1e-6;

bool IsCuriousFraction(int a, int b, double &x){
				int numerator = 9*a*b;
				int denominator = 10*a-b;

				x = static_cast<double> (numerator)/denominator;
				double diff = x - numerator/denominator;

				if (abs(diff) <  kTolerance && x < 10 && x > 0)
						return true;
				else
						return false;
}

int main(){
	// Finding x = 9ab/(10a-b) or 9ab/(10b-a)
	
	for (int a = 1; a < 10; a++)
			for (int b = a+1; b < 10; b++){
				double x;
				if (IsCuriousFraction(a, b, x))
						cout << "The fraction " << a << x << "/" << x << b << " is curious!" << endl;

				if (IsCuriousFraction(b, a, x))
						cout << "The fraction " << x << a << "/" << b << x << " is curious!" << endl;
			}

	return 0;
	
	
}
