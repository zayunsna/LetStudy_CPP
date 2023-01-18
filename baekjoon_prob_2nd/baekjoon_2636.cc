#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

int n, m;
const int N = 100;
int mat[N][N];
int vis[N][N];
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

void bfs(int y, int x){
	queue<pair<int,int>> q;
	q.push({y,x});

	vis[y][x] = 1;
	while(q.size()){
		auto it = q.front(); q.pop();
		for(int i = 0; i < 4; ++i){
			int ny = it.first + dy[i];
			int nx = it.second + dx[i];
			if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if(vis[ny][nx]) continue;
			if(mat[ny][nx] == 1) continue;
			vis[ny][nx] = 1;
			q.push({ny,nx});
		}
	}
	return;
}

bool check(int y, int x){

	int cnt = 0;
	for(int i = 0; i < 4; ++i){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(vis[ny][nx] == 1) cnt++;
	}

	if(cnt >= 1) return true;
	return false;
}

void baekjoon_2636(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for(int i =0 ; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> mat[i][j];
		}
	}

	int ret = 0;
	int cnt = 0;
	int prev = 0;


	while(true){
		cnt = 0;
		memset(vis, 0, sizeof(vis));
		bfs(0,0);
		for(int i =0 ; i < n; ++i){
			for(int j = 0; j < m; ++j){
				if(mat[i][j] == 1){
					if(check(i,j)) {
						mat[i][j] = 0;
						cnt++;
					}
				}
			}
		}
		if(cnt){
			ret++;
			prev = cnt;
		}
		else{
			break;
		}
	}

	cout << ret << "\n";
	cout << prev << "\n";

}
