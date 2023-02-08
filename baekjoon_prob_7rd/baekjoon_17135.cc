#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

const int N = 15;

int mat[N+4][N+4];
int vis[N+4][N+4];
int n, m, d;

void combi(int start, vector<int> temp){
	if(temp.size() == 3){
		for(int i : temp) cout << i << " ";
		cout << "\n";
		return;
	}

	for(int i = start+1; i < 4; ++i){
		temp.push_back(i);
		combi(i, temp);
		temp.pop_back();
	}
	return;
}

bool check(){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(mat[i][j]) return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> d;
	for(int i = 0 ; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> mat[i][j];
		}
	}


	return 0;
}
