#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;
int n, L, H;
int mat[54][54];
int vis[54][54];

int dy[4] = {1, 0, -1 ,0};
int dx[4] = {0, 1, 0, -1};

int ret = 0;

void m_p(int z[54][54]){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cout << z[i][j] << "  ";
		}
		cout << "\n";
	}
}

bool check(int a, int b){
	if( L <= abs(a-b) && abs(a-b) <= H) return true;
	else return false;
}

void bfs(int y, int x){
	queue<pair<int,int>> q;
	q.push({y,x});
	vis[y][x] = 1;

	int sum = mat[y][x];
	int count = 1;
	while(q.size()){
		auto it = q.front(); q.pop();
		for(int i = 0; i < 4; ++i){
			int ny = it.first + dy[i];
			int nx = it.second + dx[i];
			if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if( vis[ny][nx] || !check(mat[it.first][it.second],mat[ny][nx])) continue;
			vis[ny][nx] = 1;
			sum += mat[ny][nx];
			count ++;
			q.push({ny,nx});
		}
	}
	if(count == 1) vis[y][x] = 0;
	else{
		int newCont = floor(sum/count);
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				if(vis[i][j] == 1) {
					mat[i][j] = newCont;
					vis[i][j] = 2;
				}
			}
		}
		/*
		cout << " vis map\n";
		m_p(vis);
		cout << " true map\n";
		m_p(mat);
		cout << "======\n";
		*/
	}
}

bool visCheck(){
	int comp[54][54];
	fill(&comp[0][0], &comp[0][0]+54*54, 0);

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(comp[i][j] != vis[i][j]) return false;
		}
	}
	return true;
}

void run(){
	while(true){
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				if(!vis[i][j]) bfs(i,j);
			}
		}

		if(visCheck()){break;}
		else{
			ret++;
			cout << " vis map init! \n";
			fill(&vis[0][0], &vis[0][0]+54*54, 0);
		}
	}
}

void baekjoon_16234(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> L >> H;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> mat[i][j];
		}
	}

	run();

	cout << ret << "\n";

}
