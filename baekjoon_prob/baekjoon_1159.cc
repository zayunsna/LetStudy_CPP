#include "/home/icegpu/HK/HKTool.h"
using namespace std;

string str;
int N, cnt[150];


void baekjoon_1159(){
	cin >> N;

	for(int i = 0; i < N; ++i){
		cin >> str;
		cnt[str[0] - 'a']++;
	}

	if( *max_element(cnt, cnt+150) >=5 ){
		for(int i = 0; i < 150; ++i){
			if(cnt[i] >= 5) cout << char(i+'a');
		}
		cout << "\n";
	} 
	else cout << "PREDAJA" << "\n";


}
