#include <bits/stdc++.h>
using namespace std;

const int N = 20;
const int Inf = 1e9;
int n;
int man[N+4][N+4];
int ret = Inf;

int solve(vector<int> a, vector<int> b){
	int home = 0;
	int away = 0;
	for(int i = 0; i < n/2; ++i){
		for(int j = 0; j < n/2; ++j){
			home += man[a[i]][a[j]];
			away += man[b[i]][b[j]];
		}
	}

	return abs(home - away);
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	cin >> n;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			cin >> man[i][j];

	vector<int> start;
	vector<int> link;
	for(int i = 0; i < (1 << n); ++i){
		start.clear();
		link.clear();
		if(__builtin_popcount(i) != n/2) continue;

		for(int j = 0; j < n; ++ j){
			if( i & (1<<j)) start.push_back(j);
			else link.push_back(j);
		}

		ret = min(ret, solve(start, link));

		//for(auto it : start ) cout << it << " ";
		//cout << "\n";
	}

	cout << ret << "\n";

	return 0;
}
