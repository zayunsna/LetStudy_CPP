#include <bits/stdc++.h>
using namespace std;


const int N = 10004;
const int M = 100004;
vector<int> v[N];
int dp[N];
int vis[N];
int arr[N];
int n, m;
int cnt = 0;

vector<pair<int,int>> vp;

int dfs(int start){
	
	//int ret = 1;
	int &ret = dp[start];
	if(ret != -1) return ret;
	ret = 1;
	
	vis[start] = 1;	
	for(int i = 0; i < v[start].size(); ++i){
		int next = v[start][i];
		if(vis[next]) continue;
		ret += dfs(next);
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for(int i = 0; i < m; ++i){
		int a = 0, b = 0;
		cin >> a >> b;
		v[b].push_back(a);
	}
	
	int mx = 0;
	for(int i = 1; i <= n; ++i){
		memset(dp, -1, sizeof(dp));
		memset(vis, 0, sizeof(vis));
		arr[i] = dfs(i);
		mx = max(arr[i], mx);
	}
	
	
	for(int i = 1; i <=n; ++i)
		if( arr[i] == mx) cout << i << " ";
	cout << "\n";
	
	return 0;	
}
