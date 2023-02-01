#include <bits/stdc++.h>
using namespace std;


const int N = 10;
int a[N+4][N+4];
int mat[N+4][N+4];
vector<int> tree[N+4][N+4];
int n, m, k;

int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1 ,-1};

void springAndSummer(){

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(tree[i][j].size()){
				vector<int> temp;
				int death = 0;
				sort(tree[i][j].begin(), tree[i][j].end());
				for(int k : tree[i][j]){
					int &og = mat[i][j];
					if( og >= k ) {
						og -= k; 
						temp.push_back(k+1);
					}
					else {
						death += k/2;
					}
				}
				tree[i][j].clear();
				tree[i][j] = temp;	
				mat[i][j] += death;	
			}
		}
	}
	return;
}
/*
void summer(){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(death[i][j].size()){
				int &og = mat[i][j];
				for(int k : death[i][j]) og += k/2;
			}
		}
	}
}
*/

void fall(){
	vector<pair<int,int>> vp;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(tree[i][j].size()){
				for(int k : tree[i][j]){
					if(k%5 == 0){
						vp.push_back({i,j});
					}
				}
			}
		}	
	}
	
	for(auto it : vp){
		int y = it.first;
		int x = it.second;
		for(int i = 0; i < 8; ++i){
			int ny = it.first + dy[i];
			int nx = it.second + dx[i];
			if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			tree[ny][nx].push_back(1);
		}
	}
	
}

void winter(){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			mat[i][j] += a[i][j];
		}
	}
}

void mp(int z[N+4][N+4]){
 	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cout << z[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void vvp(vector<int> z[N+4][N+4]){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(!z[i][j].size()) continue;
			cout << i << " : " << j << " = ";
			for(int it : z[i][j]) cout << it << " ";
			cout << "\n";
		}
	}	
	cout << "\n";
}
int countTree(){
	int ret = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(tree[i][j].size()){
				ret += tree[i][j].size();
			}	
		}
	}
	
	return ret;
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	fill(&mat[0][0], &mat[0][0]+14*14, 5);
	cin >> n >> m >> k;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < m; ++i){
		int y, x, age;
		cin >> y >> x >> age;
		tree[y-1][x-1].push_back(age);
	}
	/*
	mp(mat);
	spring();
	mp(mat);
	vvp(tree);
	summer();
	mp(mat);
	fall();
	vvp(tree);
	winter();
	mp(mat);
	vvp(tree);

	
	
	for(int i = 0; i < k; ++i){
		cout << " Year  " << i << "\n";
		mp(mat);
		cout << " Spring \n";
		spring();
		mp(mat);
		vvp(tree);
		
		cout << " Summer \n";
		summer();
		mp(mat);
		
		
		cout << " Fall \n";
		fall();
		vvp(tree);
		
		cout << " Winter \n";
		winter();
		mp(mat);
		vvp(tree);
		cout << "\n\n";
	}
	*/
	
	
	for(int i = 0; i < k; ++i){
		//spring();
		//summer();
		springAndSummer();
		fall();
		winter();
	}
	
	
	cout << countTree() << "\n";
	return 0;
}
