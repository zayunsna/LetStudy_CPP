#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 50;
const int Inf = 987654321;
int mat[N+4][N+4];
bool vis[N+4][N+4];
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


void run(int cnt, int py, int px, int y, int x){

	if(y == 0 && x == 0){
		if( ans > cnt) ans = cnt;
		return;
	}

	if(y < 0 || x < 0 || y >= n || x >= n || vis[y][x] ) {
		return;
	}
	if( mat[y][x] == 0){
		return;
	}
	if(x+y+cnt >= ans) {
		return;
	}

	vis[y][x] = true;

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
		run(cnt+1, y, x, ny, nx);
	}
	else{
		if(px == x){
			run(cnt+1, y, x, y, x+1);
			run(cnt+1, y, x, y, x-1);
		}
		else if(py == y){
			run(cnt+1, y, x, y+1, x);
			run(cnt+1, y, x, y-1, x);
		}
	}
	vis[y][x] = false;
	return ;
}

void Init(){
	//memset(mat,0,sizeof(mat));
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			mat[i][j] = 0;
			vis[i][j] = false;
		}
	}
	ans = Inf;
}

void pipe_ver2(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	for(int tc = 1; tc <= T; ++tc){
		Init();
		cin >> n;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				cin >> mat[i][j];
			}
		}

		run(1,n-1,n,n-1,n-1);

		cout << "#" << tc << " " << ans << "\n";
	}

}
