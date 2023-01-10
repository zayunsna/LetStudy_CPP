#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

int cnt;

void baekjoon_3273(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i) cin >> v[i];
	int x = 0;
	cin >> x;

	sort(v.begin(), v.end());

	for(int it : v) cout << it << " ";
	cout << "\n";
	int j = 0, f = n-1;
	while(j < f){
		cout << j << "["<< v[j] <<  "]" << " : " << f << "["<<v[f]<<"]"<< "\n";
		if(v[j] + v[f] == x)f--, cnt++;
		else if(v[j] + v[f] > x) f--;
		else if(v[j] + v[f] < x) j++;
	}

}
