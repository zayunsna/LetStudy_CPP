#include "/home/icegpu/HK/HKTool.h"
#include <queue>
#include <vector>

using namespace std;

int number = 9;
int visit[9];
vector<int> a[10];

void bfsRun(int start){

	queue<int> q;
	q.push(start);
	visit[start] = true;

	while(!q.empty()){
		int x = q.front();
		q.pop();

		cout << x << "\n";
		for(int i = 0; i < a[x].size(); ++i){
			int y = a[x][i];
			if(!visit[y]){
				q.push(y);
				visit[y] = true;
			}
		}
	}

}


void bfs_1(){

	a[1].push_back(2);
	a[2].push_back(1);

	a[1].push_back(3);
	a[3].push_back(1);

	a[2].push_back(4);
	a[4].push_back(2);

	a[2].push_back(5);
	a[5].push_back(2);

	a[4].push_back(8);
	a[8].push_back(4);

	a[5].push_back(9);
	a[9].push_back(5);

	a[3].push_back(6);
	a[6].push_back(3);

	a[3].push_back(7);
	a[7].push_back(3);

	bfsRun(1);


}
