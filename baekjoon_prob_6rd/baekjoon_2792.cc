#include <bits/stdc++.h>
using namespace std;

typedef vector<pair<int,int>> vp;
const int N = 300000;
const long long Inf = 1e18;

long long n, m;
long long arr[N+4];
long long ret = Inf;

bool check(long long mid){
	long long num = 0;
	for(int i = 0; i < m; ++i){
		num += arr[i] / mid;
		if(arr[i] % mid) num++;
	}
	return n >= num;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	long long low = 1, high = 0, mid;
	for(int i = 0; i < m; ++i){
		cin >> arr[i];
		high = max(high, arr[i]);
	}
	
	while(low <= high){
		mid = (low + high) / 2;
		if(check(mid)){
			ret = min(ret, mid);
			high = mid - 1;
		}
		else{
			low = mid +1;
		}
	}
	
	cout << ret << "\n";
	
	return 0;
	
}
