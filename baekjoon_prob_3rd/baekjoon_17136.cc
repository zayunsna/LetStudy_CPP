#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

int n = 10;
int mat[14][14];
int vis[14][14];

int Inf = 999999999;
int ret = Inf;
map<int,int> mp;

void m_p(int m[14][14]){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cout << m[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
bool check(int y, int x, int gap){
	if(y+gap > n || x+ gap > n) return false;
	for(int i = y; i < y+gap; ++i){
		for(int j = x; j < x+gap; ++j){
			if(mat[i][j] == 0) return false;
		}
	}
	return true;
}

void draw(int y, int x, int gap, int value){
	for(int i = y; i < y+gap; ++i){
		for(int j = x; j < x+gap; ++j){
			mat[i][j] = value;
		}
	}
}

void dfs(int y, int x, int cnt){
	if( cnt >= ret ) return;
	if( x == n){
		dfs(y+1, 0, cnt);
		return;
	}
	if( y == n ){
		ret = min(ret, cnt);
		return;
	}
	if(mat[y][x] == 0){
		dfs(y, x+1, cnt);
		return;
	}
	for(int gap = 5; gap >= 1; --gap){
		if(mp[gap] == 5) continue;
		if( check(y, x, gap)){
			mp[gap]++;
			draw(y, x, gap, 0);
			dfs(y, x+gap, cnt+1);
			draw(y, x, gap, 1);
			mp[gap]--;
		}
	}
	return;
}





void baekjoon_17136(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> mat[i][j];
		}
	}

	dfs(0, 0, 0);

	int min = (ret == Inf) ? -1 : ret;

	cout << min << "\n";

}
