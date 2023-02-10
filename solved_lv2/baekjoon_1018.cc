#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 50;
const int Inf = 1e9;
const int s = 8;
char mat[N+4][N+4];
int vis[N+4][N+4];
int n, m;
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
int ret = Inf;

void drawAll(){
	for(int i = 0; i < n; ++i){
		for(int j = 0 ; j < m; ++j){
			char _this = mat[i][j];
			for(int k = 0; k < 4; ++k){
				int ny = i + dy[k];
				int nx = j + dx[k];
				if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
				if(_this == mat[ny][nx]){
					vis[ny][nx] = 1;
					if(_this == 'W') mat[ny][nx] = 'B';
					else mat[ny][nx] = 'W';
				}
			}
		}
	}
}

int search(int y, int x, int val){
	
	int cnt = 0;
	for(int i = y; i < y+s; ++i){
		for(int j = x; j < x+s; ++j){
			if(vis[i][j] == val) cnt++;
		}
	}
	
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for(int i = 0 ;i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> mat[i][j];
		}
	}
	drawAll();

	for(int i = 0 ; i <= n-s; ++i){
		for(int j = 0; j <= m-s; ++j){
			ret = min(ret, search(i,j,0));
			ret = min(ret, search(i,j,1));
		}
	}
	cout << ret << "\n";
	return 0;
}
