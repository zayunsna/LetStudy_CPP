#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 100004;
int lt[N];
int n,m;


void run(int w, int t){


	int cnt = w+t+abs( (n+w)*pow(2,t) - m);
	lt[cnt] ++;

	return;
}

void baekjoon_12851(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	run(0,0,n,m);

}
