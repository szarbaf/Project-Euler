#include <iostream>
#include <algorithm>

using namespace std;

int main(){
		
		int max_num = 0;
		for (int i = 100; i <= 999; i++)
				for(int j = i; i <= 999 j++){
						int num = i*j;
						if (palindrom(num))
								max_num = max(num, max_num);
				}

		cout << "The maximum palindrom number is : " << max_num << endl;

		return 0;
}

bool palindrom(int num){
		string st = to_string(num);

		
}
