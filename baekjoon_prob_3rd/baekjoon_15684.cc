#include <bits/stdc++.h>
using namespace std;

typedef vector<pair<int,int>> vp;
const int N = 10;
const int H = 30;
const int Inf = 1e9;
int lad[H+4][H+4];
int ret = Inf;
int n,m,h;
bool IsOkay(){
	for(int i = 1; i <= n; ++i){
		int start = i;
		for(int j = 1; j <= h; ++j){
			if(lad[j][start]) start++;
			else if(lad[j][start-1]) start--;
		}
		if(start != i) return false;
	}
	return true;
}

void solve(int start, int turn){
	if(turn > 3 || turn >= ret) return;
	if(IsOkay()){
		ret = min(ret, turn);
		return;
	}
	
	for(int i = start; i <= h; ++i){
		for(int j = 1; j <= n; ++j){
			if(lad[i][j] || lad[i][j-1] || lad[i][j+1]) continue;
			lad[i][j] = 1;
			solve(i, turn+1);
			lad[i][j] = 0;
		}
		
	}
	
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m >> h;
	if(m == 0) {
		cout << "0\n"; 
		return 0;
	}
	for(int i = 0; i < m; ++i){
		int a, b;
		cin >> a >> b;
		lad[a][b] = 1;
	}
	
	solve(1, 0);
	int out = (ret == Inf) ? -1 : ret;
	cout << out << "\n";
	return 0;
}
