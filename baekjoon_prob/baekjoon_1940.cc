#include "/home/icegpu/HK/HKTool.h"
using namespace std;

int N, M;
int cnt = 0;

void baekjoon_1940(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	cin >> M;

	int nL = N+10;

	int L[nL];
	fill(L, L+nL, 0);
	for(int i = 0; i < N; ++i){
		cin >> L[i];
	}


	for(int i = 0; i < N; ++i)cout << L[i] << endl;

	if( M > 200000 ) cout << 0 << "\n";
	else {
		for(int i = 0; i < N; ++i){
			for(int j = i+1; j < N; ++j){
				int sum = 0;
				sum = L[i]+L[j];
				if(sum == M) cnt++;
			}
		}
		cout << cnt << "\n";
	}

}
