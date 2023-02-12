#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int Inf = 1e9;
int n, m;
vector<int> a;

bool solve(int aa ,int bb, int val){
	int mid = (aa+bb)/2;
	int mVal = a[mid];
	
	if(val < mVal) return solve(aa, mid, val);
	else return solve(mid, bb, val);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> m;
		a.push_back(m);
	}
	
	sort(a.begin(), a.end());
	
	
	
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> m;
		bool ret = solve(0, a.size(), m);
		if(ret) cout << "1\n";
		else cout << "0\n";
	}
	
	return 0;
}
