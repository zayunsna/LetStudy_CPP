#include <bits/stdc++.h>
using namespace std;

int n,m;
string str;
deque<int> dq;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> str;
		if(str == "push_front"){
			cin >> m;
			dq.push_front(m);
		}
		else if(str == "push_back"){
			cin >> m;
			dq.push_back(m);
		}
		else if(str == "pop_front"){
			if(!dq.empty()){
				cout << dq.front() << "\n";
				dq.pop_front();
			}
			else cout << "-1\n";
		}
		else if(str == "pop_back"){
			if(!dq.empty()){
				cout << dq.back() << "\n";
				dq.pop_back();
			}
			else cout << "-1\n";
		}
		else if(str == "empty"){
			if(!dq.empty()) cout << "0\n";
			else cout << "1\n";
		}
		else if(str == "size"){
			cout << dq.size() << "\n";
		}
		else if(str == "front"){
			if(!dq.empty()){
				cout << dq.front() << "\n";
			}
			else cout << "-1\n";
		}
		else if(str == "back"){
			if(!dq.empty()){
				cout << dq.back() << "\n";
			}
			else cout << "-1\n";
		}
	}

	return 0;
}
