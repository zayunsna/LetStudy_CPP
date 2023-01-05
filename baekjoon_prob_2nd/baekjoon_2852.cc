#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

int n;
int a;
string str;
int c[3];
int m[3];
pair<int,int> p;
int flag = 0;

void split(string s, int &now){

	int m_now = atoi(s.substr(0,2).c_str());
	int s_now = atoi(s.substr(3,2).c_str());
	//cout << m_now << " : " << s_now << "\n";
	now = m_now*60 + s_now;
}

void baekjoon_2852(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for(int i = 0; i < n; ++i){
		int ts_now = 0;
		cin >> a >> str;
		c[a]++;
		split(str, ts_now);

		cout << a << "  " << ts_now << "\n";
		if((c[1] != c[2]) && (flag == 0)){
			cout << " Team : " << a << " Make point at " << ts_now << "\n";
			p = make_pair(a, ts_now);
			flag = 1;
		}

		if(c[1] == c[2]){
			flag = 0;
			m[p.first] += ts_now - p.second;
			cout << " Duce ! Team  : " << a << " Make point! " << "\n";
			cout << "     Team : " << p.first << " will have winning time : " << ts_now - p.second << " | Total : " << m[p.first] << "\n";
		}
		else if( i == n-1){
			m[p.first] += 48*60 - p.second;
			cout << " Game Set " << 48*60 << " " << p.second << "  " << m[p.first] << "\n";
			cout << "     Team : " << p.first << " will have winning time : " << 48*60 - p.second << " | Total : " << m[p.first] << "\n";
		}
	}

	for(int i = 0; i < 2; ++i){
		string m_p = to_string(m[i+1]/60);
		if(m_p.size() == 1) m_p = "0"+m_p;
		string s_p = to_string(m[i+1]%60);
		if(s_p.size() == 1) s_p = "0"+s_p;
		cout << m_p+":"+s_p << "\n";
	}

}
