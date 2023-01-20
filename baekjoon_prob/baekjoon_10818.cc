#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

void baekjoon_10818(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n,a;
	cin >> n;
	vector<int> v;
	for(int i = 0; i < n; ++i){
		cin >> a;
		v.push_back(a);
	}
	int mn = *min_element(v.begin(), v.end());
	int mx = *max_element(v.begin(), v.end());
	cout << mn << " " << mx << "\n";

}
