#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

int flip(int a){
	string a_str = to_string(a);
	string out = "";
	for(int i = a_str.size()-1; i >= 0; --i){
		out += a_str[i];
	}
	return atoi(out.c_str());

}

void baekjoon_2908(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a, b;
	cin >> a >> b;

	cout << (flip(a) > flip(b) ? flip(a) : flip(b)) << "\n";

}
