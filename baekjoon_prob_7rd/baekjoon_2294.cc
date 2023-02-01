#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
const int Inf = 1e9;
int dp[N+4];
int n, k, a;
vector<int> coin;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	for(int i = 0; i < n; ++i){
		cin >> a;
		coin.push_back(a);
	}
	//sort(coin.begin(), coin.end(), greater<int>());

	fill(dp, dp+N+4, Inf);
	dp[0] = 0;
	for(int it : coin){
		for(int j = it; j <= k; ++j){
			dp[j] = min( dp[j-it]+1, dp[j]);
		}
	}

	int ret = dp[k];
	cout << ((ret >= Inf) ? -1 : ret) << "\n";


	return 0;
}
