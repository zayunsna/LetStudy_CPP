#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

string tarN;
int n, o, m;
int num[14];
int cal[5];
int vis[14][5];
const int eNum = 999;
const int eT = 19; // max 20 - 1 for '='
int ret = 0;
int cnt = 0;
// 4<= touch <= 20;
// 0 <= ret <= 999;

int convInt(vector<int> a){
	string temp = "";
	for(int i = 0; i < a; ++i){
		temp += to_string(a[i]);
	}
	return atoi(temp.c_str());
}

bool check(int a){
	if(a > eNum) return false;
	else return true;
}

void run(string s, int t, int mT){
	int maxCal = ( mT %2 == 0 )? floor(mT/2)-1 : floor(mT/2);
	for(int i = 0; i < maxCal; ++i){

	}

}


void do_run(string s){
	int flag = 0;
	string temp = s;
	for(int i = 0; i < s; ++i){
		int this_n = (int)s[i]-'0';
		auto pos = find(&num[0], &num[0]+14, this_n);
		if(pos != &num[0]+14) temp.pop_back();
	}
	if(s == "0"){
		int this_n = atoi(s.c_str());
		auto pos = find(&num[0], &num[0]+14, this_n);
		if(pos == &num[0]+14) {
			ret = -1;
			return;
		}
	}	
	if(temp.size() == 0) {
		ret = s.size();
		return;
	}
	else{
		ret = -1;
		run(s, 0, m-1);
		return;
	}
	
}

void old_smartphone(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> o >> m;
	for(int i = 0; i < n; ++i){ cin >> num[i]; }
	for(int i = 0; i < o; ++i){ cin >> cal[i]; }
	cin >> tarN;

	do_run(tarN);

	cout << ret << "\n";
}
