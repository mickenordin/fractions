#include <iostream>
#include <string>

using namespace std;

class fraction {
	private:
		signed long long n = 0;
		signed long long d = 1;
		signed long long gcd (signed long long a, signed long long b) const {
			if (b == 0) {
				return a;
			}
			return gcd(b, a % b);
		}
		int get_precision(double a) {
			string s = to_string(a);
			int i = s.length() - 1;
			while (s[i] == '0'){
				i--;
			}
			s.erase(i+1,s.length());
			bool point = false;
			int count = 0;
			for(int i = 0; i < s.length(); i++) {
				if(s[i] == '.') {
					point = true;
				} else {
					if(point) {
						count++;
					}
				}
			}
			return count;
		}
	public:
		// Constructors
		fraction() {
		}
		fraction(const fraction &q) {
			signed long long hcf = gcd(q.n,q.d);
			n = q.n / hcf;
			d = q.d / hcf;
		}
		fraction(signed long long a, signed long long b) {
			signed long long hcf = gcd(a,b);
			n =  a / hcf;
			d =  b / hcf;
		}
		fraction(int a, int b) {
			signed long long hcf = gcd(a,b);
			n = (signed long long) a  / hcf;
			d = (signed long long) b / hcf;
		}
		fraction(int a) {
			fraction q(a, 1);
			n = q.n;
			d = q.d;
		}
		fraction(double dec) {
			if(dec < 0) {
				dec = dec * (double) -1;
			}
			int precision = get_precision(dec);
			signed long long denominator = 1;
			for(int i = 0; i < precision; i++) {
				denominator *= 10;
			}
			signed long long numerator = dec * denominator;
			fraction q(numerator, denominator);
			n = q.n;
			d = q.d;
		}
		// Member functions
		int get_sign() const {
			return (!(n >= 0) != !(d >=0)) ? -1 : 1;
		}
		signed long long get_n() const {
			return n;
		}
		signed long long get_d() const {
			return d;
		}
		double to_double() const {
			double dec = (double) n / (double) d ;
			return dec;
		}
		// Operators
		fraction operator+(const fraction &that) const {
			signed long long numerator = this->n * that.d + that.n * this->d;
			signed long long denominator = this->d * that.d;
			fraction q(numerator, denominator);
			return q;
		}
		fraction operator-(const fraction &that) const {
			signed long long numerator = this->n * that.d - that.n * this->d;
			signed long long denominator = this->d * that.d;
			fraction q(numerator, denominator);
			return q;
		}
		fraction operator*(const fraction &that) const {
			signed long long numerator = this->n * that.n;
			signed long long denominator = this->d * that.d;
			fraction q(numerator, denominator);
			return q;
		}
		fraction operator*(const int i) const {
			signed long long numerator = this->n * i;
			signed long long denominator = this->d;
			fraction q(numerator, denominator);
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
				os << '(' << q.n << '/' << q.d << ')';
			}
			return os;
		}
		void operator=(const fraction &q ) {
			n = q.n;
			d = q.d;
		}
		void operator=(const int i ) {
			n = (signed long long) i;
			d = (signed long long) 1;
		}
		void operator=(const double dec ) {
			const fraction q(dec);
			n = q.n;
			d = q.d;
		}
		bool operator>(const fraction &q ) const {
			signed long long hcf = gcd(d,q.d);
			fraction a(*this * hcf);
			fraction b(q * hcf);
			return (a.n > b.n);
		}
		bool operator>(const int i ) const {
			fraction q(i);
			return (*this > q);
		}
		bool operator==(const fraction &q ) const {
			return ((n == q.n) && (d == q.d) );
		}
		bool operator==(const int i) const {
			fraction q(i);
			return (*this == q);
		}
		bool operator==(const double dec) const {
			fraction q(dec);
			return (*this == q);
		}
		bool operator!=(const fraction &q ) const {
			return ( (n != q.n) || (d != q.d) );
		}
		bool operator!=(const int i) const {
			fraction q(i);
			return (*this != q);
		}
		bool operator!=(const double dec) const {
			fraction q(dec);
			return (*this != q);
		}
};
