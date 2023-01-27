#include <bits/stdc++.h>
using namespace std;

const int N = 5;
map<int,int> mp;
int mat[N+4][N+4];
int vis[N+4][N+4];
char a;
int r, c, k;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};


void m_p(int z[N+4][N+4]){
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			cout << z[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void dfs(int y, int x, int turn){
	if(y == 0 && x == c-1){
		mp[turn]++;
		//m_p(vis);
		return;
	}

	for(int i = 0; i < 4; ++i){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
		if(mat[ny][nx] == 9) continue;
		if(vis[ny][nx]) continue;

		vis[ny][nx] = 1;
		dfs(ny,nx,turn+1);
		vis[ny][nx] = 0;
	}
	return;

}


int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c >> k;
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			cin >> a;
			if(a == '.') mat[i][j] = 0;
			if(a == 'T') mat[i][j] = 9;
		}
	}

	vis[r-1][0] = 1;
	dfs(r-1,0,1);

	cout << mp[k] << "\n";
	return 0;

}
