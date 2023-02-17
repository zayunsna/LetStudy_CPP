#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int Inf = 1e9;
const int N = 14;
int mat[N+4][N+4];
int n, m;

void setMat(){
	for(int i = 1; i <= N; ++i){
		mat[0][i] = i;
	}

	for(int i = 1; i <= N; ++i){
		for(int j = 1; j <= N; ++j){
			int sum = 0;
			for(int k = 1; k <= j; ++k){
				sum += mat[i-1][k];
			}
			mat[i][j] = sum;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	setMat();
/*
	for(int i = 0 ; i < N; ++i){
		for(int j = 1; j <= N; ++j){
			cout << mat[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	*/

	int tc;
	cin >> tc;
	vector<int> v;
	for(int i = 0; i < tc; ++i){
		cin >> n >> m;
		v.push_back(mat[n][m]);
		//cout << mat[n][m] << "\n";
	}

	for(int it : v) cout << it << "\n";

	return 0;


}
