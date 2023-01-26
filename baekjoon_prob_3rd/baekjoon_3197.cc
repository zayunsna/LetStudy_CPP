#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

typedef vector<pair<int,int>> vp;
int n, m;
const int N = 1500;
int mat[N+4][N+4];
int vis[N+4][N+4];
int ret;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

bool bfs(int y, int x){
	queue<pair<int,int>> q;
	q.push({y,x});
	vis[y][x] = 1;
	int flag = 0;
	while(q.size()){
		auto it = q.front(); q.pop();
		for(int i = 0; i < 4; ++i){
			int ny = it.first + dy[i];
			int nx = it.second + dx[i];
			if(ny < 0 || nx < 0 || ny >= n || nx >= m )continue;
			if(vis[ny][nx])continue;
			if(mat[ny][nx] == 1){
				vis[ny][nx] = 1;
				mat[ny][nx] = 0;
			}
			else if(mat[ny][nx] == 0){
				vis[ny][nx] = 1;
				q.push({ny,nx});
			}
			else if(mat[ny][nx] == 9){
				flag = 1;
				break;
			}
		}
		if(flag) break;
	}
	if(flag) return true;
	return false;
	
}

void solve(){
	while(true){
		memset(vis, 0, sizeof(vis));
		bool cond = false;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				if(!vis[i][j]) cond = bfs(i,j);
			}
		}
		ret++;
		if(cond) break;
	}
	cout << ret << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> n;
	for(int i =0 ; i < n; ++i){
		for(int j = 0; j < m; ++j){
			char a;
			cin >> a;
			if(a == '.') mat[i][j] = 0;
			else if(a == 'X') mat[i][j] = 1;
			else if(a == 'L') mat[i][j] = 9;
		}
	}


	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cout << mat[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
	
}
