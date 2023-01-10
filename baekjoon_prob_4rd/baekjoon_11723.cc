#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 21;
int S = (0<<N);
int n;
string str;
string type;
int x;
string gap = " ";

vector<string> split(string a, string b){
	vector<string> ret;
	long long pos = 0;
	string token = "";
	while( (pos = a.find(b)) != string::npos){
		token = a.substr(0, pos);
		ret.push_back(token);
		a.erase(0, pos+b.length());
	}
	ret.push_back(a);
	return ret;
}

void test11(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for(int i = 0; i <= n; ++i){
		getline(cin, str);
		if(i == 0) continue;
		vector<string> sp = split(str,gap);
		if(sp.size() == 2){
			type = sp[0];
			x = atoi(sp[1].c_str());
		}
		else{
			type = sp[0];
			x = N;
		}

		if(type == "add"){
			S |= (1<<x);
		}
		else if(type == "remove"){
			S &= ~(1<<x);
		}
		else if(type == "toggle"){
			S ^= (1<<x);
		}
		else if(type == "check"){
			if(S & (1<<x)) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if(type == "all"){
			S = (1<<N)-1;
		}
		else if(type == "empty"){
			S = (0<<N);
		}

	}


}
