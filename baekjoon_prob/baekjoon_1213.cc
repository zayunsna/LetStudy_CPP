#include "/home/icegpu/HK/HKTool.h"
#include <ios>
using namespace std;

string a = "ABCDEFGHIJKMLNOPQRSTUWXYZ";
string no = "I'm Sorry Hansso";
string ret = "";
map<char, int> lt;
void set(){
	for(int i = 0; i < 26; ++i) lt[a[i]] = 0;
}


string str;
void baekjoon_1213(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> str;
	for(int i = 0; i < str.size(); ++i){
		lt[str[i]]++;
	}
	for(int i = 0; i < 26; ++i) cout << lt[a[i]] << endl;
	int cnt = 0;
	char mid;
	for(int i = 25; i >= 0; i--){
		if(lt[a[i]] > 0){
			if( lt[a[i]] & 1){
				mid = a[i];
				cnt++;
				lt[a[i]]--;
			}
			if(cnt > 1) {
				break;
			}
			else{
				for(int j = 0; j < lt[a[i]]; j += 2){
					ret += a[i];
					ret = a[i] + ret;
				}
			}
		}
	}

	if(mid) ret.insert(ret.begin()+ret.size()/2., mid);
	if(cnt > 1) cout << no << "\n";
	else cout << ret << "\n";


}
