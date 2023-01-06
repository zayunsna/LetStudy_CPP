#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

int n, m;
int mat[54][54];
int vis[54][54];

const int Inf = 999999999;
int minVal = Inf;

vector<int> ret;

typedef vector<pair<int,int>> vp;
vp dak;
vp zip;

int dist(pair<int,int> a, pair<int,int> b){
	return abs(a.first-b.first) + abs(a.second - b.second);
}
void dfs(vp pp, int cnt){
	if(cnt == zip.size()){
		ret.push_back(minVal);
		return;
	}
	for(int i = 0; i < pp.size(); ++i){
		
	}

}

void run(int cnt, vp contain){
	if(contain.size() == m){
		int this_min = 0;
		for(auto it : zip){
			minVal = Inf;
			for(int i = 0; i < contain.size(); ++i){
				minVal = min(minVal, dist(contain[i], it));
			}
			this_min += minVal;
		}
		ret.push_back(this_min);
		return;
	}
	for(int i = cnt+1; i < dak.size(); ++i){
		auto it = dak[i];
		contain.push_back(it);
		run(i, contain);
		contain.pop_back();
	}
	return;

}

void baekjoon_15686(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for( int i = 0; i < n; ++i){
		for(int j = 0 ; j < n; ++j){
			cin >> mat[i][j];
			if(mat[i][j] == 1) zip.push_back({i,j});
			else if(mat[i][j] == 2) dak.push_back({i,j});
		}
	}


	vp contain;
	run(-1, contain);

	cout << *min_element(ret.begin(), ret.end()) << "\n";

}
