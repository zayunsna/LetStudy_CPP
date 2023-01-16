#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 50;
const int dy[4] = {0,1,0,-1};
const int dx[4] = {1,0,-1,0};
int N,board[MAX_N][MAX_N],best;
bool visited[MAX_N][MAX_N];
int dirTable[4][2] = {{3,1},{2,0},{3,1},{2,0}};
enum PIPESTATUS{
	EMPTY,LINE,ROTATE,
};

void init(){
	cin>>N;
	best = 1e9;
	for(int y=0;y<N;++y){
		for(int x=0;x<N;++x){
			cin>>board[y][x];
			visited[y][x] = false;
		}
	}
	for(int y=0;y<N;++y){
		for(int x=0;x<N;++x){
			if(board[y][x]==1 || board[y][x]==2){
				board[y][x] = LINE;
			}else if(board[y][x]>=3){
				board[y][x] = ROTATE;
			}
		}
	}
}

inline bool checkValid(int y,int x){
	return y>=0 && y<N && x>=0 && x<N;
}
inline int getRemainDist(int y,int x){
	return y+x;
}

void dfs(int y,int x,int prevDir,int dist){
	if(!checkValid(y,x) || visited[y][x] || dist+getRemainDist(y,x) >= best){
		return;
	}
	if(y==0 && x==0){
		if((board[y][x]==LINE && prevDir==2) || (board[y][x]==ROTATE && prevDir==3)){
			best = min(best,dist);
		}
		return;
	}
	visited[y][x] = true;

	if(board[y][x]==LINE){
		dfs(y+dy[prevDir],x+dx[prevDir],prevDir,dist+1);
	}else if(board[y][x]==ROTATE){
		const int firstDir = dirTable[prevDir][0];
		const int secondDir = dirTable[prevDir][1];
		dfs(y+dy[firstDir],x+dx[firstDir],firstDir,dist+1);
		dfs(y+dy[secondDir],x+dx[secondDir],secondDir,dist+1);
	}
	visited[y][x] = false;
}


int run(){
	init();
	dfs(N-1,N-1,2,1);
	return best;
}

void pipe_solution(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int test_case;
	int T;
	cin>>T;   
	for(test_case = 1; test_case <= T; ++test_case)
	{        
		cout<<"#"<<test_case<<" "<<run()<<'\n';
	}

}
