#include <bits/stdc++.h>
using namespace std;

const int N = 20;
const int Inf = 1e9;
const int move = 5;
int n;
int ret = 0;

struct Box{
	int mat[N+4][N+4];
	void Rotate(){
		int temp[N+4][N+4];
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				temp[i][j] = mat[n-j-1][i];
			}
		}
		memcpy(mat, temp, sizeof(mat));
	}
	void Run(){
		int temp[N+4][N+4];
		for(int i = 0; i < n; ++i){
			int point = -1;
			int flag = 0;
			for(int j = 0; j < n; ++j){
				if(mat[i][j] == 0) continue;
				if(flag && mat[i][j] == temp[i][point]) temp[i][point] *=2, flag = 0;
				else temp[i][++point] = mat[i][j], flag = 1;
			}
			for(point++; point < n; point++) temp[i][point] = 0;
		}
		memcpy(mat, temp, sizeof(mat));
	}
	void GetMax(){
		
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				ret = max(ret, mat[i][j]);
			}
		}
	}
};


void solve(Box box, int here){
	if(here == 5){
		box.GetMax();
		return;
	}
	for(int i = 0; i < 4; ++i){
		Box temp = box;
		temp.Run();
		solve(temp, here+1);
		box.Rotate();
	}
	return;
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	Box box;

	cin >> n;

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j)
			cin >> box.mat[i][j];
	}

	solve(box, 0);
	cout << ret << "\n";


	return 0;
}
