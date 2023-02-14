#include <bits/stdc++.h>
using namespace std;

int n, age;
string name;
vector<pair<int,int>> vp;
vector<string> vs;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> age >> name;
		vp.push_back({age, i});
		vs.push_back(name);
	}

	sort(vp.begin(), vp.end());

	for(auto it : vp){
		int seq = it.second;
		cout << it.first << "  " << vs[seq] << "\n";
	}

	return 0;
}
