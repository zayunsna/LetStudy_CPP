#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> m;
		v.push_back(m);
	}
	sort(v.begin(), v.end());

	for(int it : v) cout << it << "\n";
	

	return 0;
}
