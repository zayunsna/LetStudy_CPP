#include <bits/stdc++.h>
using namespace std;

int n , m;
const int N = 1000;
int mat[N+4];
vector<int> v;
vector<int> ret;

bool check(int z[N+4]){
	for(int i = 0; i < n; ++i){
		if(mat[i] == 0) return true;
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for(int i = 0; i < n; ++i) v.push_back(i+1);

	int cnt = -1;
	int idx = 0;
	while(true)	{
		if(mat[idx%n]) {
			idx++;
			continue;
		}
		else cnt += 1;
		if( (cnt+1) % m == 0) {
			ret.push_back(v[idx%n]);
			mat[idx%n] = 1;
		}
		if(ret.size() == n) break;
		idx++;
	}

	cout << "<";
	for(int i = 0; i < n; ++i){
		if( i < n-1 ) cout << ret[i] << ", ";
		else cout << ret[i];
	}
	cout << ">\n";

	return 0;
}
