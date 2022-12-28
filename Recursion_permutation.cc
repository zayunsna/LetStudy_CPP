#include "/home/icegpu/HK/HKTool.h"
#include <string>
#include <utility>
using namespace std;

vector<int> v;
int a[3] = {1, 2, 3};

void printV(vector<int> v){
	for(int i = 0; i < v.size(); ++i){
		cout << v[i] << " ";
	}
	cout << "\n";
}

void makePermutation(int n, int r, int depth){
	cout << " n : " << n << " | r : " << r << " | depth : " << depth << "\n";
	if( r == depth){
		cout << " ==========  Finished ! \n";
		printV(v);
		return;
	}
	for(int i = depth; i < n ; ++i){
		//cout << " ## " << i << "\n";
		swap(v[i], v[depth]);
		cout << " Swap 1 : "; printV(v);
		//cout << "First swap : " << i << "  " << depth << "  " << v[i] << "  " << v[depth] << "\n";
		makePermutation(n, r, depth + 1);
		swap(v[i], v[depth]);
		cout << " Swap 2 : "; printV(v);
		//cout << "Second swap : " << i << "  " << depth << "  " << v[i] << "  " << v[depth] << "\n";
	}
	return;
}

void Recursion_permutation(){

	for(int i = 0; i < 3; ++i) v.push_back(a[i]);
	makePermutation(3, 3, 0);

}
