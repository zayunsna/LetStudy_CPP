#include <bits/stdc++.h>
using namespace std;

typedef vector<pair<int,int>> vp;
int n, m;
const int N = 21;
const int Inf = 999999999;
int mat[N][N];
int temp[N][N];
int ret = Inf;

void flipC(int num){
	for(int i = 0; i < n; ++i){
		if(temp[num][i] == 1) temp[num][i] = 0;
		else temp[num][i] = 1;
	}
}

int count(int m[N][N]){
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		int m_cnt = 0;
		for(int j = 0; j < n; ++j){
			if(m[j][i] == 0) m_cnt++;
		}
		if(m_cnt > n/2) cnt += n-m_cnt;
		else cnt += m_cnt;
	}
	return cnt;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i = 0 ; i < n; ++i){
		string str;
		cin >> str;
		for(int j = 0; j < n; ++j){
			if(str[j] == 'T') mat[i][j] = 0;
			else mat[i][j] = 1;
		}
	}

	int minFlag = 0;
	for(int i = 0; i < (1<<n); ++i){
		memcpy( temp, mat, sizeof(temp));
		for(int j = 0; j <= n; ++j){
			if(i & ( 1<<j ) ){
				flipC(j);
				ret = min(ret, count(temp));
				if( ret <= 2){
					minFlag = 1;
					break;
				}
			}
		}
		if(minFlag) break;
	}
	
	cout << ret << "\n";
}






