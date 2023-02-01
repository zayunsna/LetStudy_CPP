#include <bits/stdc++.h>
using namespace std;

const long long Inf = 1e18;
const int N = 100;
int arr[N+4];
int n;
long long mx = -Inf, mn = Inf;
vector<int> type;

void solve(){
	long long num = arr[0];
	int cnt = 1;
	for(auto it : type){
		if(it == 1) num += arr[cnt];
		else if(it == 2) num -= arr[cnt];
		else if(it == 3) num *= arr[cnt];
		else if(it == 4) num /= arr[cnt];
		cnt++;
	}
	mn = min(mn, num);
	mx = max(mx, num);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for(int i = 0; i < n; ++i) cin >> arr[i];

	for(int i = 1; i <= 4; ++i){
		int a;
		cin >> a;
		for(int j = 0; j < a; ++j) type.push_back(i);
	}

	for(int a : type) cout << a << " ";
	cout << "\n";

	do{
		solve();
	}while(next_permutation(type.begin(), type.end()));


	cout << mx << "\n" << mn << "\n";

	return 0;
}
