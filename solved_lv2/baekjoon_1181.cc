#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int Inf = 1e9;
int n;
string str;
vector<pair<int,string>> vp;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i = 0 ; i < n; ++i){
		cin >> str;
		vp.push_back({str.length(), str});
	}
	
	sort(vp.begin(), vp.end());
	vp.erase(unique(vp.begin(), vp.end()), vp.end());
	
	for(auto it : vp){
		cout << it.second << "\n";
	}
	cout << "\n";
}
