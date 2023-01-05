#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

int t, n;

void fcn(int n){
	int div2 = 0;
	int div5 = 0;
	int t2 = 2;
	int t5 = 5;
	while(t2 <= n){
		div2 += n/t2;
		t2 *= 2;
	}
	while(t5 <= n){
		div5 += n/t5;
		t5 *= 5;
	}

	cout << min(div2, div5) << "\n";

}
void baekjoon_3747(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	for(int i = 0 ; i < t; ++i){
		cin >> n;
		fcn(n);
	}

}
