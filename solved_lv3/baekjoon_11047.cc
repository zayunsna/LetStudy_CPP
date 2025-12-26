#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int Inf = 1e9;
int n, m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	vector<int> ls;
	int tmp;
	for(int i = 0; i < n; ++i){
		cin >> tmp;
		ls.push_back(tmp);
	}

	int thr, _this;
	int count = 0;
	for(int i = n-1; i >= 0; --i){
		thr = ls[i];
		// cout << i << "  " << thr << "  " << m << endl;
		if(thr <= m){
			_this = m/thr;
			m -= _this*thr;
			count += _this;
			// cout << "  -> " << _this << "  " << m << "  " << count << endl;
		}
	}

	cout << count << endl;
	
}
