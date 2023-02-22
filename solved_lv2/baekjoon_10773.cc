#include <bits/stdc++.h>
using namespace std;

int n, a;
vector<int> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> a;

		if( a == 0) v.pop_back();
		else v.push_back(a);
	}

	int ret = accumulate(v.begin(), v.end(),0);

	cout << ret << "\n";

	return 0;
}
