#include "/home/icegpu/HK/HKTool.h"
using namespace std;

const int ROT = 13;
int L_a = 65;
int S_a = 97;
int N_a = 26;
string str;
string ret;

void baekjoon_11655(){


	getline(cin, str);

	for(int i = 0; i < str.size(); ++i){
		int this_t = (int)str[i];
		if( this_t >= L_a && this_t < L_a+N_a){
			int conv = this_t + ROT;
			//if( conv >= L_a+N_a) conv = L_a + (conv - L_a - N_a);
			if( conv >= L_a+N_a) conv -=  N_a;
			ret += (char)conv;
		}
		else if( this_t >= S_a && this_t < S_a+N_a){
			int conv = this_t + ROT;
			if( conv >= S_a+N_a) conv -= N_a;
			ret += (char)conv;
		}
		else ret += (char)this_t;
	}

	cout << ret << "\n";

}
