#include "/home/icegpu/HK/HKTool.h"
using namespace std;

string str;
int flag = 0;


void baekjoon_10988(){

	cin >> str;
	int size = str.size();
	int cache = floor(size/2.);


	for(int i = 0; i < cache; ++i){
		if(str[i] != str[size-1-i]) flag = 1;
	}

	if(flag == 0) cout << 1 << "\n";
	else cout << 0 << "\n";


}

// short cut solution
/*
string str, temp;
void baekjoon_10988(){
	cin >> str;
	temp = str;
	reverse(temp.begin(), temp.end());
	if(temp == str) cout << 1 << "\n";
	else cout << 0 << "\n";
}
*/
 
