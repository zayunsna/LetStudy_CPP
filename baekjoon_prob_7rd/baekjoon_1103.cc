#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

const int MAX = 54;
const int Inf = 987654321;
int mat[MAX][MAX];
int dp[MAX][MAX][4];
int vis[MAX][MAX];
int n,m;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

char a;

int run(int y, int x, int dir){
	if(mat[y][x] == 0){
		cout << " End Fcn \n";
		return 0;
	}

	cout << " Input : " << y << "  " << x << "  " << dir << "\n";
	if(vis[y][x]){
		cout << -1 << "\n";
		exit(0);
	}

	int &ret = dp[y][x][dir];
	cout << " DP Check : " << ret << "\n";
	if(ret != -1){
		cout << " ## Already visited : " << ret << "\n";
		return ret;
	}

	ret = 1;
	vis[y][x] = 1;
	for(int i = 0; i < 4; ++i){
		int ny = y + dy[i]*mat[y][x];
		int nx = x + dx[i]*mat[y][x];
		cout << " Dir : " << i << " Distance : " << mat[y][x] << ", from current y:x" << y << " : " << x << ",  So it will move  " << ny << " : " << nx << "\n"; 
		if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

		cout << " Go Next Recursion : " << ny << "  " << nx <<  "  " <<  i << "\n";
		ret = max(ret, run(ny, nx, i)+1);
		cout << " Return from Recursion with : " << ret << "\n";
	}

	vis[y][x] = 0;
	return ret;
}


void baekjoon_1103(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> a;
			if(a == 'H') mat[i][j] = 0;
			else mat[i][j] = (int)a-'0';
		}
	}

	memset(dp, -1, sizeof(dp));

	int ret = run(0,0,0);

	cout << (ret >= Inf ? -1 : ret) << "\n";
}
