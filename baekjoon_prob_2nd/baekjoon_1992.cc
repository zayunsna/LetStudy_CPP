#include "/home/icegpu/HK/HKTool.h"
#include <ios>
using namespace std;

int n;
char mat[104][104];

string fcn(int y, int x, int size){
	if(size == 1) return string(1, mat[y][x]);
	char b = mat[y][x];
	string ret = "";
	for(int i = y; i < y+size; ++i){
		for(int j = x; j < x+size; ++j){
			if( b != mat[i][j]){
				ret += "(";
				ret += fcn(y, x, size/2);
				ret += fcn(y, x+size/2, size/2);
				ret += fcn(y + size/2, x, size/2);
				ret += fcn(y+size/2, x+size/2, size/2);
				ret += ")";
				return ret;
			}
		}
	}
	return string(1, mat[y][x]);
}


void baekjoon_1992(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> mat[i][j];
		}
	}

	cout << fcn(0,0,n) << "\n";


}
