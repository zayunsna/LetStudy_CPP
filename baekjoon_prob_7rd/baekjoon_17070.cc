#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

const int MAX = 16;
const int Inf = 987654321;
int dp[MAX][MAX][3];
int mat[MAX][MAX];
int n;
int dy[4] = {0,1,1,0};
int dx[4] = {1,1,0,0};


int run(int y, int x, int status){
	if( y == n-1 && x == n-1){
		cout << " End Fcn :" << 1 << "\n";
		return 1;
	}

	cout << " Input y:x = " << y << " : " << x << " with status : " << status << "\n";
	int &ret = dp[y][x][status];
	cout << " DP check : " << ret << "\n";
	if( ret != -1 ){
		cout << " This already visited with " << ret << "\n";
		return ret;
	}
	ret = 0;

	for(int i = 0; i < 3; ++i){
		if(status == 0 && i == 2) continue;
		if(status == 2 && i == 0) continue;
		int ny = y + dy[i];
		int nx = x + dx[i];
		cout << " next status :"<< i << " , Current status : " << status << " , next y,x : " << ny << " : " << nx << " == " << mat[ny][nx] << "\n";
		if(ny < 0 || nx <0 || ny >= n || nx >= n || mat[ny][nx]) continue;
		if(i == 1 && (mat[y][x+1]||mat[y+1][x])) continue;
	

		cout << " Go next recursion : " << ny << " : " << nx << " with status : " << i << "\n";
		ret += run(ny, nx, i);
		cout << " Return the recusion from " << ny << " : " << nx << " with ret : " << ret << "\n";
	}
	return ret;
}

void baekjoon_17070(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//memset(mat, 0, sizeof(mat));
	cin >> n;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n ; ++j){
			cin >> mat[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));

	int ret = run(0,1,0);
	cout << (ret == Inf ? 0 : ret) << "\n";


}
