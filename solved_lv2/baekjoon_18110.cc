#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int Inf = 1e9;
int n, m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector<int> items;

	cin >> n;
	if(n == 0){
		cout << 0 << endl;
		return 0;
	}
	for(int i = 0; i < n; ++i) {
		cin >> m;
		items.push_back(m);
	}
	int cut = floor((n*0.3)/2. + 0.5);
	sort(items.begin(), items.end());

	// cout << n << "  " << cut << endl;
	int start = cut;
	int end = n - cut;
	float amount = items.size() - cut*2;
	m = 0;
	for(int i = start; i < end; ++i){
		m += items[i];
		// cout << i << "  " << items[i] << "  " << m << endl;
	}

	// cout << m << " / " << amount << " = " << m/amount << endl;

	cout << floor(m/amount + 0.5) << endl;

}
