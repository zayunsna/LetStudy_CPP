#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

void baekjoon_1094(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int x = 0;
	cin >> x;

	string a = bitset<8>(x).to_string();

	int ret = 0;
	for(int i = 0; i < 8; ++i){
		if( a[i] == '1') ret++;
	}
	cout << ret << "\n";

}
/*
int ret = 0;
void run(int num, int cri, int turn){
	int d = num /2;
	if( d < 1){
		return;
	}
	else if( d == cri){
		ret++;
		return;
	}

	if(d > cri){
		run(d, cri, turn-1);
	}
	else{
		run(d, cri-d, turn-1);
		ret ++;
	}
	return;
	
}

void baekjoon_1094(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int x = 0;
	int ori = 64; // 1<<6;

	cin >> x;

	run(ori, x, 6);

	cout << (x==ori ? 1 : ret) << "\n";


}
*/
