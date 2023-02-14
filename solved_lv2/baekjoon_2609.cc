#include <bits/stdc++.h>
using namespace std;

int n, m;

int gcd(int a, int b){
	if(a== 0) return b;
	return gcd(b%a,a);
}

int lcm(int a, int b){
	return (a*b)/gcd(a,b);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	cout << gcd(n,m) << "\n" << lcm(n,m) << "\n";

	return 0;
}
