#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int Inf = 1e9;
const int N = 4000;
int n, m;
vector<int> v;
map<int,int> mp;

bool cmp(pair<int,int> a, pair<int,int> b){
	if(a.second > b.second) return a.second > b.second;
	else return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	double sum = 0;
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> m;
		v.push_back(m);
		sum += m;
		mp[m]++;
	}
	
	
	double ret1 = floor((sum/n) + 0.5);
	
	sort(v.begin(), v.end());
	int ret2 = v[n/2];
	int ret3 = 0;
	vector<pair<int,int>> vp;
	for(auto it : mp) vp.push_back({it.first, it.second});
	sort(vp.begin(), vp.end(), cmp);
	if(vp.size() > 1){
		if(vp[0].second == vp[1].second) ret3 = vp[1].first;
		else ret3 = vp[0].first;
	}
	else ret3 = vp[0].first;

	int ret4 = v[n-1]-v[0];
	

	cout << ret1 << "\n" << ret2 << "\n" << ret3 << "\n" << ret4 << "\n"; 
	
}
