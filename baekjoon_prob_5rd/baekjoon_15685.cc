#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 100;
const int Inf = 1e9;
vector<int> yong[4][14];
int mat[N+4][N+4];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
int n, x, y, d, g;
int ret =0;

void solve(int y, int x, int d, int g){
	int nx = x;
	int ny = y;
	mat[ny][nx] = 1;
	for(int i = 0; i <= g; ++i){
		for(int dir : yong[d][i]){
			ny += dy[dir];
			nx += dx[dir];
			mat[ny][nx] = 1;
		}
	}
}

void makeGraph(){
	for(int i = 0; i < 4; ++i){
		yong[i][0].push_back(i);
		yong[i][1].push_back( (i+1)%4);
		for(int j = 2; j <= 10; ++j){
			int n = yong[i][j-1].size();
			for(int k = n-1; k >=0; --k){
				yong[i][j].push_back((yong[i][j-1][k]+1)%4);
			}
			for(int k = 0; k < n; ++k){
				yong[i][j].push_back(yong[i][j-1][k]);
			}
		}
	}
}

bool check(int y, int x){
	if(mat[y][x] && mat[y+1][x] && mat[y][x+1] && mat[y+1][x+1]) return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	makeGraph();
	for(int i = 0; i < n; ++i){
		cin >> x >> y >> d >> g;
		solve(y, x, d, g);
	}
	for(int i = 0; i <= N; ++i){
		for(int j = 0 ; j <= N; ++j){
			if(check(i,j)) ret++;
		}
	}
	cout << ret << "\n";
	return 0;
}
