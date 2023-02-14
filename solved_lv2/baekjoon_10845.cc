#include <bits/stdc++.h>
using namespace std;

int n, m;
string str;
queue<int> q;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n; 
	for(int i = 0; i < n; ++i){
		cin >> str;
		if(str == "push"){
			cin >> m;
			q.push(m);
		}
		else if(str == "pop"){
			if(!q.empty()){
				cout << q.front() << "\n";
				q.pop();
			}
			else cout << "-1\n";
		}
		else if(str == "size"){
			cout << q.size() << "\n";
		}
		else if(str == "empty"){
			if(!q.empty()) cout << "0\n";
			else cout << "1\n";
		}
		else if(str == "front"){
			if(!q.empty()) cout << q.front() << "\n";
			else cout << "-1\n";
		}
		else if(str == "back"){
			if(!q.empty()) cout << q.back() << "\n";
			else cout << "-1\n";
		}
	}

	return 0;
}
