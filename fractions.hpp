#include <iostream>
#include <string>

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
		int get_precision(double a) {
			string s = to_string(a);
			bool dec = false;
			int count = 0;
			for(int i = 0; i < s.length(); i++) {
				if(s[i] == '.') {
					dec = true;
				} else {
					if(dec) {
						count++;
					}
				}
			}
			return count;
		}
	public:
		// Constructors
		fraction() {
			n = 0;
			d = 1;
		}
		fraction(int a, int b) {
			int hcf = gcd(a,b);
			n = a / hcf;
			d = b / hcf;
		}
		fraction(int a) {
			n = a;
			d = 1;
		}
		fraction(double dec) {
			int precision = get_precision(dec);
			int denominator = 1;
			for(int i = 0; i < precision; i++) {
				denominator *= 10;
			}
			int numerator = dec * denominator;
			int hcf = gcd(numerator,denominator);
			n = numerator / hcf;
			d = denominator / hcf;
		}
		fraction(const fraction &q) {
			int hcf = gcd(q.n,q.d);
			n = q.n / hcf;
			d = q.d / hcf;
		}
		// Member functions
		bool sign() const {
			return (n >= 0);
		}
		// Operators
		fraction operator+(const fraction &that) const {
			int numerator = this->n * that.d + that.n * this->d;
			int denominator = this->d * that.d;
			fraction q(numerator, denominator);
			return q;
		}
		fraction operator-(const fraction &that) const {
			int numerator = this->n * that.d - that.n * this->d;
			int denominator = this->d * that.d;
			fraction q(numerator, denominator);
			return q;
		}
		fraction operator*(const fraction &that) const {
			int numerator = this->n * that.n;
			int denominator = this->d * that.d;
			fraction q(numerator, denominator);
			return q;
		}
		fraction operator*(const int i) const {
			fraction a(i);
			fraction q(*this * a);
			return q;
		}
		fraction operator/(const fraction &that) const {
                        fraction a(this->n,this->d);
			fraction b(that.d,that.n);	
			return a * b;
		}
		friend ostream &operator<<( ostream &os, const fraction &q ) { 
			if( q.d == q.n) {
				os << 1;
			} else if(q.d == 1) {
				os << q.n;
			} else {
				os << q.n << '/' << q.d;
			}
			return os;
		}
		void operator=(const fraction &q ) {
			n = q.n;
			d = q.n;
		}
		void operator=(const int i ) {
			n = i;
			d = 1;
		}
		void operator=(const double dec ) {
			const fraction q(dec);
			*this = q;
		}
		bool operator>(const fraction &q ) const {
			int hcf = gcd(d,q.d);
			fraction a(*this * hcf);
			fraction b(q * hcf);
			return (a.n > b.n);
		}
		bool operator>(const int i ) const {
			fraction q(i);
			return (*this > q);
		}
		bool operator==(const fraction &q ) const {
			return ((n == q.n) && (d == q.d));
		}
		bool operator==(const int i) const {
			return ((n == i) && (d == 1));
		}
		bool operator==(const double dec) const {
			fraction a(dec);
			return ((n == a.n) && (d == a.d));
		}
		bool operator!=(const fraction &q ) const {
			return ((n != q.n) || (d != q.d));
		}
		bool operator!=(const int i) const {
			return ((n != i) || (d != 1));
		}
		bool operator!=(const double dec) const {
			fraction a(dec);
			return ((n != a.n) || (d != a.d));
		}
};
