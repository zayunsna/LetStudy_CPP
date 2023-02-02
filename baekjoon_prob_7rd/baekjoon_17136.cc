#include <bits/stdc++.h>
using namespace std;

const int Inf = 1e9;
const int N = 10;
int mat[N+4][N+4];
int ret = Inf;
int paper[6];

void mp( int  z[N+4][N+4]){
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			cout << z[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

bool check(int y, int x, int size){
	if( y +size > N || x+size > N) return false;
	for(int i = y; i < y+size; ++i){
		for(int j = x; j < x+size; ++j){
			if(!mat[i][j]) return false;
		}
	}
	return true;
}

void draw(int y, int x, int size, int val){
	for(int i = y; i < y+size; ++i){
		for(int j = x; j < x+size; ++j){
			mat[i][j] = val;
		}
	}
}


void solve(int y, int x, int turn){
	if( ret <= turn) return;
	if( x == N ){
		solve(y+1,0, turn);
	}
	if( y == N){
		ret = min(ret, turn);
		return;
	}
	if(!mat[y][x]){
		solve(y, x+1, turn);
		return;
	}

	for(int k = 5; k >= 1; --k){
		if(paper[k] >= 5) continue;
		if(check(y,x,k)){
			paper[k]++;
			draw(y,x,k,0);
			solve(y,x+k,turn+1);
			draw(y,x,k,1);
			paper[k]--;
		}
	}

	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			cin >> mat[i][j];
		}
	}

	solve(0,0,0);

	cout << (ret == Inf ? -1 : ret) << "\n";

	return 0;
}
