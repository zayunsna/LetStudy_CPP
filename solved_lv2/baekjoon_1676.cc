#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int Inf = 1e9;

int anw(int N){
	int cnt = 0;
	for (int i = 5; i <= N; i *=5) cnt += N/ i;
	return cnt;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n=0;
	cin >> n;
	cout << anw(n) << endl;
}
