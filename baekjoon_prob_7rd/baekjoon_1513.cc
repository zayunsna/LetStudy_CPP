#include <bits/stdc++.h>
using namespace std;

const int N = 50;
const int mod = 1000007;
int dp[N+4][N+4][N+4][N+4];
int mat[N+4][N+4];
int n, m, c;
int y, x;

int solve(int y, int x, int cnt, int prev){
	if(y > n || x > m ) return 0;
	if(y == n && x == m){
		if(cnt == 0 && mat[y][x] == 0) return 1;
		if(cnt == 1 && mat[y][x] > prev) return 1;
		return 0;
	}
	
	int &ret = dp[y][x][cnt][prev];
	if(ret != -1) return ret;
	ret = 0;
	
	if(mat[y][x] == 0){
		ret = (solve(y+1, x, cnt, prev) + solve(y, x+1, cnt, prev)) % mod;
	}
	else if(mat[y][x] > prev){
		ret = (solve(y+1, x, cnt-1, mat[y][x]) + solve(y, x+1, cnt-1, mat[y][x])) % mod;
	} 
	return ret;	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m >> c;
	for(int i = 0; i < c; ++i){
		cin >> y >> x;
		mat[y][x] = i+1;
	}
	
	memset(dp, -1, sizeof(dp));
	
	for(int i = 0; i <= c; ++i){
		cout << solve(1, 1, i, 0) << " ";
	}
}
