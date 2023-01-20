#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

void baekjoon_2753(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	bool check = 0;
	if( n % 4 == 0) check = 1;
	if( n % 100 == 0){
		if( n % 400 == 0) check = 1;
		else check = 0;
	}

	cout << check << "\n";

}
