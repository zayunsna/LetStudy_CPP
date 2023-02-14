#include <bits/stdc++.h>
using namespace std;

int n, m;

int fact(int a){
	int out = 1;
	for(int i = 1; i <= a; ++i ){
		out *= i;
	}
	return out;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	cout << fact(n)/ ( fact(m) * fact(n-m)) << "\n";

	return 0;
}
