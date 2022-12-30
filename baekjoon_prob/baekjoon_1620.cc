#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
#include <ios>
using namespace std;

int N, M;
const int Inf = 200005;
map<string, int> map1;
map<int, string> map2;
string str;

void baekjoon_1620(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for(int i = 0; i < N; ++i){
		cin >> str;
		map1[str] = i+1;
		map2[i+1] = str;
	
	}

	for(int i = 0; i < M; ++i){
		cin >> str;
		if(atoi(str.c_str()) == 0){
			cout <<  map1[str]<< "\n";
		}
		else{
			cout << map2[atoi(str.c_str())]  << "\n";
		}
	}



}
