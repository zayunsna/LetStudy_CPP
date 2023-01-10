#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;


void baekjoon_2109(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n = 0;
	cin >> n;
	vector<pair<int,int>> vp(n);
	for(int i = 0; i < n; ++i){
		cin >> vp[i].second >> vp[i].first;
	}

	for(auto it : vp) cout << it.first << "  " << it.second << "\n";
	cout << "\n";
	cout << " Sorting ...\n";
	sort(vp.begin(), vp.end());
	for(auto it : vp) cout << it.first << "  " << it.second << "\n";
	cout << "\n";

	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i = 0; i < n; ++i){
		pq.push(vp[i].second);
		if(pq.size() > vp[i].first){
			pq.pop();
		}
	}
	int ret = 0;
	while(pq.size()){
		ret += pq.top(); pq.pop();
	}

	cout << ret << "\n";



}
