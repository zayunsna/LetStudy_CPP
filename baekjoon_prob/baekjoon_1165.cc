#include "/home/icegpu/HK/HKTool.h"
using namespace std;
int p1[4] = {0, -1, 0, 1};
int p2[4] = {0,  1, 0,-1};
char mat[7][7];
string all;
string str;
string ret, p_ret;
int cnt = 0;

void solve(int start, int x, int y, string s){
	if(ret == s.substr(1,s.size())){
		if(p_ret != ret){
			cnt++;
			cout << s << endl;
		} 
		p_ret = ret;
		return;
	}

	for(int i = 1; i < 4; ++i){
		for(int j = 1; j < 4; ++j){
			int newx = x+p1[i];
			int newy = y+p2[j];
			char this_t = mat[newx][newy];
			if(this_t == '#' || (i == 2 && j == 2)) continue;
			ret += this_t;
			if(this_t == s[start+1]){
				//cout << i << "  " << j << " || "<< this_t << "  " << start+1 << "  " << x+p1[i] << " : " << y+p2[j] << "  " << ret << "\n";
				solve(start+1, newx, newy, s);
				//mat[newx][newy] = '#';
			}
			ret.pop_back();
		}
	}

}

void baekjoon_1165(){

	fill(&mat[0][0], &mat[0][0]+7*7, '#');


	for(int i = 0; i < 5; ++i){
		for(int j =0 ; j < 5; ++j){
			char a;
			cin >> a;
			mat[i+1][j+1] = a;
			all += a;
		}
	}

	ifstream in("dict.txt");
	
	while(getline(in, str)){
		if( all.find(str[0]) == string::npos) continue;

		for(int x = 0; x < 7; ++x ){
			for(int y = 0; y < 7; ++y){
				if(mat[x][y] == str[0])
					solve(0,x,y,str);
			}
		}
	}

	cout << cnt << endl;
	
}
	/*
	cout << all << endl;
	for(int x = 1; x < 6; ++x ){
		for(int y = 1; y < 6; ++y){
			cout << mat[x][y] << "  ";
		}
		cout << "\n";
	}

	cout << endl;

	str = "COOK";
	cout << str.size() << endl;
	for(int x = 0; x < 7; ++x ){
		for(int y = 0; y < 7; ++y){
		//	if(mat[x][y] == '#' )continue;
			if(mat[x][y] == str[0]){
				cout << " == > " << str[0] << "  " << x << " : " << y << "\n";
				ret = "";
				solve(0,x,y,str);
			}
		}
	}
	*/
