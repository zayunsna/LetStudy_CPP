#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int Inf = 1e9;
int n, m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int lim = 13;
	string inp;
	cin >> inp;
	n = 0;

	int tar = 0;
	for(int i = 0; i < lim-1; ++i){
		int s = int(inp[i]) - '0';
		if(s == -6) {tar = i+1; continue;}
		if((i+1)%2==0) n += s*3;
		else n += s;
		// cout << i << "  " << s << "  " << n << endl;
	}
	m = int(inp[12]) - '0';
	int m_v = (m==0)?0:10-m;
	// cout << "m   : " << m << endl;
	// cout << "m_v : " << m_v << endl;
	// cout << "n   : " << n << endl;
	int s = 0;
	for(int i = 0; i < 10; ++i){
		if(tar%2 == 0) s = i*3;
		else s = i;
		// cout << i << "  " << (n+s) << "  " << (n+s)%10 << endl;
		if((n+s)%10 == m_v){
			cout << i << endl;
			break;
		}
	}
	return 0;	
}
