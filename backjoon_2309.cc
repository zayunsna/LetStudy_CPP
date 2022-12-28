#include "/home/icegpu/HK/HKTool.h"
using namespace std;

const int N = 9;
const int target = 100;
vector<int> t(9,0);


//9C7 Using Combination 
// 9C7 = 9C2

pair<int, int> ret;

void solve(){
	int sum = accumulate(t.begin(), t.end(), 0);
	for(int i = 0; i < N; ++i){
		for(int j = i+1; j < N; ++j){
			int this_ret = sum - (t[i] + t[j]);
			cout << sum << "  " << t[i] << "  " << t[j] << "  " << this_ret << endl;
			if( this_ret == target){
				ret = make_pair(i, j);
				return;
			}
		}
	}
}

void backjoon_2309(){

	for(int i = 0; i < N; ++i){
		cin >> t[i];
	}
	sort(t.begin(), t.end());

	solve();

	vector<int> result;
	for(int i = 0; i < N; ++i){
		if( i == ret.first || i == ret.second) continue;
		result.push_back(t[i]);
	}

	cout << " == " << endl;
	for(auto i : result) cout << i << "\n";

}



// 9P7 Using Permutation
/*
void backjoon_2309(){

	for(int i = 0; i < N; ++i){
		cin >> t[i];
	}
	sort(t.begin(), t.end());

	do{
		for(int i : t) cout << i << "  ";
		cout << "\n";
		int sum = 0;
		//for(int i = 0; i < 7; ++i) sum += t[i];
		sum = accumulate(t.begin(), t.end()-2, 0);
		
		if(sum == target) break;
	}while(next_permutation(t.begin(), t.end()));

	for(int i = 0; i < 7; ++i) cout << t[i] << "\n";


}
*/
