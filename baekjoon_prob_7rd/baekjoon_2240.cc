#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

int dp[1004][2][34];
int cnt = 0;
int n, w;
int mat[1004];

int run(int t, int status, int move){
	if(move < 0) return  -1e9;
	if(t == n) return 0;
	int &ret = dp[t][status][move];
	if(ret != -1) return ret;
	int cnt = (status == mat[t]-1) ? 1 : 0;

	ret = max( run(t+1, status&1, move), run(t+1, status^1, move-1)) + cnt;
	return ret;
}


void baekjoon_2240(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> w;
	for(int i = 0; i < n; ++i){
		cin >> mat[i];
	}

	memset(dp, -1, sizeof(dp));
	int ret = max( run(0, 0, w), run(0,1,w-1) );

	cout << ret << "\n";
}
