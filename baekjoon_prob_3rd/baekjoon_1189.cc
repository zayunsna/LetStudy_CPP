#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

int r, c, k;
string cr;
int mat[10][10];
int vis[10][10];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int cnt = 0;
vector<int> ret;

void m_p(int b[10][10]){
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 4; ++j){
			cout << b[i][j] << " ";	
		}
		cout << "\n";
	}
}


void dfs(int y, int x){
	if( y == 0 && x == c-1){
		ret.push_back(vis[y][x]);
		return;
	}
	for(int i =0 ; i < 4; ++i){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if( ny < 0 || nx < 0 || ny >= r || nx >= c || vis[ny][nx] || mat[ny][nx] == 2) continue;
		vis[ny][nx] = vis[y][x] +  1;
		dfs(ny, nx);
		vis[ny][nx] = 0;
	}
}



void baekjoon_1189(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c >> k;
	for(int i = 0; i < r; ++i){
		cin >> cr;
		for(int j = 0; j < c; ++j){
			if(cr[j] == 'T')mat[i][j] = 2;
			else mat[i][j] = 0;
		}
	}

	vis[r-1][0] = 1;
	dfs(r-1,0);	

	int tcnt = 0;
	for(auto it : ret){
		if( it == k ) tcnt++;
	}

	cout << tcnt << "\n";

}
