#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

void baekjoon_3052(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	const int t = 10;
	const int div = 42;
	int a;
	map<int,int> m;
	for(int i = 0; i < t; ++i){
		cin >> a;
		m[a%div]++;
	}

	cout << m.size() << "\n";

}
