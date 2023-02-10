#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int Inf = 1e9;
int n, m;
string fcn_1, fcn_2;

string cal(string str){
	int a = str[1] - '0';
	int b = str[3] - '0';
	char op = str[2];
	if(op == '^') return to_string(a^b);
	else if(op == '|') return to_string(a|b);
	else if(op == '&') return to_string(a&b);
}

int solve( string fcn ){
	int idx = 0; int Size = fcn.size();
	int len = 5;
	if( fcn == "1" || fcn == "0" ) return fcn[0] -'0';
	for(int i = 0; i < Size; ++i){
		if(fcn[i] == '(') idx = i;
		else if(fcn[i] == ')'){
			fcn.replace(fcn.find(fcn.substr(idx, len)), len, cal(fcn.substr(idx, len)));
			return solve(fcn);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> fcn_1;
	fcn_2 = fcn_1;

	int sSize = fcn_1.size();
	for(int i = 0; i < sSize; ++i){
		if(fcn_1[i] == 'x'){
			fcn_1[i] = '1';
			fcn_2[i] = '0';
		}
		else if(fcn_1[i] == 'X'){
			fcn_1[i] = '0';
			fcn_2[i] = '1';
		}
	}

	int ret = 0;
	if( solve(fcn_1) != solve(fcn_2) ) ret = 1;
	else ret = 0;
	cout << ret << "\n";

}
