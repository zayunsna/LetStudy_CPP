#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

void baekjoon_2577(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a;
	long long multi = 1;
	int arr[10];
	memset(arr, 0, sizeof(arr));
	for(int i = 0; i < 3; ++i){
		cin >> a;
		multi *= a;
	}

	string str = to_string(multi);
	for(int i = 0; i < str.size(); ++i){
		int a = str[i] - '0';
		arr[a]++;
	}

	for(int it : arr) cout << it << "\n";

}
