#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int Inf = 1e9;
int x, y, w, h;
int ret = Inf;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> x >> y >> w >> h;
	
	ret = min(ret, abs(x-w));
	ret = min(ret, x);
	ret = min(ret, abs(y-h));
	ret = min(ret, y);
	
	cout << ret << "\n";
}
