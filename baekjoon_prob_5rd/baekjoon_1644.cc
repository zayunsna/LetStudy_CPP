#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;


const int N = 4000000;
int status[N];
int p[N/2];
int sum = 0;
int g, lo, hi, ret;
vector<int> setArr(int num){
	vector<int> t;
	for(int i = 2; i <= num; ++i){
		if(status[i]) continue;
		for(int j = 2*i; j<= num; j += i){
			status[j] = 1;
		}
	}
	for(int i = 2; i <= num; ++i) if(status[i] == 0) t.push_back(i);
	return t;
}
void baekjoon_1644(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	
	int n = 0, cnt = 0;
	cin >> n;

	vector<int> _list = setArr(n);


	cout << _list.size() << "\n";
	int low= 0, high= 0;
	int sum = 0;
	while(true){
		if( sum >= n){
			sum -= _list[low++];
		}
		else if(high == _list.size()) break;
		else{
			sum += _list[high++];
		}
		if(sum == n) cnt++;
	}

	cout << cnt << "\n";

}
