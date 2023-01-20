#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

void baekjoon_2439(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		string ret = "";
		for(int j = 1; j < n-i; ++j)
			ret += " ";
		for(int j = 0; j < i+1; ++j)
			ret += "*";
		cout << ret << "\n";
	}

}
