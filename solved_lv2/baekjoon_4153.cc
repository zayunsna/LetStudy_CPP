#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

bool check(int a, int b, int c){
	int side = a*a + b*b;
	if(side == c*c) return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	while(true){
		v.clear();
		int flag = 0;
		for(int i = 0; i < 3; ++i){
			cin >> n;
			v.push_back(n);
			if(n == 0){
				flag++;
				break;
			}
		}
		if(flag) break;
		sort(v.begin(), v.end());
		int flag2 = 0;
		do{
			if(check(v[0],v[1],v[2])){
				flag2 = 1;
				break;
			}
		}while(next_permutation(v.begin(), v.end()));

		if(flag2) cout << "right\n";
		else cout << "wrong\n";

	}

	return 0;
}
