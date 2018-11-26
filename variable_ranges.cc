#include <limits>
#include <iostream>
#include <cstddef>

using namespace std;

int main(){

  cout << "int: " << dec << numeric_limits<int>::max() << endl;
  cout << "long int: " << dec << numeric_limits<long int>::max() << endl;
  cout << "long long int: " << dec << numeric_limits<long long int>::max() << endl;
  cout << "double: " << dec << numeric_limits<double>::max() << endl;
  cout << "long double: " << dec << numeric_limits<long double>::max() << endl;

  return 0;
}
