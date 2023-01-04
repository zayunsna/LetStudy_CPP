#include "/home/icegpu/HK/HKTool.h"
#include <ios>
#include <utility>
using namespace std;

int mat[104][104];
int visited[104][104];
int n, m, ny, nx;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
string str;


void bfs(int x, int y, int n, int m){

	queue<pair<int,int>> q;
	q.push(make_pair(y, x));
	visited[y][x] = 1;
	while(q.size()){
		auto it = q.front(); q.pop();
		for(int i = 0; i < 4; ++i){
			ny = it.first + dy[i];
			nx = it.second + dx[i];
			if( ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] == 1) continue;
			if(mat[ny][nx] == 1 && !visited[ny][nx]){
				visited[ny][nx] = visited[it.first][it.second] + 1;
				q.push(make_pair(ny, nx));
			}
		}
	}
	return;
}

void baekjoon_2178(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	
	for(int i = 0; i < n; ++i){
		cin >> str;
		for(int j = 0; j < m; ++j){
			mat[i][j] = (int)str[j]-'0';
		}
	}

	bfs(0,0,n,m);


	cout << visited[n-1][m-1] << "\n";

}
