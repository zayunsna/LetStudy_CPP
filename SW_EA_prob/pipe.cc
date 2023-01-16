#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 50;
const int Inf = 987654321;
int mat[N][N];
int vis[N][N];
int dp[N][N][N][N];
int n;
int ans;
int T;

void m_p(int m[N][N]){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cout << m[i][j] << " ";
		}
		cout << "\n";
	}
}


void run(int cnt, int py, int px, int y, int x, int dir){


	if(cnt > ans) return;
	if(dir == 1){
		if(y == 0 && x == -1){
			//cout << " Back traking \n";
			//m_p(vis);
			if( ans > cnt) ans = cnt;
			return;
		}
	}
	else if(dir == 0){
		if(y == n-1 && x == n-1){
			//cout << " Foward traking \n";
			//m_p(vis);
			if( ans > cnt) ans = cnt;
			return;
		}
	}

	if(y < 0 || x < 0 || y >= n || x >= n || vis[y][x]) {
		//cout << " Null break \n";
		return;
	}
	if( mat[y][x] == 0){
		//cout << " no data\n";
		return;
	}
	if(x+y+cnt >= ans) {
		//cout << " No need to go\n";
		return;
	}

	int &ret = dp[py][px][y][x];
	//cout << " DP check : " << ret << "\n";
	if( ret < cnt ){
		ret = cnt;
		return;
	}
	ret = cnt;

	vis[y][x] = 1;

	if(mat[y][x] < 3){
		int ny, nx;
		if(px == x){
			ny = y+y-py;
			nx = x;
		}
		else if(py == y){
			ny = y;
			nx = x+x-px;
		}
		if( py == 0 && px == 0 && y == 0 && x== 0) ny = 0, nx = 1;	
		run(cnt+1, y, x, ny, nx,dir);
	}
	else{
		if(px == x){
			run(cnt+1, y, x, y, x+1, dir);
			run(cnt+1, y, x, y, x-1, dir);
		}
		else if(py == y){
			run(cnt+1, y, x, y+1, x, dir);
			run(cnt+1, y, x, y-1, x, dir);
		}
	}
	vis[y][x] = 0;
	return ;
}

void Init(){
	memset(vis,0,sizeof(vis));
	memset(dp, 300, sizeof(dp));
	ans = Inf;
}

void pipe(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	for(int tc = 1; tc <= T; ++tc){
		memset(mat,0,sizeof(mat));
		Init();
		cin >> n;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				cin >> mat[i][j];
			}
		}
		
		run(0,n-1,n,n-1,n-1, 1);
		int back = ans;
		memset(vis,0,sizeof(vis));
		memset(dp, 300, sizeof(dp));
		run(0,0,-1,0,0,0);
		int go = ans;

		//cout << "#" << tc << " " << ans << "\n";
		cout << "#" << tc << " " << min(back, go) << "\n";
	}

}
