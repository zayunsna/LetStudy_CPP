#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;
const int N = 104;
int mat[N][N];
int n, l;
int ret = 0;


void baekjoon_14890(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> l;
	for(int i = 0 ; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> mat[i][j];
		}
	}


	for(int i = 0; i < n; ++i){
		int cnt1 = 1;
		int j;
		for(j = 0; j < n-1; ++j){
			if(mat[i][j] == mat[i][j+1]) cnt1++;
			else if(mat[i][j]+1 == mat[i][j+1] && cnt1 >= l) cnt1 = 1;
			else if(mat[i][j]-1 == mat[i][j+1] && cnt1 >= 0) cnt1 = -l +1;
			else{break;}
		}
		if( j == n-1 && cnt1 >= 0 )ret ++;
	}
	for(int i = 0 ; i < n; ++i){
		int cnt1 = 1;
		int j;
		for(j = 0; j < n-1; ++j){
			if(mat[j][i] == mat[j+1][i]) cnt1++;
			else if(mat[j][i]+1 == mat[j+1][i] && cnt1 >= l) cnt1 = 1;
			else if(mat[j][i]-1 == mat[j+1][i] && cnt1 >= 0) cnt1 = -l +1;
			else{break;}
		}
		if( j == n-1 && cnt1 >= 0 )ret ++;
	}

	cout << ret << "\n";

}
