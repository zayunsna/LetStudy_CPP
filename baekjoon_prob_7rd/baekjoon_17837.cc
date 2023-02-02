#include <bits/stdc++.h>
using namespace std;

const int N = 12;
int mat[N+4][N+4];
vector<int> v[N+4][N+4];
int n, k;
int dy[5] = {0, 0, 0, -1, 1};
int dx[5] = {0, 1, -1, 0, 0};
struct H{
	int y; int x; int dir;
};
vector<H> mal;

int changeDir(int dir){
	if(dir == 1) return 2;
	if(dir == 2) return 1;
	if(dir == 3) return 4;
	if(dir == 4) return 3;
}

void Update(int y, int x, int dir, int id){
	int ny = y + dy[dir];
	int nx = x + dx[dir];
	if(ny < 0 || nx < 0 || ny >= n || nx >= n || mat[ny][nx] == 2){
		mal[id].dir = changeDir(mal[id].dir);
		ny = y + dy[mal[id].dir];
		nx = x + dx[mal[id].dir];
		if(ny < 0 || nx < 0 || ny >= n || nx >= n || mat[ny][nx] == 2) return;
	}
	// 현재 있는 곳의 배열 참조 복사 
	vector<int> &vec = v[y][x];
	// 이제 갈 곳의 배열 참조 복사 
	vector<int> &next_vec = v[ny][nx];
	// 현재 배열속 현재 말의 idx 찾기 
	auto now = find(vec.begin(), vec.end(), id);
	// 만약 갈 곳이 빨강블럭이면  현재 배열속 현재 말의 idx부터 끝까지 뒤집음.
	// 그 말 위에 있는 말까지 한번에 가야하고 뒤집힌 상태에서 가야 하기 때문. 
	if(mat[ny][nx] == 1) reverse(now, vec.end());
	// 현재 배열의 현재말 idx부터 한개씩 갈 곳의 배열로 push_back; 
	for( auto it = now; it != vec.end(); it++){
		mal[*it].y = ny;
		mal[*it].x = nx;
		next_vec.push_back(*it);
	}
	// 현재 배열안에 이동한 말의 id를 제거. 
	vec.erase(now, vec.end());
	return;
}

bool check(){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(v[i][j].size() >= 4) return true;
		}
	}
	return false;
}

bool Run(){
	for(int i = 0; i < mal.size(); ++i){
		int y = mal[i].y;
		int x = mal[i].x;
		int dir = mal[i].dir;
		
		//cout << " ID : " << i << " " << y << " " << x << " " << dir << "\n";
		Update(y, x, dir, i);
		/*
		for(int j = 0; j < n; ++j){
			for(int k = 0; k < n; ++k){
				
				if(v[j][k].size()){
					cout << "(";
					for(auto it : v[j][k]) cout << it << " ";
					cout << ") ";
				}
				else cout << 0 << " ";
			}
			cout << "\n";
		}
		cout << "\n";
		*/
		if(check()) return true;
	}
	return false;
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
	for(int i = 0; i < k; ++i){
		int y, x, dir;
		cin >> y >> x >> dir; 
		y--; 
		x--;
		mal.push_back({y, x, dir});
		v[y][x].push_back(i);
	}

	int cnt = 0;
	bool flag = false;
	while( cnt <= 1000){
		cnt++;
		if(Run()){
			flag = true;
			break;
		}
	}
	if(flag) cout << cnt << "\n";
	else cout << -1 << "\n";
	return 0;
}
