#include "/home/icegpu/HK/HKTool.h"
#include <ios>
using namespace std;


const int w = 5;
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
char mat[w][w];
int visitied[w][w];
char c;
//int cnt = 0;
vector<string> cnt;
int ny, nx;
string prompt_s;
string ret;

void dfs(int start, int y, int x, string str){

	if( ret == str.substr(1,str.size())){
		//cout << ret << "  " << str.substr(1, str.size()) << " result " << endl;
		if( find(cnt.begin(), cnt.end(), str) == cnt.end()){
			cout << ret << "  " << str << endl;
			cnt.push_back(str);		
		}
		return;
	}


	visitied[y][x] = 1;

	//cout << y << "  " << x << "  " << mat[y][x] << "\n";
	for(int i = 0; i < 8; ++i){
		ny = y + dy[i];
		nx = x + dx[i];
		if(ny < 0 || nx < 0 || ny >= w || nx >= w) continue;
		ret += mat[ny][nx];
		if(mat[ny][nx] == str[start+1] && !visitied[ny][nx]){
			//cout << ny << "  " << nx << "  " << mat[ny][nx] << " is started \n";
			dfs(start+1, ny, nx, str);
		}
		ret.pop_back();
	}
	return;
}

void baekjoon_13502(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	prompt_s = "";

	for(int i = 0; i < w; ++i){
		for(int j = 0; j < w; ++j){
			cin >> mat[i][j];
			prompt_s += mat[i][j];
		}
	}

	ifstream inFile("dict.txt");
/*
	string line = "UFC";
	c = line[0];
	if(prompt_s.find(c) != string::npos){
		for(int i = 0; i < w; ++i){
			for(int j = 0; j < w; ++j){
				if(mat[i][j] == c){
					cout << i << "  " << j << "  " << c <<  " is input " << endl;
					dfs(0,i,j,line);
				}
			}
		}
	}

	cout << cnt.size() << "\n";
*/

	string line;
	
	while(getline(inFile,line)){
		c = line[0];
		if(prompt_s.find(c) != string::npos){
			for(int i = 0; i < w; ++i){
				for(int j = 0; j < w; ++j){
					if(mat[i][j] == c){
						fill(&visitied[0][0], &visitied[0][0]+w*w, 0);
						dfs(0,i,j,line);
					}
				}
			}
		}
	}


	cout << cnt.size() << "\n";
	

}
