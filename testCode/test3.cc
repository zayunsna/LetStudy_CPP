#include "/home/icegpu/HK/HKTool.h"
#include <utility>
using namespace std;

void test3(){

	pair<int,int> paired;
	tuple<int, int, int> tuples;
	int a, b, c;

	paired = make_pair(1, 2);
	tuples = make_tuple(1,2,3);

	tie(a,b) = paired;
	cout << a << " : " << b << "\n";

	tie(a,b,c) = tuples;
	cout << a << " : " << b << " : " << c << "\n";

	vector< pair<double, double> > test_vec;
	pair<double, double> paired2;
	TRandom3 rndm;
	for(int i = 0; i < 10; ++i){
		paired2 = make_pair(i*rndm.Gaus(), i*rndm.Uniform());
		test_vec.push_back( paired2 );
	}

	int size = test_vec.size();

	double aa, bb;
	for(int i = 0; i < size; ++i){
		tie(aa, bb) = test_vec[i];
		cout << aa << " : " << bb << "\n";

	}

}
