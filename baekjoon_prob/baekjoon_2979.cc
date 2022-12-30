#include "/home/icegpu/HK/HKTool.h"
using namespace std;

const int Inf = 100;
int a, b, c;
int cnt[Inf];

int ii, jj;

int fee = 0;

void baekjoon_2979(){
	cin >> a >> b >> c;

	for(int i = 0; i < 3; ++i){
		cin >> ii >> jj;
		for(int j = ii; j < jj; ++j) cnt[j]++;
	}

	for(int i = 0; i < Inf; ++i){
		if(cnt[i] != 0){
			if(cnt[i] == 3) fee += 3*c;
			else if(cnt[i] == 2) fee += 2*b;
			else fee += a;
		}
	}

	cout << fee << "\n";


}
