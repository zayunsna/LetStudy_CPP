#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

int n, m;
char mat[54][54];
int vis[54][54];
vector<int> ret;
typedef vector<pair<int,int>> vp;

vp p;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

const int Inf = 999999999;
int minVal;

bool check(pair<int,int> a, pair<int,int>b){
	int d = abs(a.first - b.first) + abs(a.second - b.second);
	if(d != 1) return true;
	else return false;
}

int dfs(int y, int x, pair<int,int> e){
	if( y == e.first && x == e.second){
		//cout << " # cnt : " << vis[y][x]-1 << ". Searching end \n";
		return vis[y][x]-1;
	}
	for(int i = 0; i < 4; ++i){
		int ny = y + dy[i];
		int nx = x + dx[i];
		int next = mat[ny][nx];
		//cout << " == > Go Next " << ny << " : " << nx << " = " << (char)next << "\n";
		if(ny < 0 || nx < 0 || ny >= n || nx >= m || vis[ny][nx] || next == 'W') continue;
		vis[ny][nx] = vis[y][x] +1;
		//cout << " === > Do next dfs \n";
		minVal = min(dfs(ny,nx,e), minVal);
		vis[ny][nx] = 0;

	}
	return minVal;

}
int mx = 0;

void run(int cnt, vp temp){
	if(temp.size() == 2){
		fill(&vis[0][0], &vis[0][0]+54*54, 0);
		auto it = temp[0];
		//cout << " Start point : " << it.first << " : " << it.second << "\n";
		minVal = Inf;
		vis[it.first][it.second] =1;
		int dist = 0;
		if(check(it, temp[1])) dist = dfs(it.first, it.second, temp[1]);
		else dist = 1;

		if( dist != Inf) ret.push_back(dist);
		return;

	}
	for(int i = cnt+1; i < p.size(); ++i){
		temp.push_back(p[i]);
		run(i, temp);
		temp.pop_back();
	}

	return;
}

void baekjoon_2589(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> mat[i][j];
			if(mat[i][j] == 'L') p.push_back({i,j});
		}
	}

	vp temp;
	run(-1, temp);



	cout << *max_element(ret.begin(),ret.end()) << "\n";

}
