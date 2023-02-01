#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int dp[N+4];

vector<pair<int,int>> vp;
int n, k, w, v;

bool cmp(pair<int,int> a, pair<int,int> b){
	if(a.first > b.first) return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> k;
	for(int i = 0; i < n; ++i){
		cin >> w >> v;
		vp.push_back({w,v});
	}
	sort(vp.begin(), vp.end(), cmp);
	
	memset(dp, 0, sizeof(dp));
	for(auto it : vp){
		int _w = it.first;
		int _v = it.second;
		for(int i = k; i >= _w; --i){
			dp[i] = max(dp[i-_w]+_v, dp[i]);
		}
	}
	
	cout << dp[k] << "\n";
}
