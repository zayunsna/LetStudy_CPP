#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

string str;
int n;
vector<int> ok;
const int N = 1000004;
const int su = 100;


bool check(int a){
	string str = to_string(a);
	for(int i = 0; i < str.size(); ++i){
		int num = (int)str[i]-'0';
		if(find(ok.begin(), ok.end(), num) != ok.end()) return false;
	}
	return true;
}

void baekjoon_1107(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> str;
	cin >> n;
	for(int i = 0; i < n; ++i){
		int a; cin >> a;
		ok.push_back(a);
	}
	if(atoi(str.c_str()) == su){
		cout << "0\n"; return ;
	}
	if(str.size() == 1){
		if(check(atoi(str.c_str()))){
			cout << "1\n";
			return;
		}
	}

	int ret = abs(atoi(str.c_str()) - su);
	for(int i = 0; i <= N; ++i){
		if(check(i)){
			int sub = abs( atoi(str.c_str()) - i) + to_string(i).length();
			ret = min(ret,sub);
		}
	}

	cout << ret << "\n";

}
