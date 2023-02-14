#include <bits/stdc++.h>
using namespace std;

int n;
int factor = 6;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	int ret = 1;
	if(n == 1){
		cout << ret << "\n";
		return 0;
	} 

	int now = 1;
	while(true){
		now += factor*ret;

		if(now >= n) break;
		ret++;
	}

	cout << ret+1 << "\n";

	return 0;
}
