#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int L[N+4], J[N+4], dp[N+4];
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> L[i];
	for(int i = 0; i < n; ++i) cin >> J[i];
	
	for(int i = 0; i < n; ++i){
		int _L = L[i];
		int _J = J[i];
		for(int j = 100; j > _L; --j){
			dp[j] = max(dp[j-_L]+_J, dp[j]);
		}
	}
	
	cout << dp[100] << "\n";
	
}
