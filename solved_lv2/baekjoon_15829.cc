#include <bits/stdc++.h>
using namespace std;

long long n, ret;
string str;
long long MOD = 1234567891;
int R = 31;

long long _pow(int a){
	long long out = 1;
	for(int i = 0; i < a; ++i){
		out *= R%MOD;
	}

	return out;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> str;

	for(int i = 0; i < n; ++i){
		long long _now = (int)(str[i] - 'a') + 1;
		ret += _now * _pow(i);
	}

	cout << ret << "\n";

	return 0;
}
