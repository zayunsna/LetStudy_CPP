#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

int n, k;
int bag[300000];
int vis[300000];
int m, v;
vector<pair<int,int>> vp;

int dp[300000];

bool cmp(pair<int,int> a, pair<int,int> b){
	return a.first > b.first;
}

int maxV = 0;
int sum = 0;

void run(int cnt){
	if(cnt == k){
		maxV = max(maxV, sum);
		return ;
	}
	
	for(int i = 0; i < n; ++i){
		auto it = vp[i];
		int val = it.first;
		int w = it.second;
		if(vis[i] || w > bag[cnt]) continue;

		vis[i] = 1;
		sum += val;
		run(cnt+1);
		vis[i] = 0;
		sum -= val;
	}
}

void baekjoon_1202(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	for(int i = 0; i < n; ++i){
		cin >> m >> v;
		vp.push_back({v,m}); // pair {value, weight}
	}

	sort(vp.begin(), vp.end(), cmp);

	for(int i = 0; i < k; ++i){
		cin >> bag[i];
	}

	memset(vis, 0, sizeof(vis));
	run(0);

	cout << maxV << "\n";
}
