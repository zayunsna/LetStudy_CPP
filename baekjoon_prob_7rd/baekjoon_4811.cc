#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 60;
const int Inf = 987654321;
ll dp[34][34];
int n;


ll run(int w, int h){

//	cout << " input : " << t << "  " << w << "  " << h << "\n";
	if( w == 0){
//		cout << " all w is out \n";
		return 1;
	}
	if( h < 0 ) {
//		cout << " Negative h \n";
		return 0;
	}

	ll &ret = dp[w][h];
//	cout << " DP Check : " << ret << "\n";
	if(ret != -1) return ret;
	ret = 0;
	ll a = run( w-1, h+1);
	ll b = run( w, h-1);

	ret = a+b;
//	cout << a <<  "   " << b  << "  " << ret << "\n";
	return ret;

}

void baekjoon_4811(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while(1){
		cin >> n;
		if(n == 0) break;
		memset(dp, -1, sizeof(dp));
		ll ret = run(n, 0);
		cout << ret << "\n";
	}

}
