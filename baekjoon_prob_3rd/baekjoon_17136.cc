#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
#include <ios>
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
		//cout << " x == n " << "\n";
		dfs(y+1, 0, cnt);
		return;
	}
	if( y == n ){
		ret = min(ret, cnt);
		//cout << " End line!  y == n " << y << " ; " << x << "  " << cnt << "\n";
		return;
	}
	if(mat[y][x] == 0){
		//cout << " contant is 0 || " << y << " : " << x << "\n";
		dfs(y, x+1, cnt);
		return;
	}
	//cout << " content is 1 || " << y << " : " << x << "\n";
	for(int gap = 5; gap >= 1; --gap){
		//cout << " size selection : " << gap << "  " << mp[gap] << "\n";
		if(mp[gap] == 5) continue;
		if( check(y, x, gap)){
			//cout << " size : " << gap << " is okay for this .\n";
			mp[gap]++;
			//cout << " Draw section \n";
			draw(y, x, gap, 0);
			//cout << cnt+1 << "th Search continue \n";
			dfs(y, x+gap, cnt+1);
			//cout << cnt+1 << "th Remove drawing \n";
			draw(y, x, gap, 1);
			//cout << " Fill off the paper \n";
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
