#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int Inf = 1e9;
int n, m;

pair<int, int> dp[42];
bool visited[42];

pair<int,int> solve(int n){
	if (visited[n]) return dp[n];

	visited[n] = true;

	if(n == 0) dp[n] = {1, 0};
	else if(n == 1) dp[n] = {0, 1};
	else {
		auto a = solve(n-1);
		auto b = solve(n-2);
		return {a.first + b.first, a.second + b.second};
	}

	return dp[n];	
}

int fibonacci(int n) {
    if (n == 0) {
        printf("0");
        return 0;
    } else if (n == 1) {
        printf("1");
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	while(n--){
		cin >> m;
		auto result = solve(m);
		cout << result.first << " " << result.second << endl;
	}
	return 0;
}
