#include <bits/stdc++.h>
using namespace std;

const int Inf = 987654321;
const int N = 1004;
char mat[N][N];
int vis[N][N];
int f_vis[N][N];
int r, c;
int ret;

pair<int,int> jihoon;
pair<int,int > fire;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int bfs(int y, int x){
	queue<pair<int,int>> q;
	q.push({y,x});

	vis[y][x] = 1;

	int cnt = Inf;

	while(q.size()){
		auto it = q.front(); q.pop();
		if(it.first == 0 || it.first == r-1 || it.second == 0 || it.second == c-1){
			cnt = vis[it.first][it.second];
			break;
		}
		for(int i = 0; i < 4; ++i){
			int ny = it.first + dy[i];
			int nx = it.second + dx[i];
			if(mat[ny][nx] == '#' || ny < 0 || nx < 0 || ny >= r || nx >= c )continue;
			if(vis[ny][nx]) continue;
			vis[ny][nx] = vis[it.first][it.second] + 1;
			if(vis[ny][nx] >= f_vis[ny][nx]) continue;

			q.push({ny,nx});
		}
	}

	return cnt;
}
void m_p(int z[N][N]){
	for(int i = 0 ; i < r; ++i){
		for(int j = 0; j < c; ++j){
			cout << z[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void baekjoon_4179()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	queue<pair<int,int>> f_q;

	memset(vis, 0, sizeof(vis));
	memset(f_vis,0,sizeof(f_vis));
	fill(&f_vis[0][0], &f_vis[0][0] + N*N, Inf);

	cin >> r >> c;
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			cin >> mat[i][j];
			if( mat[i][j] == 'J') jihoon = make_pair(i,j);
			if( mat[i][j] == 'F') {
				f_vis[i][j] = 1;
				f_q.push({i,j});
			}
		}
	}

	while(f_q.size()){
		auto it = f_q.front(); f_q.pop();
		for(int i = 0; i < 4; ++i){
			int ny = it.first + dy[i];
			int nx = it.second + dx[i];
			if(ny < 0 || nx < 0 || ny >= r || nx >= c )continue;
			if(mat[ny][nx] == '#') continue;
			if( f_vis[ny][nx] != Inf) continue;

			f_vis[ny][nx] = f_vis[it.first][it.second] + 1;
			
			f_q.push({ny,nx});	
		}
	}
	
	int jm = bfs(jihoon.first, jihoon.second);

	if(jm == Inf) cout << "IMPOSSIBLE\n";
	else cout << jm << "\n";


}
