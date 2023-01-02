#include "/home/icegpu/HK/HKTool.h"
#include <ios>
using namespace std;

int n;
int ret;

void baekjoon_4375(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while(cin >> n){
		int cnt = 1; ret = 1;
		while(true){
			if( cnt % n == 0){
				cout << ret << "\n";
				break;
			}
			else{
				cnt = (cnt * 10) +1;
				cnt %= n;
				ret++;
			}

		}
	}

	/*{
		string str = "1";
		bool flag = false;
		while(!flag){
			if(str.size() > 18) break;
			long long this_i = atol(str.c_str());
			double div = this_i % n;
			if(div == 0){
				cout << str.size() << "\n";
				flag = true;
			}
			else{
				str += "1";
				flag = false;
			}
		}
	}
	*/	


}
