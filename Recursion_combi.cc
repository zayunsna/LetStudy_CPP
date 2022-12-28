#include "/home/icegpu/HK/HKTool.h"
using namespace std;

int n = 5, k = 3, a[5] = {1, 2, 3, 4, 5};

void printV(vector<int> v){
	for(int i = 0; i < v.size(); ++i){
		cout << v[i] << " ";
	}
	cout << "\n";
}

int global_count = 0;
void combi(int start, vector<int> b){

	if(b.size() == k){
		cout << " Result : "; printV(b);
		global_count++;
		return ;
	}

	for(int i = start+1; i< n; ++i){
		cout << " ==> "<< i << "  " << start << endl;
		b.push_back(i);
		printV(b);
		combi(i, b);
		b.pop_back();
		printV(b);
	}
	return;

}

void Recursion_combi(){

	vector<int> b;
	combi(-1, b);

	cout << " total # of combination : " << global_count << endl;
}
