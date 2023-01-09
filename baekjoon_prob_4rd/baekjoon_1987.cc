#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 24;
char mat[N][N];
int vis[N][N];
vector<char> word;

int n ,m;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int ret = 0;

void m_p(int v[N][N]){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cout << vis[i][j] << " ";
		}
		cout << "\n";
	}
}

void dfs(int y, int x){
	if(vis[y+1][x] && vis[y][x+1] && vis[y-1][x] && vis[y][x-1]){
		cout << " Searching End \n";
		return;
	}
	//cout << mat[y][x] << "\n";
	vis[y][x] = 1;
	for(int i = 0; i < 4; ++i){
		int ny = y + dy[i];
		int nx = x + dx[i];
		//cout << " ==> " << ny << " : " << nx  << " New word : " << mat[ny][nx] << " " << vis[ny][nx] << " " << word.size() << "\n";
		//m_p(vis);
		if(ny < 0 || nx < 0 || ny >= n || nx >= m || vis[ny][nx]) continue;
		//cout << "pass 1\n";
		if(!vis[ny][nx]){
			char nw = mat[ny][nx];
			//cout << " Double check : " << nw << "\n";
			if(find(word.begin(), word.end(), nw) == word.end()){
				//cout << " No new word found \n";
				vis[ny][nx] = 1;
				word.push_back(nw);
				if( ret <= word.size()) ret = word.size();
				/*
				cout << " Max comparing : " << ret << "\n";
				for(auto it : word) cout << it << " ";
				cout << "\n";
				*/
				dfs(ny,nx);
				vis[ny][nx] = 0;
				word.pop_back();
				/*
				cout << " pop Back : ";
				for(auto it : word) cout << it << " ";
				cout << "\n";
				*/
			}
			else{
				///cout << " this already visited \n";
				continue;
			}
		}
	}
	return;
	
}


void baekjoon_1987(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> mat[i][j];
		}
	}
/*
	for(int i = 0; i < n; ++i){
		cout << i << " : ";
		for(int j = 0; j < m; ++j){
			cout << mat[i][j] << " ";
		}
		cout << "\n";
	}
*/
	word.push_back(mat[0][0]);
	dfs(0,0);

	cout << ret << "\n";

}
