#include <bits/stdc++.h>
using namespace std;

int n, m;
map<int,int> mp;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for(int i =0 ; i < n; ++i){
		cin  >> m;
		mp[m]++;
	}

	cin >> n; 
	for(int i = 0 ; i < n; ++i){
		cin >> m;
		cout << mp[m] << " ";
	}
	cout << "\n";

	return 0;
}
