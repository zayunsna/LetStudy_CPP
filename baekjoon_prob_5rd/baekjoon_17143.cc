#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int vis[N+4][N+4];
int R, C, M;
int r, c, s, d, z;
int ret;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, 1, -1};

struct S{
	int y, x, speed, dir, size;
};

vector<S> sang;

void kill(int id){
	sang[id].y = 101;
	sang[id].x = 101;
	sang[id].speed = 0;
	sang[id].dir = 0;
	sang[id].size = 0;
	return;
}

int grap(int col){

	int mass = 0;
	for(int i = 0; i < R; ++i){
		if(vis[i][col]){
			//cout << " Grap : " << vis[i][col] << "\n";
			mass = sang[vis[i][col]].size;
			kill(vis[i][col]);
			vis[i][col] = 0;
			break;
		}
	}
	return mass;
}

void mp(int z[N+4][N+4]){
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			cout << vis[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void update(int id, int y, int x, int dir){
	sang[id].y = y;
	sang[id].x = x;
	sang[id].dir = dir;
}

void move(){

	int temp[N+4][N+4];
	memset(temp,0, sizeof(temp));
	for(int i = 1; i <= M; ++i){
		S _this = sang[i];
		int y = _this.y;
		int x = _this.x;
		int speed = _this.speed;
		int dir = _this.dir;
		int size = _this.size;
		//cout << i << "  " << y << "  " << x << "  " << speed << "  " << dir << "  " << size << "\n";
		//if(speed == 0) continue;
		if(dir == 1){
			y -= speed;
			if( y < 0){
				int mo = 1-y/(R-1);
				int ja = abs(y%(R-1));
				if( mo % 2 == 0){y = R-1-ja;}
				else{
					y = ja;
					dir = 2;
				}
			}
		}
		else if(dir == 2){
			y += speed;
			if( y >= R){
				int mo = y/(R-1);
				int ja = y%(R-1);
				if(mo % 2 == 0){y = ja;}
				else{
					y = R-1-ja;
					dir = 1;
				}
			}

		}
		else if(dir == 3){
			x += speed;
			if( x >= C){
				int mo = x/(C-1);
				int ja = x%(C-1);
				if(mo%2==0) {x = ja;}
				else{
					x = C-1-ja;
					dir = 4;
				}
			}
		}
		else if(dir == 4){
			x -= speed;
			if( x < 0){
				int mo = 1-y/(C-1);
				int ja = abs(x%(C-1));
				if(mo%2 == 0) { x = C-1-ja;}
				else{
					x = ja;
					dir = 3;
				}
			}
		}
		//else continue;

		if(temp[y][x]){
			if(size > sang[temp[y][x]].size){
				kill(temp[y][x]);
				temp[y][x] = i;
			}
			else{
				kill(i);
			}
		}
		else{
			temp[y][x] = i;
		}
		//temp[_this.y][_this.x] = 0;
		//cout << "=> " << y << "  " << x << "  " << speed << "  " << dir << "  " << size << "\n";
		update(i, y, x, dir);

	}
	memcpy(vis,temp,sizeof(vis));
	//cout << "\n";
	return ;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C >> M;
	if(M == 0){
		cout << 0 << "\n";
		return 0;
	}
	sang.push_back({101,101,0,0,0});
	for(int i = 1; i <= M; ++i){
		cin >> r >> c >> s >> d >> z;
		sang.push_back({r-1,c-1,s,d,z});
		vis[r-1][c-1] = i;
	}
/*
	for(int i = 1; i <= M; ++i){
		cout << i << " : " << sang[i].y << "  " << sang[i].x << "  " << sang[i].speed << "  " << sang[i].dir << "  " << sang[i].size  << "\n";
	}
	mp(vis);
*/
	for(int i = 0 ; i < C; ++i){
		//cout << " Turn : " << i << "\n";
		ret += grap(i);
		//cout << " Ret : " << ret << "\n";
		move();
		//mp(vis);

	}

	cout << ret << "\n";


	return 0;
}
