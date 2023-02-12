#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int Inf = 1e9;
vector<int> v;
int n, m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> m, v.push_back(m);
	
	int cnt = 0;
	int idx = 0;
	int flag = 0;
	stack<int> stk;
	
	string str = "";
	
	for(int i = 1; i <= n; ++i){
		stk.push(i);
		str +="+";
		while(stk.size() && stk.top() == v[idx]){
			stk.pop();
			str += "-";
			idx++;
		}
	}

	if(stk.size()) cout << "NO\n";
	else{
		for(char a : str) cout << a << "\n";
		cout << "\n";
	}
	return 0;
}
