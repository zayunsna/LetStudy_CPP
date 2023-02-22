#include <bits/stdc++.h>
using namespace std;

int n;
int ret;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	ret += n/5;
	int remain = n%5;

	if( remain  == 0) cout << ret << "\n";
	else if(remain == 4){
		if(ret) cout << ret+2 <<"\n";
		else cout << "-1\n";
	}
	else if(remain == 3){
		cout << ret+1 << "\n";
	}
	else if(remain == 2){
		if(ret >= 2) cout << ret+2 << "\n";
		else cout << "-1\n";
	}
	else if(remain == 1){
		if(ret) cout << ret+1 << "\n";
		else cout << "-1\n";
	}

	return 0;
}
