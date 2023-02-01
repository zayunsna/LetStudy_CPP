#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
int dp[N+4];
vector<pair<int,int>> vp;
int n, m,  m1, m2;
int b, b1, b2;
double temp;
int a;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	while(true){
		memset(dp, 0, sizeof(dp));
		vp.clear();
		scanf("%d %d.%d", &n, &m1, &m2);
		if(n == 0) break;
		m = m1*100 + m2;
		for(int i = 0; i < n; ++i){
			scanf("%d %d.%d", &a, &b1, &b2);
			b = b1*100 + b2;		
			vp.push_back({b, a});
		}
		sort(vp.begin(), vp.end());
		
		for(auto it : vp){
			int cost = it.first;
			int kcal = it.second;
			for(int i = cost; i <= m; ++i){
				dp[i] = max(dp[i-cost] + kcal, dp[i]);
			}
		}
		cout << dp[m] << "\n";
	}
	return 0;
}
