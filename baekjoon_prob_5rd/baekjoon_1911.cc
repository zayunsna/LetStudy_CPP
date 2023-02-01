#include <bits/stdc++.h>
using namespace std;

int n, m, now, ret, here;
vector<pair<int,int>> vp;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for(int i = 0; i < n; ++i){
		int a, b;
		cin >> a >> b;
		vp.push_back({a,b});
	}
	sort(vp.begin(), vp.end());
	for(auto it : vp){
		if(it.second <= now) continue;
		if(here < it.first){
			now = (it.second-it.first)/m + ( (it.second-it.first)%m ? 1 : 0);
			here = it.first + now*m;
		}
		else{
			now = (it.second-here)/m + ( (it.second-here)%m ? 1 : 0);
			here = here + now*m;
		}
		ret += now;
	}

	cout << ret << "\n";


	return 0;
}
