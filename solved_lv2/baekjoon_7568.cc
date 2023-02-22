#include <bits/stdc++.h>
using namespace std;

const int N = 50;
int mat[N+4][2];
int n, rk;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> mat[i][0] >> mat[i][1];
	}
	for(int i = 0; i < n; ++i){
		rk = 1;
		for(int j = 0; j < n; ++j){
			if(mat[i][0] < mat[j][0] && mat[i][1] < mat[j][1])rk ++;
		}

		cout << rk << " ";
	}
	cout << "\n";

	return 0;
}
