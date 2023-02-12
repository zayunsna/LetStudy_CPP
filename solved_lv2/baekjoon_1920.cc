#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int Inf = 1e9;
int n, m;
vector<int> a;

bool solve(int aa ,int bb, int val){
	int mid = (aa+bb)/2;
	int mVal = a[mid];
	
	if(aa>bb) return false;
	//cout << val << " = " << a[aa] << "  " << a[bb] << "  " << mVal << "\n";

	if(mVal < val) return solve(mid+1, bb, val);
	else if(mVal == val) return true;
	else return solve(aa, mid-1, val);

	return false;
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
		bool ret = solve(0, a.size()-1, m);
		if(ret) cout << "1\n";
		else cout << "0\n";
	}
	
	return 0;
}
