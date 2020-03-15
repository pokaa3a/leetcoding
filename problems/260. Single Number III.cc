#include <iostream>
using namespace std;

int main() {
	int a = 18;
	a &= -a;

	cout << a << endl;
}