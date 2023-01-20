#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

void baekjoon_2920(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int> v;
	for(int i = 0; i < 8; ++i){
		int a;
		cin >> a;
		v.push_back(a);
	}

	if(v[0] == 1){
		for(int i = 0; i < 8; ++i ){
			if(v[i] == i+1) continue;
			else{
				cout << "mixed\n";
				return;
			}
		}
		cout << "ascending\n";
	}
	else if(v[0] == 8){
		for(int i = 0; i < 8; ++i ){
			if(v[i] == 8-i) continue;
			else{
				cout << "mixed\n";
				return;
			}
		}
		cout << "descending\n";
	}
	else cout << "mixed\n";

}
