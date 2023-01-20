#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

void baekjoon_2475(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long sum = 0;
	int a = 0;
	for(int i = 0; i < 5; ++i){
		cin >> a;
		sum += a*a;
	}
	cout << sum%10 << "\n";

}
