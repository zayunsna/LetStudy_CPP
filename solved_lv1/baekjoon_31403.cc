#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int Inf = 1e9;
int n, m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string a, b, c;
	cin >> a; cin >> b; cin >> c;

	cout << stoi(a)+stoi(b)-stoi(c) << endl;
	string p = a+b;
	cout << stoi(p) - stoi(c) << endl;
	
}
