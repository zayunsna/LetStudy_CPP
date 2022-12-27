#include "/home/icegpu/HK/HKTool.h"
using namespace std;

#define eend "\n"

void test1(){

	string a = "Love is";
	a += " pain!";
	cout << a << " : " << a.size() << eend;

	a.pop_back();
	cout << a << " : " << a.size() << eend;

	cout << char(* a.begin()) << eend;
	cout << char(* (a.end() - 1)) << eend;

	a.insert(0, "test ");
	cout << a << " : " << a.size() << eend;

	a.erase(0, 5);
	cout << a << " : " << a.size() << eend;

	auto it = a.find("Love");

	if( it != string::npos ){
		cout << " Is here! " << eend;
	}
	cout << it << eend;
	cout << string::npos << eend;

	cout << a.substr(5, 2) << eend;

}
