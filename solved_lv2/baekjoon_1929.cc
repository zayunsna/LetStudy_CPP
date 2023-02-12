#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int Inf = 1e9;
int n, m;

bool check(int n){
	if( n <= 1 ) return false;
	if( n == 2 ) return true;
	if( n%2 == 0) return false;
	for(int i = 2; i*i <= n; i++)
		if(n%i == 0) return false; 
	
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for(int i = n; i <= m; ++i){
		if(check(i)) cout << i << "\n";
	}	
	
	return 0;
}
