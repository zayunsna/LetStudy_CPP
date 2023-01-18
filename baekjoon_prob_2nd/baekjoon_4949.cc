#include <bits/stdc++.h>
using namespace std;


void run(string str){

	int s = str.size();
	//cout << str << " " << s << "\n";
	int cnt = 0;
	stack<char> st;
	for(int i = 0; i < s; ++i){
		char _this = str[i];
		if(_this == '(' ||_this == '[') st.push(_this);
		else if(_this == ')'){
			if(st.size() == 0){
				cout << "no\n";
				return;
			}
			else if( st.top() == '(') st.pop();
			else cnt ++;
		}
		else if(_this == ']'){
			if(st.size() == 0){
				cout << "no\n";
				return;
			}
			else if( st.top() == '[') st.pop();
			else cnt++;
		}
	}

	if(cnt || st.size()) cout << "no\n";
	else cout << "yes\n";

	return;
}

void baekjoon_4949(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string str;
	//while(cin >> str)
	while(getline(cin, str))
	{

		if(str.size() == 1 && str == ".") break;
		run(str);
	}

	cout << "\n";

}
