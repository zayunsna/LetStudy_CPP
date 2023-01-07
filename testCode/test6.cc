#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

void test6(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	const int n = 4;
	string a[n] = {"tommy","sara","david","bob"};

	for(int i = 0; i < (1 << n); ++i){
		string out = "";
		cout << i << "[" << bitset<4>(i) << "]" << " \n";
		for(int j = 0; j < n; ++j){
			if( i & (1 << j)) out += (a[j] + " ");
		}
		cout  << out << "\n";
	}

}
