#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, k, ret, remain;
set<pair<ll,ll>>::iterator planet;
set<pair<ll,ll>> s;

void Init(){
	s.clear();
	ret = 0;
	remain = 0;
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	Init();
	cin >> n >> k;
	for(int i = 0; i < n; ++i){
		ll a;
		cin >> a;
		s.insert({a, i});
		remain += a;
	}

	cout << " Initial Status : " << remain << "\n";
	for(auto it : s){
		ll A, B;
		tie(A,B) = it;
		cout << A << "  " << B << "\n";
	} 
	cout << "\n";
	while(true){
		if( k >= remain )break;
		cout << "Upper bound " << k << "  " << n << "\n";
		planet = s.upper_bound({k,n});
		cout << " => " << ret << "  " << remain << "  " << (*planet).first << "  " << k <<  "\n";
		if(planet != s.begin()) planet = prev(planet);
		else{
			ret = -1;
			break;
		}
		ret ++;
		remain -= (*planet).first;
		k += (*planet).first;
		s.erase(planet);
		cout << " ==> "<< ret << "  " << remain << "  " << (*planet).first << "  "  << k <<  "\n";
		
	}

	cout << ret << "\n";


	return 0;
}
