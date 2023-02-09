#include <bits/stdc++.h>
using namespace std;

string str;
int ret;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int tc;
	cin >> tc;
	for(int ic = 1; ic <= tc; ++ic){
		stack<string> st;
		cin >> str;
		int str_size = str.size();
		string token = "";
		for(int i = 0; i < str_size; ++i){
			token += str[i];
			if(!st.size()) {
				st.push(token);
				token = "";
				continue;
			}
			if(token != st.top()){
				st.push(token);
				token = "";
			}
			else continue;
		}
		cout << "#" << ic << " " << st.size() << "\n";
	}
	return 0;

}
