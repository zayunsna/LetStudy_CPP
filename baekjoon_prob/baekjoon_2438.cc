#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

void baekjoon_2438(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		string ret = "*";
		for(int j = 0; j < i; ++j)
			ret += "*";
		cout << ret << "\n";
	}

}
