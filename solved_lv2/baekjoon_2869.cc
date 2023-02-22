#include <bits/stdc++.h>
using namespace std;

double n, m, v;
int _now;
int ret;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> v;

	if(n >= v){
		cout << 1 << "\n";
		return 0;
	}
	ret = ceil((v-n)/(n-m));
	if(ret < 1) ret = 2;
	else ret += 1;

	cout << ret << "\n";

	return 0;
}
