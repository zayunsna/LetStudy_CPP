#include <bits/stdc++.h>
using namespace std;

const int N = 500;
char mat[N+4][N+4];
int vis[N+4][N+4];
int dp[N+4][N+4];
int n, m, ret;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int flag;

void mp ( int z[N+4][N+4]){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cout << z[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void solve(int y, int x, int turn, int con){

	int &ddp = dp[y][x];
	if(ddp != -1) {
		if(ddp > turn) return;
	}

	for(int i = 0; i < 4; ++i){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(con >= 2) {
			if( con != i) flag = 1;
			else flag = 0;
		}
		if(flag){
			if(i >= 2 && i != con)continue;
		}
		if(ny < 0 || nx < 0 || ny >= n || nx >= m || vis[ny][nx] || mat[ny][nx] == '#' ) continue;
		vis[ny][nx] = 1;
		ret = max(ret, turn);
		//mp(vis);
		//cout << "Flag : " << flag << "  " << i << "  " << dy[i] << "  " << dx[i] << "\n";
		ddp = ret;
		solve(ny, nx, turn+1, i);
		flag = 0;
		vis[ny][nx] = 0;
	}

	return ;

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int tc;
	cin >> tc;
	for(int ic = 1; ic <= tc; ++ic){
		memset(vis, 0, sizeof(vis));
		memset(dp, -1, sizeof(dp));
		cin >> n >> m;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				cin >> mat[i][j];
			}
		}
		flag = 0;
		ret = 0;
		vis[0][0] = 1;
		solve(0,0,1,0);

		cout <<"#" << ic << " " << ret+1 << "\n";
	}

	return 0;
}
