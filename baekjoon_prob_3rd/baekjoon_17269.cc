#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100;
const int Inf = 1e9;
//int mat[2*N+4];
vector<int> mat;
int n, m;
string a, b;
int ret;

int word[26] = {3, 2, 1, 2, 4, 3, 1, 3, 1, 1, 3, 1, 3, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};

void solve(vector<int> v){
	int vSize = v.size();
	if(vSize == 2){
		ret = v[0]*10 + v[1];
		return;
	}
	
	vector<int> next;
	for(int i = 0; i < vSize-1; ++i){
		next.push_back((v[i]+v[i+1])%10);
	}
	solve(next);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	cin >> a >> b;
	
	int mn = min(n,m);
	int mx = max(n,m);
	string str = "";
	for(int i = 0; i < mn; ++i){
		str += a[i];
		str += b[i];
	}
	str += a.substr(mn, mx);
	str += b.substr(mn, mx);
	
	int sSize = str.size();
	for(int i = 0; i < sSize; ++i){
		//mat[i] = word[(int)str[i]-'A'];
		mat.push_back(word[(int)str[i]-'A']);
	}

	solve(mat);

	cout << ret << "%\n";
	return 0;
}
