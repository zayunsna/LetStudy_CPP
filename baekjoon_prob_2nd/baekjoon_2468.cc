#include "/home/icegpu/HK/HKTool.h"
#include <ios>
using namespace std;

int mat[104][104];
int vis[104][104];

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int n, ny, nx;
int cnt = 0, mx = 0, mcnt =0;

void bfs(int cri, int y, int x, int n){
	queue<pair<int,int>> q;
	vis[y][x] = 1;
	q.push(make_pair(y,x));

	while(q.size()){
		auto it = q.front(); q.pop();
		for(int i = 0; i < 4; ++i){
			ny = it.first + dy[i];
			nx = it.second + dx[i];
			if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if(mat[ny][nx] > cri && !vis[ny][nx]){
				//vis[ny][nx] = vis[it.first][it.second] + 1;
				vis[ny][nx] = 1;
				q.push(make_pair(ny,nx));
			}
		}
	}
	cnt++;
	return;
}


void baekjoon_2468(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> mat[i][j];
			if(mx < mat[i][j]) mx = mat[i][j];
		}
	}

	for(int i = 1; i < mx; ++i){
		fill(&vis[0][0], &vis[0][0]+104*104, 0);
		for(int j = 0; j < n; ++j){
			for(int k = 0; k < n; ++k){
				if(mat[j][k] > i && !vis[j][k]) bfs(i, j, k, n);
			}
		}

		if(mcnt < cnt) mcnt = cnt;
		cnt = 0;
	}

	cout << mcnt << "\n" ;

}
