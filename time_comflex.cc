#include <iostream>
using namespace std;

int N, cnt;

void solve(int N){
	cnt++;
	if (N == 0) return;
	for( int i = 0; i < 3; ++i){
		cout << N -1 << endl;
		solve(N - 1);
	}
	return ;
}


void time_comflex(){

	cin >> N;
	solve(N);
	
	cout << cnt << "\n";

	// Required time consumtion (complexcity) is O(3^n) for this case. 

}
