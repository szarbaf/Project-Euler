/*Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:
 *
 * 21 22 23 24 25
 * 20  7  8  9 10
 * 19  6  1  2 11
 * 18  5  4  3 12
 * 17 16 15 14 13
 *
 * It can be verified that the sum of the numbers on the diagonals is 101.
 *
 * What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
 */

#include <iostream>
#include <vector>

using namespace std;

const int SquareSize = 1001;

int main(){

  // The initial size of the square is three
  int size = 3;

  // The counter keeping track of the current element index, which starts at 2.
  long int counter = 2;

  // The variable containing the sum of the diagonals, containing the element 1.
  long long int sum_diagonal = 1;

  // Invariant: The counter is at middle element of the right side.
  while(size <= SquareSize){

	// Incrementing the counter size-2 to get the lower right diagonal element.
	counter += size-2;
	sum_diagonal += counter;

	// Incrementing the counter (size-1) to get the lower left element
	counter += size-1;
	sum_diagonal += counter;

	// Incrementing the counter (size-1) to get the upper left element
	counter += size-1;
	sum_diagonal += counter;

	// Incrementing the counter (size-1) to get the upper right element
	counter += size-1;
	sum_diagonal += counter;

	// Updating the counter to point to the middle element of the right side of the next square.
	counter += 1;

	// Updating the size
	size += 2;

  }


  cout << "The sum of the diagonal for a square of " << SquareSize << "*" << SquareSize << " is : "
	<< sum_diagonal << endl;

  return 0;

}
