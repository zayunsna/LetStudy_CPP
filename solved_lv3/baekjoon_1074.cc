#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

int n, r, c;
int cnt = 0;
int tSize= 0;

int check(int y, int x, int s){
	if(y < s/2 && x < s/2) return 0;
	else if( y < s/2 && x >= s/2) return 1;
	else if( y >= s/2 && x < s/2) return 2;
	else return 3;
}

int run(int Size, int r, int c){

	int rs = pow(2,Size);
	if(Size == 1){
		return check(r, c, rs);
	}
	int ret = check(r, c, rs)*pow(4,Size-1);
	int nr = (r >= rs/2) ? r-rs/2 : r;
	int nc = (c >= rs/2) ? c-rs/2 : c;
	ret += run( Size-1, nr, nc );
	
	return ret;
}


void baekjoon_1074(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> r >> c;

	cout <<	run(n, r, c) << "\n";


}
