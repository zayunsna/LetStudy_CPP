#include <bits/stdc++.h>
using namespace std;

int tc, n, m, k;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> tc;
	for(int i = 0; i < tc; ++i){
		cin >> n >> m >> k;
		int floor = (k%n == 0) ? n*100 : k%n*100;
		//int floor = k%n;
		int room = (k-1)/n +1;

		cout << floor+room << "\n";
		//cout << floor << "  " << room << "\n";
	}

	return 0;
}
