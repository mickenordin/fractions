#include <iostream>
#include "fractions.hpp"


int main() {
	int a = 7;
	int b = 3;
	int c = 1;
	int d = 11;
	fraction q(a,b);
	fraction q2(c,d);
	cout << a << "/" << b << '=' << q << endl;
	cout << q << "+" << q2 << '=' << q + q2 << endl;
	cout << q << "-" << q2 << '=' << q - q2 << endl;
	cout << q << "*" << q2 << '=' << q * q2 << endl;
	cout << q << "/" << q2 << '=' << q / q2 << endl;
	return 0;
}
