#include <bits/stdc++.h>
using namespace std;

const int N = 1e7;
const int Inf = 1e9;
int dp[N+4];
int n;

void solve(int n){

	if(n == 0) return;
	cout << n << " ";
	if(!(n%3) && dp[n] == dp[n/3]+1) solve(n/3);
	else if(!(n%2) && dp[n] == dp[n/2]+1) solve(n/2);
	else if(n-1 >= 0 && dp[n] == dp[n-1]+1) solve(n-1);
	return;


}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	fill(dp, dp+N+4, Inf);
	cin >> n;
	dp[1] = 0;
	for(int i = 1; i <= n; ++i){
		if(!(i%3)) dp[i] = min(dp[i/3] + 1, dp[i]);
		if(!(i%2)) dp[i] = min(dp[i/2] + 1, dp[i]);
		dp[i] = min(dp[i-1]+1, dp[i]);
	}

	cout << dp[n] << "\n";

	solve(n);
	cout << "\n";


	return 0;
}
