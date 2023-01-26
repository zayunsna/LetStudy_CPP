#include <bits/stdc++.h>
using namespace std;

const int N = 300;
int mat[N+4][N+4];
int vis[N+4][N+4];
int n , m;
pair<int,int> ju;
pair<int,int> cho;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int ret;

void m_p(int z[N+4][N+4]){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cout << z[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

bool bfs(int y, int x){

	queue<pair<int,int>> q;
	vis[y][x] = 1;
	q.push({y,x});

	int flag = 0;
	while(q.size()){
		auto it = q.front(); q.pop();
		for(int i = 0; i < 4; ++i){
			int ny = it.first + dy[i];
			int nx = it.second + dx[i];
			if(ny < 0 || nx < 0 || ny >= n || nx >= m || vis[ny][nx]) continue;
			if(mat[ny][nx] == 0) {
				vis[ny][nx] = 1;
				q.push({ny, nx});
			}
			else if( mat[ny][nx] == 1){
				vis[ny][nx] = 1;
				mat[ny][nx] = 0;
			}
			else if(mat[ny][nx] == 8){
				flag = 1;
				break;
			}
		}
		if(flag) break;
	}
	if(flag) return true;
	return false;
}

void solve(){
	while(true){
		memset(vis,0, sizeof(vis));
	//	cout << " Matrix \n";
	//	m_p(mat);
		bool cond = bfs(ju.first, ju.second);
	//	cout << " visited \n";
	//	m_p(vis);
	//	cout << " After Matrix \n";
	//	m_p(mat);
		ret++;
		if(cond) break;
	}
	cout << ret << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	ju = make_pair(a-1,b-1);
	cho = make_pair(c-1,d-1);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			char c;
			cin >> c;
			if(c == '*') mat[i][j] = 9;
			else if(c == '#') mat[i][j] = 8;
			else mat[i][j] = (int)c-'0';
		}
	}

	solve();
	return 0;

}
