#include <bits/stdc++.h>
using namespace std;

long long  n;

 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;

	long long ret = 1;
	for(int i = 1; i <= n; ++i){
		ret *= i;
	}
	cout << ret << "\n";

	return 0;
}
