#include "/home/icegpu/HK/HKTool.h"
#include <ios>
using namespace std;

int n;
string str;

vector<int> mat;

string ret;

bool v_check(vector<int> vec){
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	int size = vec.size();
	if(size == 1) return true;
	else return false;
}

void dfs(vector<int> m, int n){
	if(n == 2){
		if(v_check(m)){
			ret += to_string(m[0]);
		}
		else{
			ret += "(";
			for(int i =0 ; i < 4; ++i) ret += to_string(m[i]);
			ret += ")";
		}
		return;
	}
	const int t_n = n/2;
	vector<int> t_m;

	ret += "(";
	for (int i = 0; i < 2; ++i){
		for(int j = 0; j < 2; ++j){
			int ly = t_n*i;
			int lx = t_n*j;
			t_m.clear();
			for(int ii = 0; ii < n; ++ii){
				for(int jj = 0; jj < n; ++jj){
					if( (ly <= ii && ii < ly+t_n) && (lx <= jj && jj < lx+t_n ) ){
						int now = m[ii*n + jj];
						t_m.push_back(m[ii*n + jj]);
					}
				}
			}
			if(v_check(t_m)){
				ret += to_string(t_m[0]);
			}
			else dfs(t_m, t_n);
		}
	}
	ret += ")";
	return;

}


void baekjoon_1992_HK(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	cin >> n;

	for(int i = 0; i < n; ++i){
		cin >> str;
		for(int j = 0; j < n; ++j){
			mat.push_back((int)str[j] -'0');
		}
	}

	if(v_check(mat)){
		cout << to_string(mat[0]) << "\n";
	}
	else {
		dfs(mat, n);
		cout << ret << "\n";
	}

}
