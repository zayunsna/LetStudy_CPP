#include <bits/stdc++.h>
using namespace std;

double a, b;
int turn = 90/5;
const int N = 20;
double dp[N][N][N];
int sosu[N];

double solve(int A, int B, int idx){
	if(idx == turn) return sosu[A] || sosu[B] ? 1.0 : 0.0;
	double &out = dp[A][B][idx];
	if(out > -0.5) return out;
	out = 0.0;
	out += solve(A+1, B, idx+1) * a * (1-b);
	out += solve(A+1, B+1, idx+1) * a * b;
	out += solve(A, B+1, idx+1) * (1-a) * b;
	out += solve(A, B, idx+1) * (1-a) * (1-b);
	return out;
}

void GetList(){
	fill(sosu, sosu+N, 1);
	sosu[0] = 0;
	sosu[1] = 0;
	for(int i = 2; i <= N; ++i){
		for(int j = i + i; j <= N; j+=i){
			sosu[j] = 0;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> a >> b;
	a /= 100;
	b /= 100;
	GetList();
	memset(dp, -1, sizeof(dp));
	cout << setprecision(6);
	cout << solve(0,0,0) << "\n";
	//printf("%0.6lf", solve(0,0,0));
	return 0;
	
}
