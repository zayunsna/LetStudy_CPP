#include <bits/stdc++.h>
using namespace std;

const int N = 50;
int mat[N+4][N+4];

int n, m;
char a;
bool ret = false;

void Init(){
	memset(mat, 0, sizeof(mat));
	ret = false;
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

void mp(int z[N+4][N+4]){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m ; ++j){
			cout << z[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void solve(int y, int x){
	if(x >= m-1){
		x = 0;
		y++;
	}
	if( y == n-1 ){
		ret = checkTile();
		return;
	}

	if(ret) return;
	if(checkOkay(y, x)){
		drawVis(y, x, 0);
		
		solve(y,x+2);
		drawVis(y,x,1);

	}
	solve(y,x+1);

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
				if( a== '#') mat[i][j] = 1;
			}
		}

		solve(0,0);

		if(ret) cout << "#" << ic << " YES\n";
		else cout << "#" << ic  << " NO\n";
	}

	return 0;
}
