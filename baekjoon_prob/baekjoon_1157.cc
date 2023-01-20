#include "/home/icegpu/HK/HKTool.h"
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void baekjoon_1157(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	map<int,int> m;
	string str;
	cin >> str;

	for(int i = 0; i < str.size(); ++i){
		int asc = (int)str[i];
		if(asc > 90) asc -= 32;
		m[asc]++;
	}

	int mx = 0;
	int ret = 0;
	int cnt = 0;
	for(auto it : m) {
		if( mx < it.second){
			mx = it.second;
			ret = it.first;
			cnt = 0;
		}
		else if(mx == it.second){
			cnt++;
		}
	}

	if(cnt) cout << "?\n";
	else cout << (char)ret << "\n";

}
