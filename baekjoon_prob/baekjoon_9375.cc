#include "/home/icegpu/HK/HKTool.h"
using namespace std;

map<string, int> map1;
int T, N;
string clo, typ;


void baekjoon_9375(){

	cin >> T;
	for(int i = 0; i < T; ++i){
		map1.clear(); 
		cin >> N;
		for(int j = 0; j < N; ++j){
			cin >> clo >> typ;
			map1[typ]++;
		}
		long long sum = 1;
		for(auto it : map1)	sum *= ((long long)it.second +1);

		cout << sum-1 << "\n";

	}

}
