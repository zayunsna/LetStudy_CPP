#include "/home/icegpu/HK/HKTool.h"
using namespace std;

string alpha = "abcdefghijklmnopqrstuvwxyz";
map<char, int> lm;
void setFcn(){
	for(int i = 0; i < alpha.size(); ++i){
		char this_t = alpha[i];
		lm[this_t] = 0;
	}
	return;
}

void baekjoon_10808(){

	string input;
	cin >> input;

	setFcn();
	for(int i = 0; i < input.size(); ++i){
		char this_t = input[i];

		auto it = lm.find(this_t);
		if( it != lm.end()) lm[this_t]++;
	}

	for(auto it : lm){
		cout << it.second << " ";
	}
	cout << "\n";

}

// Short cut answer Using ASCI code
/*
string str;
int cnt[26];
void baekjoon_10808(){

	cin >> str;
	for(char a : str){
		cnt[a - 'a']++;
	}
	for(int i = 0 ; i < 26; ++i) cout << cnt[i] << " ";

	cout << "\n";	

}
*/
