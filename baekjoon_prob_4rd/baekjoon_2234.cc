#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

int n, m;
int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0 , 1, 0};

int mat[54][54];
int vis[54][54];

int comp[2048];
int g_cnt = 1;
int mx = 0;
int g_mx = 0;

void m_p(int t[54][54]){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cout << t[i][j] << " ";
		}
		cout << "\n";
	}
}

int bfs(int y, int x){

	int cnt = 0;
	queue<pair<int,int>> q;
	q.push({y,x});
	vis[y][x] = g_cnt;

	while(q.size()){
		auto it = q.front(); q.pop();
		int tar = 15 - mat[it.first][it.second];
		for(int j = 0; j < 4; ++j){
			if( tar & (1 << j)){
				int ny = it.first+dy[j];
				int nx = it.second+dx[j];
				if(vis[ny][nx]) continue;
				vis[ny][nx] = g_cnt;
				q.push({ny, nx});
				cnt++;
			}
		}
	}
	return cnt+1;
}

void baekjoon_2234(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m >> n;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> mat[i][j];
		}
	}

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(!vis[i][j]) {
				int this_mx = bfs(i,j);
				mx = max(mx, this_mx);
				comp[g_cnt] = this_mx;
				g_cnt++;
			}
		}
	}

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if( i < n-1){
				int a = vis[i][j];
				int b = vis[i+1][j];
				if( a != b) g_mx = max( g_mx, comp[a]+comp[b]);
			}
			if( j < m-1){
				int a = vis[i][j];
				int b = vis[i][j+1];
				if( a != b) g_mx = max( g_mx, comp[a] + comp[b]);
			}
		}
	}
	cout << g_cnt-1 << "\n";
	cout << mx << "\n";
	cout << g_mx << "\n";
}
