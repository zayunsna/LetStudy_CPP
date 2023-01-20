#include "/home/icegpu/HK/HKTool.h"
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void baekjoon_1546(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> num;
	int a;
	for(int i = 0; i < n; ++i){
		cin >> a;
		num.push_back(a);
	}
	int mx = *max_element(num.begin(), num.end());

	double sum = 0.;
	for(int it : num){
		sum += (double)it/mx * 100.;
	}

	cout << setprecision(10);
	cout << (double)sum/n << "\n";
	


}
