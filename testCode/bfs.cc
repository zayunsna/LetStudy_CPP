#include "/home/icegpu/HK/HKTool.h"
#include <cstdio>
#include <ios>
using namespace std;

int n, m;
int ID_x, ID_y;
int g_x, g_y;
int nx, ny;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int visited[10][10];
int mat[10][10];

void go(int y, int x){
	queue<pair<int,int>> q;
	
	visited[y][x] = 1;
	q.push(make_pair(x,y));
	while(q.size()){
		auto it = q.front(); q.pop();
		for(int i = 0; i < 4; ++i){
			ny = it.first + dy[i];
			nx = it.second + dx[i];
			if( ny < 0 || nx < 0 || nx >= 5 || ny >= 5 || mat[ny][nx] == 0) continue;
			if(mat[ny][nx] == 1 && !visited[ny][nx]){
				visited[ny][nx]  = visited[it.first][it.second] + 1;
				q.push(make_pair(ny, nx));
			}
		}
	}

	return;

}


void bfs(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	cin >> ID_x >> ID_y;
	cin >> g_x >> g_y;

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> mat[i][j];
		}
	}

	go(ID_y, ID_x);

	cout << visited[g_y][g_x]  << "\n";

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cout << visited[i][j] << "  ";
		}
		cout << "\n";
	}


}
