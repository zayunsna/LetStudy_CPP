#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int mat[N+4][N+4];
int vis[N+4][N+4];
int n, k, l;

void m_p(int z[N+4][N+4]){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cout << z[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	memset(mat, 0, sizeof(mat));
	cin >> k;
	for(int i = 0; i < k; ++i){
		int a, b;
		cin >> a >> b;
		mat[a-1][b-1] = 1;
	}
	//m_p(mat);
	cin >> l;
	vector<pair<int,char>> q_l;
	for(int i = 0; i < l; ++i){
		int a; char b;
		cin >> a >> b;
		q_l.push_back({a,b});
	}

	//for(auto it : q_l) cout << it.first << "  " << it.second << "\n";

	int t = 0;
	int dt = 0;
	queue<pair<int,int>> q;
	int y = 0, x = 0;
	int dy = 0, dx = 1;
	vis[y][x] = 1;
	q.push({y,x});
	while(true){
		auto dir = q_l[dt]; 
		//cout << t << "  " << dir.first << "  " << dir.second << "\n";
		if(t == dir.first){
			//cout << " Time : " << t << " [ " << dir.second << " ] \n";
			if( dir.second == 'L'){
				//cout << " Turn Left ! \n"; 
				if(dy == 0 && dx == 1) dy = -1, dx = 0;
				else if(dy == 0 && dx == -1) dy = 1, dx = 0; 
				else if(dy == 1 && dx == 0) dy = 0,dx = 1;
				else if(dy == -1 && dx == 0) dy = 0, dx = -1;
			}
			if(dir.second == 'D'){
				//cout << " Turn Right ! \n";
				if(dy == 0 && dx == 1) dy = 1, dx = 0;
				else if(dy == 0 && dx == -1) dy = -1, dx = 0; 
				else if(dy == 1 && dx == 0) dy = 0,dx = -1;
				else if(dy == -1 && dx == 0) dy = 0, dx = 1;
			}
			dt++;
		}
		y += dy;
		x += dx;
		//cout << " Next << " << y << "  " << x << " \n";
		if(y < 0 || x < 0 || y >= n || x >= n){ 
			//cout << " Hit the wall \n";
			break;
		}
		if(vis[y][x]) {
			//cout << " Hit a body \n";
			break;
		}
		if(mat[y][x] == 1){
			q.push({y,x});
			vis[y][x] = 1;
			mat[y][x] = 0;
		}
		else if(mat[y][x] == 0){
			q.push({y,x});
			auto it = q.front(); q.pop();
			vis[y][x] = 1;
			vis[it.first][it.second] = 0;
		}
		t++;
	}

	//m_p(vis);
	cout << t+1 << "\n";
	return 0;
}
