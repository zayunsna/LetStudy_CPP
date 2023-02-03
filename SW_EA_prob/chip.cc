#include <bits/stdc++.h>
using namespace std;

const int H = 15;
const int W = 25;
int mat[H][W];
int vis[H][W];
int dp[1<<H][W];
int T, n, h , w;
int ret = 0;

void draw(int y, int x, int c){
	for(int i = y; i < y+2; ++i)
		for(int j = x; j < x+2; ++j) mat[i][j] = c;
}

bool check(int y, int x){
	if(y+2 > h || x+2 > w) return false;
	for(int i = y; i < y+2; ++i)
		for(int j = x; j < x+2; ++j) 
			if( mat[i][j] == 1) return false;
	return true;
}

void m_p(int z[H][W]){
	for(int i = 0; i < h; ++i){
		for(int j = 0; j < w; ++j)
			cout << z[i][j] << " ";
		cout << "\n";
	}
	return;
}

void run(int y, int x, int cnt){

	if(y >= h-1){
		y = 0;
		x++;
	}
	if( x == w){
		//ret = max(ret, cnt);
		if(ret < cnt) ret = cnt;
		return;
	}
	if(y == 0){
		int b = 0;
		for(int i = 0; i < h; ++i){
			b |= (mat[i][x] << i);
		}
		int &ddp = dp[b][x];
		cout << y << ", " << x << " : " << bitset<16>(b) << "  " << ddp << "  " << cnt << "\n";
		if( ddp >= cnt) return;
		ddp = cnt;
	}

	if(check(y,x)){
		draw(y,x,1);
		run(y+2, x, cnt+1);
		draw(y,x,0);
	}
	run(y+1, x, cnt);

}

void init(){
	memset(dp, -1, sizeof(dp));
	memset(vis, 0, sizeof(vis));
	memset(mat, 0, sizeof(mat));
	ret = 0;
}


int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	for(int tc = 1; tc <= T; ++tc){
		init();

		cin >> h >> w;
		for(int i = 0 ; i < h; ++i){
			for(int j = 0 ; j < w; ++j){
				cin >> mat[i][j];
			}
		}

		run(0,0,0);

		cout << "#"<< tc << " " << ret << "\n";
	}

	return 0;

}
