#include "/home/icegpu/HK/HKTool.h"
#include <ios>
using namespace std;

int N;
int n, m, ny, nx, B, tx, ty;
int mat[54][54];
int visited[54][54];

int dy[4] = {1, 0, -1 ,0};
int dx[4] = {0, 1, 0, -1};

int a, b;

int cnt = 0;

void bfs(int y, int x, int n, int m){

	queue<pair<int,int>> q;
	q.push(make_pair(y,x));
	visited[y][x] = 1;
	//cout << y << "  " << x << " = " << mat[y][x] <<  "\n";
	while(q.size()){
		auto it = q.front(); q.pop();
		for(int i = 0; i < 4; ++i){
			ny = it.first + dy[i];
			nx = it.second + dx[i];
			if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if(mat[ny][nx] == 1 && !visited[ny][nx]){
				visited[ny][nx] = visited[it.first][it.second] + 1;
				q.push(make_pair(ny,nx));
				//cout << ny << "  " << nx << " = " << mat[y][x] <<  " is pushed \n";
			}
		}
	}

	cnt++;
	return;
}



void baekjoon_1012(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	cin >> N;
	for(int ii = 0; ii < N; ++ii){

		fill(&visited[0][0], &visited[0][0]+54*54, 0);
		fill(&mat[0][0], &mat[0][0] + 54*54, 0);
		cin >> n >> m >> B;

		for(int i = 0; i < B; ++i){
			cin >> ty >> tx;
			mat[ty][tx] = 1;
		}

		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				//cout << i << "  " << j << "  " << mat[i][j] << "  " << visited[i][j] << "\n";
				if(mat[i][j] == 1 && !visited[i][j]) {
					//cout << "First input : " << i << "  " << j << "  " << mat[i][j] << "\n";
					bfs(i,j,n,m);
				}
			}
		}

		cout << cnt << "\n";
		cnt = 0;
	}
	


}
