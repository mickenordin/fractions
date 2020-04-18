#include <iostream>

using namespace std;

class fraction {
	private:
		int n, d;
		int gcd (int a, int b) const {
			if (a == 0) {
				return b;
			}
			if (b == 0) {
				return a;
			}
			if (a == b) {
				return a;
			}

			if (a > b) {
				return gcd(a-b, b);
			}

			return gcd(a, b-a);
		}
	public:
		// Constructors
		fraction(int a, int b) {
			int hcf = gcd(a,b);
			n = a / hcf;
			d = b / hcf;
		}
		fraction(const fraction &q) {
			int hcf = gcd(q.n,q.d);
			n = q.n / hcf;
			d = q.d / hcf;
		}
		// Operators
		fraction operator+(const fraction &that) {
			int numerator = this->n * that.d + that.n * this->d;
			int denominator = this->d * that.d;
			fraction q(numerator, denominator);
			return q;
		}
		fraction operator-(const fraction &that) {
			int numerator = this->n * that.d - that.n * this->d;
			int denominator = this->d * that.d;
			fraction q(numerator, denominator);
			return q;
		}
		fraction operator*(const fraction &that) {
			int numerator = this->n * that.n;
			int denominator = this->d * that.d;
			fraction q(numerator, denominator);
			return q;
		}
		fraction operator/(const fraction &that) {
                        fraction a(this->n,this->d);
			fraction b(that.d,that.n);	
			return a * b;
		}
		friend ostream &operator<<( ostream &os, const fraction &q ) { 
			if( q.d == q.n) {
				os << 1;
			} else {
				os << q.n << '/' << q.d;
			}
			return os;
		}
};
