#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

int n, m;
const int N = 24;
char mat[N][N];

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
int ret = 0;

void run(int y, int x, int num, int cnt){
	ret = max(ret, cnt);
	for(int i =0 ; i < 4; ++i){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		int next = (1 << (int)(mat[ny][nx] - 'A'));
		if((num & next) == 0) run(ny, nx, num | next, cnt+1);
	}
	return;
}

void baekjoon_1987_ver2(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for(int i =0 ; i < n; ++ i){
		for(int j = 0; j < m; ++j){
			cin >> mat[i][j];
		}
	}
	
	run(0, 0,  1 << (int)(mat[0][0]-'A'), 1);

	cout << ret << "\n";

}
