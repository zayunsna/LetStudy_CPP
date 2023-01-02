#include "/home/icegpu/HK/HKTool.h"
#include <ios>

using namespace std;

typedef long long ll;

ll a, b, c;
ll solve(ll a, ll b){
	if( b == 1) return a%c;

	ll ret = solve(a, b/2);
	ret = (ret*ret) % c;
	if( b % 2 == 1) ret = (ret * a) % c;
	return ret;
}


void baekjoon_1629(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b >> c;
	cout << solve(a,b) << "\n";

}
