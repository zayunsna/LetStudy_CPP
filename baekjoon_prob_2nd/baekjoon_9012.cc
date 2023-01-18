#include <bits/stdc++.h>
using namespace std;

void run(string str){

	int s = str.size();

	int sum = 0;
	for(int i = 0; i < s; ++i){
		char _this = str[i];
		if(_this == '(') sum += 1;
		else if(_this == ')') sum -= 1;

		if(sum < 0){
			cout << "NO\n"; 
			return;
		}
	}

	if(sum){
		cout << "NO\n";
		return;
	}

	cout << "YES\n";
	return;

}


void baekjoon_9012(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string str;
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> str;
		run(str);
	}
	cout << "\n";

}
