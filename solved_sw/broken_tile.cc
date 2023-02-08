#include <bits/stdc++.h>
using namespace std;

const int N = 50;
int mat[N+4][N+4];
int n, m;
char a;

vector<pair<int,int>> vp;

void Init(){
	memset(mat, 0, sizeof(mat));
	vp.clear();
}

bool checkTile(){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(mat[i][j] == 1) return false;
		}
	}
	return true;
}

bool checkOkay(int y, int x){
	for(int i = y; i < y+2; ++i){
		for(int j = x; j < x+2; ++j){
			if( i < 0 || j < 0 || i >= n || j >= m) return false;
			if(mat[i][j] == 0) return false;
		}
	}
	return true;
}

void drawVis(int y, int x, int val){
	for(int i = y ; i < y+2 ; ++i){
		for(int j = x ; j < x+2; ++j){
			mat[i][j] = val;
		}
	}
}

bool solve(){
	
	for(auto it : vp){
		int y = it.first;
		int x = it.second;
		if(mat[y][x] == 0) continue;
		if(mat[y][x]){
			if(checkOkay(y,x)) drawVis(y,x, 0);
		}
	}
	
	if(checkTile()) return true;
	else return false;

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	int tc;
	cin >> tc;
	for(int ic = 1; ic <= tc; ++ic){
		Init();
		cin >> n >> m;
		for(int i = 0; i < n; ++i){
			for(int j = 0 ; j < m; ++j){
				cin >> a;
				if( a== '#') {
					mat[i][j] = 1;
					vp.push_back({i,j});
				}
			}
		}

		if(solve()) cout << "#" << ic << " YES\n";
		else cout << "#" << ic  << " NO\n";
	}

	return 0;
}
