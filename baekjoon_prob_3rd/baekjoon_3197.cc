#include <bits/stdc++.h>

using namespace std;

int n, m;
const int N = 1500;
int mat[N+4][N+4];
int vis[N+4][N+4];
int vis_swan[N+4][N+4];
int ret;

int tarX, tarY;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

queue<pair<int,int>> water_q;
queue<pair<int,int>> water_q2;
queue<pair<int,int>> swan_q;
queue<pair<int,int>> swan_q2;

void QClear(queue<pair<int,int>> &a){
	queue<pair<int,int>> noQ;
	swap(a, noQ);
}

void melting(){
	while(water_q.size()){
		auto it = water_q.front(); water_q.pop();
		for(int i = 0; i < 4; ++i){
			int ny = it.first + dy[i];
			int nx = it.second + dx[i];
			if(ny < 0 || nx < 0 || ny >= n || nx >= m )continue;
			if(vis[ny][nx])continue;
			if(mat[ny][nx] == 1){
				vis[ny][nx] = 1;
				water_q2.push({ny,nx});
				mat[ny][nx] = 0;
			}
		}
	}
}


bool bfs(){
	while(swan_q.size()){
		auto it = swan_q.front(); swan_q.pop();
		for(int i = 0; i < 4; ++i){
			int ny = it.first + dy[i];
			int nx = it.second + dx[i];
			if(ny < 0 || nx < 0 || ny >= n || nx >= m )continue;
			if(vis_swan[ny][nx])continue;
			vis_swan[ny][nx] = 1;
			if(mat[ny][nx] == 0){
				swan_q.push({ny,nx});
			}
			else if(mat[ny][nx] == 1){
				swan_q2.push({ny,nx});
			}
			else if(mat[ny][nx] == 9){
				return true;
			}
		}
	}
	return false;
}

void solve(){

	while(true){
		//memset(vis, 0, sizeof(vis));
		if(bfs()) break;
		melting();
		water_q = water_q2;
		swan_q = swan_q2;
		QClear(water_q2);
		QClear(swan_q2);
		ret++;
	}
	cout << ret << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for(int i =0 ; i < n; ++i){
		for(int j = 0; j < m; ++j){
			char a;
			cin >> a;
			if(a == '.' || a == 'L') {
				mat[i][j] = 0;
				water_q.push({i,j});
				vis[i][j] = 1;
			}
			if(a == 'X') mat[i][j] = 1;
			if(a == 'L') {
				mat[i][j] = 9;
				tarY = i; tarX = j;
			}
		}
	}
	swan_q.push({tarY, tarX});
	vis_swan[tarY][tarX] = 1;

	solve();

	return 0;

}
