#include "/home/icegpu/HK/HKTool.h"
#include <ios>
using namespace std;

int n;
string str, box;
vector<string> ret;

void fcn(){
	while(1){
		if(box.size() && box.front() == '0') box.erase(box.begin());
		else break;
	}
	if(box.size() == 0) box = "0";
	ret.push_back(box);
	box = "";
	
}

bool cmp(string a, string b){
	if(a.size() == b.size()){ return a < b;}
	return a.size() < b.size();

}

void baekjoon_2870(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> str;
		box = "";
		for(int j = 0; j < str.size(); ++j){
			if(str[j] < 65) box += str[j];
			else if(box.size()) fcn();
		}
		if(box.size()) fcn();
	}

	sort(ret.begin(), ret.end(), cmp);
	for(int i = 0; i < ret.size(); ++i){
		cout << ret[i] << "\n";
	}


}
