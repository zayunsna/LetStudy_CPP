#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

void baekjoon_2884(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int h, m;
	cin >> h >> m;

	if( m - 45 >= 0) m -= 45;
	else {
		if( h - 1 >= 0) h -=1;
		else h = h+24-1;
		m = m+60-45;
	}
	cout << h << " " << m << "\n";

}
