#include <bits/stdc++.h>
using namespace std;

int n, m;
string str;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	stack<int> stk;
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> str;
		if(str == "push"){
			cin >> m;
			stk.push(m);
		}
		if(str == "top"){
			if(!stk.empty()){
				cout << stk.top() << "\n";
			}
			else cout << "-1\n";
		}
		if(str == "size"){
			cout << stk.size() << "\n";
		}
		if(str == "empty"){
			if(!stk.empty()) cout << "0\n";
			else cout << "1\n";
		}
		if(str == "pop"){
			if(!stk.empty()){
				cout << stk.top() << "\n";
				stk.pop();
			}
			else cout << "-1\n";
		}
	}

	return 0;
}
