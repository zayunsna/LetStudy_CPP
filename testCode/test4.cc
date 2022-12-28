#include "/home/icegpu/HK/HKTool.h"
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void test4(){

	vector<int> v;
	int a[5] = {1, 2, 2, 2, 3};
	for(int i = 0; i < 5; ++i){
		v.push_back(a[i]);
	}

	int x = 2;
	int c = (int)(upper_bound(v.begin(), v.end() , x) - lower_bound(v.begin(), v.end(), x));
	int f = (int)(lower_bound(v.begin(), v.end(), 2) - v.begin());
	int t = (int)(upper_bound(v.begin(), v.end(), 2) - v.begin());

	int f2 = *lower_bound(v.begin(), v.end(), x);
	int t2 = *upper_bound(v.begin(), v.end(), x);

	cout << " the number of x [" << x <<"] : " << c << " | Start point : " << f << " , End point : " << t << "\n";
	cout <<  f2 << " | " << t2 << "\n";


	vector<int> aa;

	for(int i = 2; i <=5; ++i) aa.push_back(i);
	aa.push_back(7);

	cout << upper_bound(aa.begin(), aa.end(), 6) - aa.begin() << "\n";
	cout << lower_bound(aa.begin(), aa.end(), 6) - aa.begin() << "\n";
	cout << upper_bound(aa.begin(), aa.end(), 9) - aa.begin() << "\n";
	cout << lower_bound(aa.begin(), aa.end(), 9) - aa.begin() << "\n";
	cout << upper_bound(aa.begin(), aa.end(), 0) - aa.begin() << "\n";
	cout << lower_bound(aa.begin(), aa.end(), 0) - aa.begin() << "\n";

	map<string, int> mp;
	string name[4] = {"aaa","bbb","ccc","ddd"};

	for(int i = 0; i < 4; ++i) mp.insert({name[i], i+1});

	string type;
	int p;
	//for(auto it : mp)
	for(map<string, int>::iterator it = mp.begin(); it != mp.end(); ++it)
	{
		tie(type,p) = *it;
		cout << type << " : " << p << endl;
	}



}
