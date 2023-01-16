#include <bits/stdc++.h>
using namespace std;

typedef vector<pair<int,int>> vp;
int n, m;
const int N = 10;
const int mcnt = 10;
char mat[N][N];
int dy[4] = {1, -1, 0 ,0};
int dx[4] = {0, 0, 1, -1};

int cnt = 0;
int ret = 0;

pair<int,int> posR;
pair<int,int> posB;
pair<int,int> posO;

void m_p(char z[N][N]){
	for(int i  =0 ; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cout << z[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}


pair<int,int> moveR(pair<int,int> p, int dir){

	pair<int,int> newPos;
	int ny = p.first, nx = p.second;
	int flagB = 0;
	while(1){
		ny += dy[dir];
		nx += dx[dir];
		char nw = mat[ny][nx];
		if( nw == 'B'){
			flagB = 1;
		}
		if(nw == '#' || nw == 'O'){
			if(flagB) newPos = make_pair(ny - 2*dy[dir], nx - 2*dx[dir]);
			else newPos = make_pair(ny - dy[dir], nx - dx[dir]);
			break;
		}
	}

	return newPos;
}

pair<int,int> moveB(pair<int,int> p, int dir){

	pair<int,int> newPos;
	int ny = p.first, nx = p.second;
	while(1){
		ny += dy[dir];
		nx += dx[dir];
		int py = ny - dy[dir];
		int px = nx - dx[dir];
		char nw = mat[ny][nx];
		if(nw == '#' || nw == 'O'){
			if(mat[py][px] == 'R') newPos = make_pair(ny - 2*dy[dir], nx - 2*dx[dir]);
			else newPos = make_pair(ny - dy[dir], nx - dx[dir]);
			break;
		}
	}

	return newPos;
}

void drawBall(pair<int,int> a, pair<int,int> b , char w, int flag){	
	if(flag == 0){
		mat[a.first][a.second] = w;
		mat[b.first][b.second] = '.';
	}
	else if(flag == 1){
		mat[b.first][b.second] = w;
		mat[a.first][a.second] = '.';		
	}
	
}

void run(pair<int,int> Red, pair<int,int> Blue, int c){
	if(Red == posO){
		ret = min(ret, c);
		if(Blue == posO)
			ret = -1;
		return;
	}
	if(c > mcnt) {
		ret = -1;
		exit(0);
	}

	
	int flag = 0;
	for(int i = 0; i < 4; ++i){
		
		pair<int,int> temp_R = Red;
		pair<int,int> temp_B = Blue;
		
		Red = moveR(temp_R, i);
		Blue = moveB(temp_B, i);
		
		drawBall(temp_R, Red, 'R', 1);
		drawBall(temp_B, Blue, 'B', 1);
		
		run(Red, Blue, c+1);
		
		drawBall(temp_R, Red, 'R', 0);
		drawBall(temp_B, Blue, 'B', 0);
		Red = temp_R;
		Blue = temp_B;

	}
	
		
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for(int i  =0 ; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> mat[i][j];
			if(mat[i][j] == 'R') posR = make_pair(i,j); 
			if(mat[i][j] == 'B') posB = make_pair(i,j);
			if(mat[i][j] == 'O') posO = make_pair(i,j);
		}
	}
	
	cout << posR.first << ", " << posR.second << "\n";
	run(posR, posB, 0);
	
	cout << ret << "\n";
	
}
