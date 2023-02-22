#include <bits/stdc++.h>
using namespace std;

int n,m, ret;
vector<int> v;

bool check(int a){
	long long out = 0;
	for(int it : v){
		if( it >= a) out += it-a;
	}

	if(out >= m) return true;
	return false;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for(int i = 0; i < n; ++i){
		int a; cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	long long left = 0;
	long long right = v[n-1];
	long long mid = 0;
	while(left <= right){
		mid = (left+right)/2;
		if(check(mid)){
			left = mid +1;
			ret = mid;
		}
		else{
			right = mid -1;
		}
	}




	cout << ret << "\n";
	return 0;
}
