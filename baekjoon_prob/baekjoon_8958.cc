#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

int T;
string str;

void baekjoon_8958(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	for(int i = 0; i < T; ++i){
		cin >> str;

		int s = str.size();
		int cnt = 0 ;
		int sum = 0;
		for(int j = 0; j < s; ++j){
			if(str[j] == 'O') cnt++;
			else if(str[j] == 'X'){
				cnt  = 0;
			}
			sum += cnt;
		}
		cout << sum << "\n";
	}

}
