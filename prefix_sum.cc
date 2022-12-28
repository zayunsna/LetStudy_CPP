#include "/home/icegpu/HK/HKTool.h"
using namespace std;

int N, M;
const int LIM = 100004;
int _list[LIM];
int b, c;
vector<int> temp;
int pSum[LIM];

void prefix_sum(){

	cin >> N >> M;

	for(int i = 1; i <= N; ++i){
		int num;
		cin >> num;
		pSum[i] = pSum[i-1] + num;
		// Note that, pSum list mush be start from 1 instead of 0.
		// in order to use 'i-1' seq.
	}


	for(int i = 0; i < M; ++i){
		cin >> b >> c;
		int sum = pSum[c] - pSum[b-1];
		cout << sum << "\n";
	}


}
