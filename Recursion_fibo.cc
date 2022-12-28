#include "/home/icegpu/HK/HKTool.h"
using namespace std;

int fact(int n){
	if(n == 1 || n == 0) return 1;
	return n * fact(n - 1);
}

int fact1(int n){
	int ret = 1;
	for(int i = 1; i <= n; ++i){
		ret *= i;
	}
	return ret;
}

int fibo(int n){
	cout << "fibo : " << n << "\n";
	if(n == 0 || n == 1) return n;
	int a = fibo(n-1);
	int b = fibo(n-2);
	int result = a+b;
	cout << " result : " << result << " = " << a << " + " << b << "\n";
	return result;
}
int n = 6;
void Recursion_fibo(){

	cout << fibo(n) << "\n";

}
