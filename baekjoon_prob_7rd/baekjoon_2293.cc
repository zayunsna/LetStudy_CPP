#include <bits/stdc++.h>
using namespace std;

const int Inf = 1e9;
const int N = 10000;
int dp[N+4];
int n, k;
int ret;
vector<int> coin;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	for(int i = 0; i < n; ++i){
		int a;
		cin >> a;
		coin.push_back(a);
	}

	dp[0] = 1;
	for(int it : coin){
		for(int j = it; j <= k; ++j){
			dp[j] += dp[j-it];
		}
	}

	cout << dp[k] << "\n";

	return 0;
}
