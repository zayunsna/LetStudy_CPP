#include <bits/stdc++.h>
using namespace std;

const int Inf = 987654321;
const int N = 10;
int vis[N+4][N+4];
int mat[N+4][N+4];
int n;
int ret = Inf;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

void drawVis(int y, int x, int status){

	vis[y][x] = status;
	for(int i = 0; i < 4; ++i){
		int ny = y + dy[i];
		int nx = x + dx[i];
		vis[ny][nx] = status;
	}

}
int cal(int y, int x){
	int out = mat[y][x];
	for(int i = 0; i < 4; ++i){
		int ny = y + dy[i];
		int nx = x + dx[i];
		out += mat[ny][nx];
	}
	return out;
}

bool IsOkay(int y, int x){
	for(int i = 0; i < 4; ++i){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(vis[ny][nx]) return false;
		if(ny < 0 || nx < 0 || ny >= n || nx >= n) return false;
	}
	return true;

}

void m_p(int z[N+4][N+4]){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cout << z[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";

}

void dfs(int y, int x, int turn, int sum){
	int now = sum + cal(y,x);

	if(now >= ret) return;
	cout  << " Input : " << y << "  " << x << "  " << turn << "  " << cal(y,x) << "  " << now << "\n";
//	m_p(vis);
	if(turn == 3){
		ret = min(ret, now);
		cout << " =========> " << ret << "\n";
		m_p(vis);
		return;
	}

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(IsOkay(i, j)){
				drawVis(i,j, 1);
				dfs(i, j, turn+1, now);
				drawVis(i, j, 0);
			}
		}
	}
	return;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> mat[i][j];
		}
	}

	for(int i = 1; i < n-1; ++i){
		for(int j = 1; j < n-1; ++j){
			drawVis(i,j,1);
			dfs(i,j,1,0);
			drawVis(i,j,0);
		}
	}

	cout << ret << "\n";

	return 0;
}
