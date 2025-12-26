#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int Inf = 1e9;
int n, m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	string tmp;
	unordered_map<string, int> list_all;
	for(int i = 0; i < n; ++i){
		cin >> tmp;
		list_all[tmp]++;
	}
	int count = 0;
	vector<string> res;
	for(int i = 0; i < m; ++i){
		cin >> tmp;
		if(list_all[tmp] != 0){
			count++;
			res.push_back(tmp);
		}
	}
	sort(res.begin(), res.end());

	cout << count << endl;
	for(auto i : res) cout << i << endl;
}
