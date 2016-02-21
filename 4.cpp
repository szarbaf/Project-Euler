#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool palindrom(int num);

int main(){

	int max_num = 0;
	for (int i = 999; i >= 100; i--)
		for(int j = i; j >= 100 ; j--){
			int num = i*j;
			if (palindrom(num)){
				max_num = max(max_num, num);
			}
		}

	cout << "The maximum palindrom number is : " << max_num << endl;

	return 0;
}

bool palindrom(int num){
	
	string st = to_string(num);
	int s=-1, e=st.size();
	while (s++ < e--)
		if(st[s] != st[e])
			break;
	
	if (s < e)
		return false;
	else
		return true;
}
