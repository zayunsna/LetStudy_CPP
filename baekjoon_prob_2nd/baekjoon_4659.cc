#include "/home/icegpu/HK/HKTool.h"
#include <ios>
#include <locale>
using namespace std;

string str;

string m = "aeiou";
string j = "bcdfghjklmnpqrstvwxyz";
string ok = " is acceptable.";
string no = " is not acceptable.";

bool fcn(string s){
	int s_size = s.size();
	int m_cnt = 0;
	int m2_cnt = 0;
	int j_cnt = 0;
	int pos = 0;
	for(int i = 0; i < 5; ++i){
		pos = s.find(m[i]);
		if( pos != -1 ) break;
	}
	if( pos == -1) return false;

	for(int i = 0; i < s_size; ++i){
		char n = s[i];
		if( m.find(n) != string::npos){
			m_cnt++;
			j_cnt = 0;
			if(m_cnt > 1){
				if( n == s[i-1] ){
					if( n == 'o' || n == 'e'){
						m2_cnt++;
						if(m2_cnt > 1) return false;
						continue;
					}
					else return false;
				}
				else if( m_cnt > 2) return false;
			}

		}
		else{
			j_cnt++;
			m_cnt = 0;
			m2_cnt = 0;
			if(j_cnt > 1){
				if(n == s[i-1]) return false;
				else if ( j_cnt > 2) return false;
			}
		}
	}
	return true;
}


void baekjoon_4659(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	while(cin >> str){
		if(str == "end") break;

		if(fcn(str)) cout << "<"<< str << ">" << ok << "\n";
		else cout << "<"<< str << ">" << no << "\n";

	}

}
