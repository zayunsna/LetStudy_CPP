#include "/home/icegpu/HK/HKTool.h"
#include <ios>
using namespace std;

int mat[104][104];
int vis[104][104];

int n, m, k, ny, nx;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int cnt = 0;
vector<int> c_size;

void bfs(int y, int x, int n, int m){
	queue<pair<int,int>> q;
	q.push(make_pair(y,x));
	vis[y][x] = 1;

	int m_cnt = 0;
	while(q.size()){
		auto it = q.front(); q.pop();
		for(int i = 0; i < 4; ++i){
			ny = it.first + dy[i];
			nx = it.second + dx[i];
			if( ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if(mat[ny][nx] == 1 && !vis[ny][nx]){
				q.push(make_pair(ny,nx));
				vis[ny][nx] = 1;
				m_cnt++;
			}
		}
	}
	cnt++;
	c_size.push_back(m_cnt);
}

void baekjoon_2583(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> k;
	fill(&mat[0][0], &mat[0][0]+104*104, 1);
	fill(&vis[0][0], &vis[0][0]+104*104, 0);

	for(int nk = 0; nk < k; ++nk){
		int t[4];
		for(int i = 0; i < 4; ++i) cin >> t[i];

		for(int i =0 ; i < n; ++i){
			for(int j = 0; j < m; ++j){
				if( j >= t[0] && j < t[2]){
					if( i >= t[1] && i < t[3]){
						mat[i][j] = 0;
					}
				}
			}
		}
	}

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){

			if(mat[i][j] == 1 && !vis[i][j]) {
				bfs(i,j, n, m);
			}
		}
	}


	cout << cnt << "\n";
	sort(c_size.begin(), c_size.end());
	for(auto it : c_size) cout << it+1 << " ";
	cout << "\n";

}
