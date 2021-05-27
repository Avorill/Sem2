#include <iostream>
using namespace std;
extern "C"  int __cdecl Arcsin(float x);
extern "C"  float __cdecl Calculate(float x, float eps);

int main() {
	//float x, eps;
	//float res = 0;
	//cout << ">> x ";
	//cin >> x;
	//cout << Arcsin(x) << endl;
	cout << Calculate(5, 0.2) << endl;


	return 0;
}

