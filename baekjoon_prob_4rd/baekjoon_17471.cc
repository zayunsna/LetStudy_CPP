#include <bits/stdc++.h>
using namespace std;

typedef vector<pair<int,int>> vp;
int n, m;
const int N = 12;

int h[N];
vector<int> s[N];
int visited[N];
int stat[N];

const int Inf = 999999999;
int ret = Inf;

pair<int,int> dfs(int now, int v){
	visited[now] = 1;
	pair<int, int> ret = {1, h[now]};
	for(int it : s[now]){
		if(stat[it] != v) continue;
		if(visited[it]) continue;
		pair<int, int> temp  = dfs(it, v);
		ret.first += temp.first;
		ret.second += temp.second;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> h[i+1];
	}
	
	for(int i = 0; i < n; ++i){
		int in = 0;
		cin >> in;
		for(int j = 0; j < in; ++j){
			int a = 0;
			cin >> a;
			s[i+1].push_back(a);
			s[a].push_back(i+1);
		}
	}
	
	for(int i = 1; i < (1 << n)-1; ++i){
		memset(visited, 0, sizeof(visited));
		memset(stat, 0, sizeof(stat));
		int idx1 = -1, idx2 = -1;
		for(int j = 0; j < n; ++j){
			if(i & (1<<j)) {
				stat[j+1] = 1;
				idx1 = j+1;
			}
			else idx2 = j+1;
		}
		pair<int, int> comp1 = dfs(idx1, 1);
		pair<int, int> comp2 = dfs(idx2, 0);
	
		if(comp1.first + comp2.first == n){
			ret = min(ret, abs(comp1.second - comp2.second));
		}
	}
	
	cout << (ret == Inf ? -1 : ret )<< "\n";


/*
	int flag = 0;
	for(int i = 1; i < ( 1<<(n+1) )-1; ++i){
		flag = 1;
		select.clear();
		sum2 = 0;
		for(int j = 1; j <= n; ++j ){
			if( i & (1<< (j-1))){
				select.push_back(j);
				sum2 += h[j];
			}
		}

		for(int i = 1; i < select.size(); ++i){
			if( find( s[select[0]].begin(), s[select[0]].end(), select[i] ) == s[select[0]].end()  ){
				flag = 0;
				break;
			}
		}
		
		if( flag ){
			ret = min(ret, abs(sum - 2*sum2));
		}
		

	}
	
	if(flag) cout << -1 << "\n";
	else cout << ret << "\n";
	
	return 0;
	*/
}
