#include "/home/icegpu/HK/HKTool.h"
#include <cstddef>
#include <ios>
using namespace std;

vector<string> split(string input, string delimiter){
	vector<string> ret;
	long long pos = 0;
	string token = "";
	while( (pos = input.find(delimiter)) != string::npos  ){
		token = input.substr(0, pos);
		ret.push_back(token);
		input.erase(0, pos + delimiter.length());
	}
	ret.push_back(input);
	return ret;
}

void string_split(){

	string s = "Hello, this is a coding test code for the coding test.";
	string type = " ";

	cout << " My input string is : " << s << "\n";
	cout << " , And  Delimieter is : " << type << "\n";
	cout << " String split process result are shown below \n";
	vector<string> a = split(s,type);

	for(string b : a) cout << b << "\n";



}
