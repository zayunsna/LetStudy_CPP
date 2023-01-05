#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;


int n, a;
int pSum[45];

void fibo(){
	for(int i = 0; i < 45; ++i){
		if( i == 0 || i == 1) pSum[i] = i;
		else pSum[i] = pSum[i-1] + pSum[i-2];
	}
}


void baekjoon_1003(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	fibo();
	cin >> n;
	for(int i = 0 ; i < n ; ++i){
		cin >> a;
		if(a == 0) cout << 1 << " " << 0 << "\n";
		else cout << pSum[a-1] << " " << pSum[a] << "\n";
	}


}
