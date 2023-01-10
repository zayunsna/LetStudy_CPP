#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

void baekjoon_9935(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string str;
	cin >> str;
	string key;
	cin >> key;
	string a[40];

	string t = "";
	for(char c : str){
		t+= c;
		if( t.size() >= key.size() && t.substr(t.size() - key.size(), key.size()) == key){
			t.erase( t.end() - key.size(), t.end());
		}
	}

	cout << t << "\n";

}
