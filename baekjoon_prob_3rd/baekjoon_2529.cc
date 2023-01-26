#include <bits/stdc++.h>
using namespace std;

typedef vector<pair<int,int>> vp;
int n, m;
const int N = 9;
char comp[N+2];
int vis[N+2];
vector<long long> box;

void ret_print(long long a){
	string as = to_string(a);
	string out_a = "";
	if( as.size() < n+1){
		for(int i = 0; i < n-as.size()+1; ++i){
			out_a += "0";
		}
		out_a += as;
	}
	else out_a = as;
	cout << out_a << "\n";
}

void dfs(string str,int now, int turn){
	if(turn == n){
		box.push_back(atol(str.c_str()));
		return ;
	}
	for(int j = 0; j < N+1; ++j){
		if(vis[j]) continue;
		if(comp[turn] == '>'){
			if(now > j) {
				vis[j] = 1;
				dfs(str+to_string(j), j, turn+1); 
				vis[j] = 0;
			}
		}
		if(comp[turn] == '<'){
			if(now < j) {
				vis[j] = 1;
				dfs(str+to_string(j), j, turn+1);
				vis[j] = 0;
			}
		}

	}
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> comp[i];
	}

	string str = "";
	for(int i = 0; i < N+1; ++i){
		vis[i] = 1;
		str = "";
		dfs(str+to_string(i), i,0);
		vis[i] = 0;
	}

	//cout << box.size() << "\n";
	sort(box.begin(), box.end());
	//for(auto it : box) cout << it << "\n";
	ret_print(box[box.size()-1]);
	ret_print(box[0]);
}
