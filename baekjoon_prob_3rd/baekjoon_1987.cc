#include <bits/stdc++.h>
using namespace std;

typedef vector<pair<int,int>> vp;
const int N = 20;
char mat[N+4][N+4];
int vis[30];
int n, m;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int ret = -1;

void dfs(int y, int x, int depth){

	ret = max(ret, depth);

	for(int i = 0; i < 4; ++i){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		int _num = (int)mat[ny][nx] - 'A';
		if(vis[_num])continue;
		vis[_num] = 1;
		dfs(ny,nx,depth+1);
		//cout << " Return back with "  << ny << " : " << nx << "  " << mat[ny][nx] << "\n";
		vis[_num] = 0;
	}
	return;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for(int i = 0; i < n; ++i){
		for(int j = 0 ; j < m; ++j){
			char a;
			cin >> a;
			mat[i][j] = a;
		}
	}

	vis[mat[0][0]-'A'] = 1;
	dfs(0,0,1);
	cout << ret << "\n";
	return 0;


}
