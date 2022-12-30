#include "/home/icegpu/HK/HKTool.h"
using namespace std;

int n;
string tar, str, out;
vector<string> p;
vector<string> ret;



// Note that 'tar' will have a struction by prifix and suffix.
// It should be matched as a 'word', not a single charactor.
// the pattern is that two word divided by '*' should be located front and end of input string.

void baekjoon_9996(){

	cin >> n;
	cin >> tar;

	long long pos = 0;
	string token = "";
	while( (pos = tar.find('*')) != string::npos){
		token = tar.substr(0, pos);
		p.push_back(token);
		tar.erase(0, pos+1);
	}
	p.push_back(tar);

	for(int i = 0; i < n; ++i){
		cin >> str;

		if( p[0].size() + p[1].size() > str.size()) ret.push_back("NE");
		else{
			if( p[0] == str.substr(0, p[0].size() ) && p[1] == str.substr(str.size()-p[1].size()) ){
				ret.push_back("DA");
			}
			else ret.push_back("NE");
		}


	}

	for(auto i : ret) cout << i <<"\n";


}
