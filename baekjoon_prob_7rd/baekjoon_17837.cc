#include <bits/stdc++.h>
using namespace std;

const int N = 12;
int mat[N+4][N+4];
vector<int> v[N+4][N+4];
int n, k;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
struct H{
	int y; int x; int dir;
};
vector<H> mal;

void mp(int z[N+4][N+4]){
	for(int i = 0; i < n ;++i){
		for(int j = 0 ; j < n; ++j){
			cout << z[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

vector<int> pickup(int id){
	int y = mal[id].y;
	int x = mal[id].x;
	vector<int> out;
	for(int k : v[y][x]) cout << k << " ";
	cout << "\n";
	cout << "After \n";
	if(v[y][x].size() == 1) out.push_back(id);
	else{
		int idx = find(v[y][x].begin(), v[y][x].end(), id) - v[y][x].begin();
		copy(v[y][x].begin()+idx, v[y][x].end(), out.begin());
		v[y][x].erase(v[y][x].begin()+idx, v[y][x].end());
	}
	for(int k : v[y][x]) cout << k << " ";
	cout << "\n";
	return out;
}

void update(int id, int y, int x, int val){
	mal[id].y = y;
	mal[id].x = x;
	if(val){
		int _dir = mal[id].dir;
		if(_dir == 1) mal[id].dir = 2;
		else if(_dir == 2)mal[id].dir = 1;
		else if(_dir == 3)mal[id].dir = 4;
		else if(_dir == 4)mal[id].dir = 3;
	}
}

int solve(){
	int turn = 0;
	while(true){
		if(turn >= 1) break;

		for(int i = 0; i < k; ++i){
			cout << mal[i].y << "  " << mal[i].x << "  " << mal[i].dir << "\n";
			int dir = mal[i].dir-1;
			int y = mal[i].y + dy[dir];
			int x = mal[i].x + dx[dir];
			cout << "=> " << y << "  " << x << "  " << dir << "\n";
			if( y < 0 || x < 0 || x >= n || y>= n || mat[y][x] == 2){
				vector<int> _mal = pickup(i);
				for(int id : _mal) {
					update(id, y, x, 1);
					v[y][x].push_back(id);
				}
			}
			else{
				vector<int> _mal = pickup(i);
				for(int id : _mal) {
					update(id, y, x, 0);
					v[y][x].push_back(id);
				}
			}
		}

		turn++;
	}

	return (turn >= 1000) ? -1 : turn;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> mat[i][j];
		}
	}
	for(int i = 1; i <= k; ++i){
		int y, x, dir;
		cin >> y >> x >> dir;
		mal.push_back({y-1, x-1, dir});
		v[y-1][x-1].push_back(i);
	}

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			int vSize = v[i][j].size();
			if(vSize){
				cout << "(";
				for(int a : v[i][j]) cout << a << ",";
				cout << ") ";
			}
			else cout << 0 << " ";
		}
		cout << "\n";
	}

	cout << solve() << "\n";

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			int vSize = v[i][j].size();
			if(vSize){
				cout << "(";
				for(int a : v[i][j]) cout << a << ",";
				cout << ") ";
			}
			else cout << 0 << " ";
		}
		cout << "\n";
	}


	return 0;
}
