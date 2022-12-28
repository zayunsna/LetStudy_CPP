#include "/home/icegpu/HK/HKTool.h"
using namespace std;

vector<int> v;

void binary(){

	int n = 53;
	int b = 2;
	while(n > 1){
		v.push_back( n % b);
		n /= b;
	}
	if(n == 1) v.push_back(1);
	reverse(v.begin(), v.end());

	for(auto a : v){
		cout << a;
	}
	cout << endl;
	
	n = 53;
	b = 16;
	v.clear();

	while(n > 1){
		v.push_back( n % b);
		n /= b;
	}
	if(n == 1) v.push_back(1);
	reverse(v.begin(), v.end());
	for(auto a : v){
		if( a >= 10) cout << char(a+55);
		else cout << a;
	}
	cout << endl;

}
