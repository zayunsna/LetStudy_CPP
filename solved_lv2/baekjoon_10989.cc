#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
int n, a;
int mat[N+4];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	memset(mat, 0, sizeof(mat));
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> a;
		mat[a]++;
	}

	for(int i = 0; i < N; ++i){
		if(mat[i]){
			for(int j = 0; j < mat[i]; ++j){
				cout << i << "\n";
			}
		}
	}


	return 0;
}
