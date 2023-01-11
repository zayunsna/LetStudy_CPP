#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

const int MAX = 16;
const int Inf = 987654321;
int dp[MAX][(1<<MAX)];
int mat[MAX][MAX];
int n;

int run(int here, int vis){
	if( vis == ( 1<< n) -1){
		//cout << " End Fcn : "<< vis << "  " << (1<<n) -1 << " = " << mat[here][0] << " \n";
		return  mat[here][0] ? mat[here][0] : Inf ;
	}	
	int &ret = dp[here][vis];
	//cout << " DP check : " << ret << "\n";
	if(ret != -1) return ret;
	ret = Inf;

	for(int i = 0; i < n; ++i){
		//cout << i << "  " << here << "  " << bitset<4>(vis) << "  " << mat[here][i] << "\n";
		if( vis & ( 1 << i ) ) continue;
		if( mat[here][i] == 0) continue;

		//cout << " Go next recursion : " << i << "  " << here << "  " << bitset<4>(vis) << "  " << mat[here][i] << "\n";
		ret = min(ret, run(i, vis | (1<<i)) + mat[here][i]);
		//cout << " -- " << here << " Recursion out with ret : " << ret << "\n";
	}
	
	return ret;

}

void baekjoon_2098(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for(int i =0 ; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> mat[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));
	cout << run(0, 1) << "\n";

}
