#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int Inf = 1e9;
vector<int> v;
int n, m;
ll ret;

bool check(int num){
	int cnt =0 ;
	for(int it : v){
		cnt += it/num;
		if(cnt >= m) return true;
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for(int i = 0 ;i < n; ++i){
		int a; cin >> a;
		v.push_back(a);
	}
	
	ll init = 1;
	ll mx = *max_element(v.begin(), v.end());

	while(init <= mx){
		ll mid = (init+mx)/2;
		if(check(mid)){
			ret = max(ret, mid);
			init = mid + 1;
		}
		else{
			mx = mid - 1;
		}
	}
	
	cout << ret << "\n";
	
}
