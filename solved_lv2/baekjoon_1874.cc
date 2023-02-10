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
	stk.push(idx);
	
	string str = "";
	
	while(true){
		int now = stk.top();
		int target = v[cnt];
		if(cnt == v.size()-1) break;
		if(idx && !now){
			break;
		}
		//cout << idx << " " << now << " " << target << "\n";
		if(now < target){
			//cout << "+\n";
			str += "+";
			idx++;
			stk.push(idx);
		}
		else if(now == target) {
			cnt++;
			//cout << "-\n";
			str += "-";
			stk.pop();
		}
		else if(now > target){
			//cout << "-\n";
			str += "-";
			stk.pop();
		}
	}

	if(cnt != v.size()-1) cout << "NO\n";
	else{
		for(char a : str) cout << a << "\n";
		cout << "\n";
	}
	return 0;
}
