#include "/home/icegpu/HK/HKTool.h"
using namespace std;

int N, K, a;
int temp[100050];
int sum = 0;
int mmax = -99999999;

void baekjoon_2559(){

	cin >> N >> K;


	for(int i = 1;  i <= N; ++i){
		cin >> a;
		temp[i] = a + temp[i-1];
	}

	for(int i = K; i <= N; ++i){
		sum = temp[i]-temp[i-K];
		if(mmax < sum) mmax = sum;
	}

	cout << mmax << "\n";



}
