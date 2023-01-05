#include "/home/icegpu/HK/HKTool.h"
using namespace std;

int h, w;
string str;
char c;
int mat[105][105];

void baekjoon_10709(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> h >> w;

	for(int i = 0; i < h; ++i){
		cin >> str;
		for(int j = 0; j < w; ++j){
			if(str[j] == 'c') mat[i][j] = 1;
			else mat[i][j] = 0;
		}
	}

	for(int i = 0; i < h; ++i){
		int in = 1;
		for(int j = 0; j < w; ++j){
			if(mat[i][j] != 0){
				if(mat[i][j+1] == 1) in = 1;
				else in++;
				mat[i][j+1] = in;
			}
		}
	}
	
	for(int i = 0; i < h; ++i){
		for(int j = 0; j < w; ++j){
			cout << mat[i][j]-1 << " ";
		}
		cout << "\n";
	}
	



}
