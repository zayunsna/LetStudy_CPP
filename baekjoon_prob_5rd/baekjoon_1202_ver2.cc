#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

long long n, m, v, k, ret;


void baekjoon_1202_ver2(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	vector<pair<int,int>> vp(n);
	vector<long long> bag(k);
	for(int i = 0; i < n; ++i){
		cin >> vp[i].first >> vp[i].second;
	}
	for(int i = 0; i < k; ++i) cin >> bag[i];

	sort(vp.begin(), vp.end());
	sort(bag.begin(), bag.end());
	priority_queue<long long> pq;

	int j = 0;
	for(int i = 0; i < k; ++i){
		while( j < n && vp[j].first <= bag[i]) pq.push(vp[j++].second);
		if(pq.size()){
			ret += pq.top(); pq.pop();
		}
	}

	cout << ret << "\n";

}
