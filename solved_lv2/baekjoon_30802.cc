#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int Inf = 1e9;
int n, m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int people = 0;
	int pack_s = 0, pack_p = 0;

	cin >> people;
	vector<int> cont;
	for(int i = 0; i < 6; ++i){
		cin >> n;
		cont.push_back(n);
	}
	cin >> pack_s >> pack_p;

	m = 0;
	for(int i = 0; i < 6; ++i){
		 if (cont[i] == 0) continue;
		 else if (cont[i] != 0 && cont[i] < pack_s) m+=1;
		 else if (cont[i]%pack_s == 0) m += cont[i]/pack_s;
		 else m += (cont[i]/pack_s)+1;
	}
	cout << m << endl;
	cout << people/pack_p << " " << people%pack_p << endl;
	return 0;

	
}
