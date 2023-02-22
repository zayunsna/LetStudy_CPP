#include <bits/stdc++.h>
using namespace std;

int n, y, x;
vector<pair<int,int>> vp;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> x >> y;
		vp.push_back({y,x});
	}

	sort(vp.begin(), vp.end());

	for(auto it : vp) cout << it.second << " " << it.first << "\n";

	return 0;
}
