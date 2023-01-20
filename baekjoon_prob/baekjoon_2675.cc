#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

string expand(char a, int n){
	string out = "";
	for(int i = 0; i < n; ++i){
		out += a;
	}

	return out;
}

void baekjoon_2675(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int tc = 0;
	cin >> tc;
	for(int i = 0; i < tc; ++i){
		int n;
		string str;
		cin >> n >> str;

		string ret = "";
		for(int j = 0; j < str.size(); ++j){
			ret += expand(str[j], n);
		}
		cout << ret << "\n";
	}

}
