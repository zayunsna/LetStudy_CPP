#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> vp;
int n;
int x, y;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for(int i = 0; i < n; ++ i){
		cin >> x >> y;
		vp.push_back({x,y});
	}

	sort(vp.begin(), vp.end());

	for(auto it : vp) cout << it.first << " " << it.second << "\n";

	return 0;
}
