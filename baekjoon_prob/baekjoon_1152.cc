#include <bits/stdc++.h>
using namespace std;

void baekjoon_1152(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string str;
	
	int flag = 0;
	int cnt = 0;
	getline(cin, str);
	for(int i = 0; i < str.size(); ++i){
		if(str.c_str()[i] == ' '){
			flag = 0;
			continue;
		}
		else flag ++;
		if(flag == 1) cnt++;
	}

	cout << cnt << "\n";

}
