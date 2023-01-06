#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

typedef vector<pair<int,int>> vp;
const int Inf = 999999999;
int n,m;
char mat[54][54];
char vis[54][54];
vp land;
int mx = 0;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int bfs(pair<int,int> p){

	int re = 0;
	queue<pair<int,int>> q;
	q.push(p);
	vis[p.first][p.second] = 1;
	while(q.size()){
		auto it = q.front(); q.pop();
		for(int i = 0; i < 4; ++i){
			int ny = it.first + dy[i];
			int nx = it.second + dx[i];
			if(ny < 0 || nx < 0 || ny >= n || nx >= m || vis[ny][nx] || mat[ny][nx] == 'W') continue;
			vis[ny][nx] = vis[it.first][it.second]+1;
			re = vis[ny][nx];
			q.push({ny,nx});
		}
	}

	return re-1;


}

int run(){
	for(auto it : land){
		fill(&vis[0][0], &vis[0][0]+54*54, 0);
		mx = max(mx, bfs(it));
	}

	return mx;
}



void baekjoon_2589_ver2(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for(int i = 0; i < n; ++i){
		for(int j = 0;  j < m; ++j){
			cin >> mat[i][j];
			if(mat[i][j] == 'L') land.push_back({i,j});
		}
	}

	cout << run() << "\n";

}
