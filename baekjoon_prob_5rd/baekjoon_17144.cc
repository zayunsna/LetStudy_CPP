#include <bits/stdc++.h>
using namespace std;

const int N = 50;
const int Inf = 1e9;
int mat[N+4][N+4];
int temp[N+4][N+4];
int vis[N+4][N+4];
int r, c, t;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int dir1[4] = {1, 0, -1, 0};
int dir2[4] = {0, 1, 0, -1};

vector<pair<int,int>> vp;

void spreadMonji(){

	memset(temp, 0, sizeof(temp));
	queue<pair<int,int>> q;
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			if(mat[i][j] != -1 && mat[i][j]){
				q.push({i,j});
			}
		}
	}

	while(q.size()){
		int a, b;
		tie(a,b) = q.front(); q.pop();
		int now = mat[a][b] / 5;
		for(int k = 0; k < 4; ++k){
			int ny = a + dy[k];
			int nx = b + dx[k];
			if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
			if(mat[ny][nx] == -1) continue;
			temp[ny][nx] += now;
			mat[a][b] -= now;
		}
	}
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			mat[i][j] += temp[i][j];
		}
	}

	return;
}
void circulate(){

	int up = vp[0].first;
	int down = vp[1].first;

	int ty = 0, tx = 0;
	int temp = mat[ty][tx];
	//int temp = 0;
	int d = 0;

	while(true){
		int ny = ty+dy[d];
		int nx = tx+dx[d];
		if(ny == 0 && nx == 0){
			mat[ty][tx] = temp;
			break;
		}
		if(ny >=0 && nx >=0 && ny <= up && nx < c && vis[ny][nx] == 0){
			mat[ty][tx] = mat[ny][nx];
			//mat[ny][nx] = mat[ty][tx];
			ty = ny; tx = nx;
			vis[ny][nx] = 1;
		}
		else{
			d = (d+1)%4;
		}
	}
	mat[up][0] = -1;
	mat[up][1] = 0;
	memset(vis, 0, sizeof(vis));

	ty = down, tx = 0;
	temp = mat[ty][tx];
	d = 0;
	while(true){
		int ny = ty+dir1[d];
		int nx = tx+dir2[d];
		if(ny == down && nx == 0){
			mat[ty][tx] = temp;
			break;
		}
		if(ny >= down && nx >= 0 && ny < r && nx < c && vis[ny][nx] == 0){
			mat[ty][tx] = mat[ny][nx];
			//mat[ny][nx] = mat[ty][tx];
			ty = ny; tx = nx;
			vis[ny][nx] = 1;
		}
		else{
			d = (d+1)%4;
		}
	}
	mat[down][0] = -1;
	mat[down][1] = 0;
	return ;
}

int calMonji(){
	int out = 0;
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			if(mat[i][j] == -1) continue;
			out += mat[i][j];
		}
	}
	return out;
}

void m_p(int z[N+4][N+4]){
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			cout << z[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c >> t;
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			cin >> mat[i][j];
			if( mat[i][j] == -1) vp.push_back({i,j});
		}
	}
	/*
	   m_p(mat);

	   spreadMonji();
	   m_p(mat);
	   circulate();
	   m_p(mat);
	   */
	for(int i = 0; i < t; ++i){
		spreadMonji();
		circulate();
		//m_p(mat);
	}

	int ret = calMonji();
	cout << ret << "\n";

	return 0;
}
