#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;


const int n = 4;
string a[n] = {"bob","jimmy","sara","david"};

void run(int num){
	cout << bitset<4>(num) << "\n";
	for(int i = 0; i < n; ++i){
		if( num & ( 1 << i)) cout << a[i] << " ";
	}
	cout << "\n";
}


void test7(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for(int i = 0; i < n; ++i){
		run(1 | (1<<i));
	}

}
