#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 50;
int mat[N][N];
int vis[N][N];
string let = "";
int ball[4];

int n, x;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

bool validate(int y, int x){
	if( y < 0 || x < 0 || y >= n || x >= n ) return true;
	return false;
}

void makeFull(string & str){
	int s = str.size();
	int end = n*n-s;
	if(end < 0) {
		str = str.substr(0,n*n-2);
		return;
	}
	for(int i = 0; i < end; ++i){
		str.push_back('0');
	}
}

void setMat(){
	int cri = (n+1)/2;
	int dir = 0;
	int ny = 0, nx = 0;
	let += to_string(mat[0][0]);
	int cnt = 1;
	vis[0][0] = 1;
	for(int i = 0; i < n*n+100; ++i){
		if(dir >= 4) dir = 0;
		ny += dy[dir];
		nx += dx[dir];
		if( validate(ny, nx) || vis[ny][nx]) {
			ny -= dy[dir];
			nx -= dx[dir];
			dir++;
			continue;
		}
		vis[ny][nx] = cnt+1; 
		//cout << mat[ny][nx] << "\n";
		if( ny == cri-1 && nx == cri-1) break;
		let += to_string(mat[ny][nx]);
		cnt++;
	}
	reverse(let.begin(), let.end());
	makeFull(let);
}
vector<int> selectPos(int dir, int dist){
	vector<int> out;
	int s[5] = {0,6,2,0,4};
	int gap[5] = {0,15, 11, 9, 13};
	for(int i = 1; i <= dist; ++i){
		int num = s[dir];
		for(int j = 1; j  < i; ++j){
			num += gap[dir]+ 8*(j-1);
		}
		out.push_back(num);
	}
	return out;
}
void bomb(string & str){
	int s = str.size();
	int now = 0, prev = 0, cnt = 0, point = 0;
	for(int i = 0; i < s; ++i){
		now = int(str[i]);
		
		if(now == 0) continue;
		if(now == prev){
			if(point  == 0 ) point = i;
			cnt++;
		}
		else{
			if(cnt >= 3){
				ball[prev-'0'] += cnt+1;
				str.erase(point-1, cnt+1);
				i = 0;
			} 
			cnt = 0;
			point = 0;
		}
		prev = now;
	
	}
	makeFull(str);
}



void comb(string &str){
	string out = "";
	int s = str.size();
	int now, prev = 0, cnt = 0, point = 0;
	for(int i = 0; i < n*n-1; ++i){
		now = int(let[i])-'0';
		if(now == 0) continue;
		if(now == prev){
			cnt++;
		}
		else{
			if(prev != 0){ 
				out += to_string(cnt+1) + to_string(prev);
			}
			cnt = 0;
		}
		prev = now;
	}
	str = out;
	makeFull(str);
}
void baekjoon_21611(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> x;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> mat[i][j];
		}
	}
	queue<pair<int,int>> q;
	for(int i = 0; i < x; ++i){
		int d, l;
		cin >> d >> l;
		q.push({d,l});
	}

	setMat();

	while(q.size()){
		auto it = q.front(); q.pop();
	//	cout << " 1:: " << let << "\n";
		vector<int> tor = selectPos(it.first, it.second);
		for(int i = tor.size()-1; i >= 0; --i){
			//cout << i << "  " << let[tor[i]] << "\n";
			let.erase(tor[i], 1);
		}
		makeFull(let);

	//	cout << " 2:: " << let << "\n";
		bomb(let);
	//	cout << " 3:: "<< let << "\n";

		comb(let);
	//	cout << " 4:: "<< let << "\n";

	}
	int ret = 0;

	for(int i = 1; i < 4; ++i){
		ret += i * ball[i];
	}
	cout << ret << "\n";

	exit(0);

}
