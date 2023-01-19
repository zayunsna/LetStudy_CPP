#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

const int Inf = 987654321;
int ret = -Inf;

vector<char> type;
vector<int> num;
string str;
int n;

int cal(char a, int b, int c){
	int out = 0;
	if(a == '+') out = b+c;
	if(a == '-') out = b-c;
	if(a == '*') out = b*c;
	return out;
}

void run(int idx, int _num){
	cout << " Input : " << idx << ", num : " << _num << "\n";
	if(idx == num.size() - 1){
		cout << " Fcn end : " << ret << " vs ";
		ret = max( ret, _num);
		cout << _num << " = " << ret << "\n";
		return;
	}

	cout << " go prompt recursion : " << idx+1 << "  " << _num << "  " << type[idx] << "  " << num[idx+1] << " = " << cal(type[idx], _num, num[idx+1]) << "\n";
	run(idx+1, cal( type[idx], _num, num[idx+1] ));
	cout << " return from prompt recursion with " << idx+1 << "\n";
	if(idx+2 <= num.size()-1){
		int temp = cal(type[idx+1], num[idx+1], num[idx+2]);
		cout << " go delayed recursion : " << idx+2 << "  " << _num << "  " << type[idx] << "  " << temp << " = " << cal(type[idx], _num, temp) << "\n";
		run(idx+2, cal(type[idx], _num, temp));
		cout << " return from delayed recursion with " << idx+2 << "\n";
	}
	return;
}


void baekjoon_16637(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> str;
	for(int i = 0; i < n; ++i){
		if( i % 2 == 0) num.push_back(str[i] - '0');
		else type.push_back(str[i]);
	}

	run(0, num[0]);

	cout << ret << "\n";

}
