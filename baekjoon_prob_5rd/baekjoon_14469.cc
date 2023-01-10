#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

int n;

void baekjoon_14469(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	vector<pair<int,int>> vp(n);

	for(int i = 0; i < n; ++i){
		cin >> vp[i].first >> vp[i].second;
	}

	sort(vp.begin(), vp.end());

	int ret = 0;
	int eT = 0;
	for(int i = 0; i < n; ++i){
		int now_s = vp[i].first;
		int now_r = vp[i].second;

		if( now_s >= eT) ret = now_s+now_r;
		else if( now_s < eT) ret = eT+now_r;

		eT = ret;
	}

	cout << ret << "\n";


}
