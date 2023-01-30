#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
const int N = 50;
const int Inf = 1e9;
int mat[N+4][N+4];
int temp[N+4][N+4];
int vis[N+4][N+4];
int n, m, k, r, c, s;
int ret = Inf;
int ys, xs, ye, xe;
int dir;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

struct A{
	int y, x, cnt;
};
vector<A> v;
vector<int> v_idx;
vector<pair<int,int>> vv;

void run(int y, int x, int flag){
	if(!flag && y == ys && x == xs ) dir++;
	if(!flag && y == ys && x == xe ) dir++;
	if(!flag && y == ye && x == xs ) dir++;
	if(!flag && y == ye && x == xe ) dir++;
	int ny = y + dy[dir];
	int nx = x + dx[dir];
	if(vis[ny][nx]) return;
	vis[ny][nx] = 1;
	vv.push_back({ny,nx});
	run(ny, nx, 0);
}

void rotateAll(int y, int x, int cnt){
	for(int i = 1; i <= cnt; ++i){
		ys = y - 1*i;
		xs = x - 1*i;
		ye = y + 1*i;
		xe = x + 1*i;
		vv.clear();
		dir = 0;
		memset(vis, 0, sizeof(vis));
		vis[ys][xs] = 1;
		vv.push_back({ys,xs});
		run(ys, xs, 1);
		vector<int> vvv;
		for(pair<int,int> it : vv) vvv.push_back(temp[it.first][it.second]);
		rotate(vvv.begin(), vvv.begin() + vvv.size() -1, vvv.end());
		int vvSize = vv.size();
		for(int i = 0; i < vvSize; i++) temp[vv[i].first][vv[i].second] = vvv[i];
	}
}



int solve(){
	for(auto it : v_idx) rotateAll(v[it].y, v[it].x, v[it].cnt);
	int _ret = Inf;
	for(int i = 0; i < n; ++i){
		int cnt = 0;
		for(int j = 0; j < m; ++j) cnt += temp[i][j];
		_ret = min(_ret, cnt);
	}
	return _ret;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> k;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> mat[i][j];
		}
	}
	for(int i = 0 ; i < k; ++i){
		cin >> r >> c >> s;
		v.push_back({r-1,c-1,s});
		v_idx.push_back(i);
	}
	do{
		memcpy(temp, mat, sizeof(temp));
		ret = min(ret, solve());
	}while(next_permutation(v_idx.begin(), v_idx.end()));

	cout << ret << "\n";

	return 0;
}
