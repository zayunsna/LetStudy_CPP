#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int tc;
	cin >> tc;
	for(int ic = 1; ic <= tc; ++ic){
		cin >> n >> m;
		if( n <= m ){
			if(n == 1) cout  << "#" << ic << " " << n << "\n";
			else{
				cout << "#" << ic << " " << n*2 << "\n";
			}
		}
		else if( m == 0){
			cout << "#" << ic << " " << n << "\n";
		}
		else if( m == 1){
			if( n == 2) cout << "#" << ic << " " << n*2 << "\n";
			else cout << "#" << ic << " " << n+1 << "\n";
		}
		else{
			cout << "#" << ic << " " << n << "\n";
		}
	}

/*	
	cin >> n >> m;
	ll t = n + m;
	t -= 1;
	ll bg = (1 << t);
	ll mx = bg, mn= bg;

	for(int i = t-1; i > m-1; --i){
		mx |= (1 << i);
	}

	for(int i = 0; i < n-1; ++i){
		mn |= ( 1 << i);
	}

	const int nbit = 64;
	cout << bitset<nbit>(mx) << " " << mx << "\n";
	cout << bitset<nbit>(mn) << " " << mn << "\n"; 

	ll multi = mx*mn;
	cout << bitset<nbit>(multi) << " " << multi << "\n";
	cout << __builtin_popcount(multi) << "\n";
*/
	return 0;
}
