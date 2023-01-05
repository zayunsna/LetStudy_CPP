#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

int n, m;
int mat[10][10];
int vis[10][10];

typedef vector<pair<int,int>> vp;
vp can;
vp zz;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

void m_print(int mx[10][10]){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cout << mx[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void dfs(int y, int x){
	for(int i = 0; i < 4; ++i){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m || vis[ny][nx] || mat[ny][nx] == 1) continue;
		vis[ny][nx] = 1;
		dfs(ny, nx);
	}
	return;
}


int fcn(){
	fill(&vis[0][0], &vis[0][0] + 10*10, 0);
	m_print(mat);
	for(int i = 0; i < zz.size(); ++i){
		auto it = zz[i];
		vis[it.first][it.second] = 1;
		dfs(it.first, it.second);
	}

	m_print(vis);
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(mat[i][j] == 0 && !vis[i][j]) cnt++;
		}
	}
	return cnt;
}

void baekjoon_14502(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> mat[i][j];
			if(mat[i][j] == 0) can.push_back({i,j});
			if(mat[i][j] == 2) zz.push_back({i,j});
		}
	}
	int ret = 0;
	for(int i = 0; i < can.size(); ++i){
		for(int j = i+1 ; j < can.size(); ++j){
			for(int k = j+1; k < can.size(); ++k ){
				auto it1 = can[i];
				auto it2 = can[j];
				auto it3 = can[k];
				mat[it1.first][it1.second] = 1;
				mat[it2.first][it2.second] = 1;
				mat[it3.first][it3.second] = 1;
				ret = max(ret, fcn());
				mat[it1.first][it1.second] = 0;
				mat[it2.first][it2.second] = 0;
				mat[it3.first][it3.second] = 0;
			}
		}
	}


	cout << ret << "\n";

}
