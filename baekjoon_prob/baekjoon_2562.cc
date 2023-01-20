#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

void baekjoon_2562(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a;
	int mx = 0;
	int save = 0;

	for(int i = 0; i < 9; ++i){
		cin >> a;
		if( mx < a) {
			mx = a;
			save = i+1;
		}
	}

	cout << mx << "\n" << save << "\n";

}
