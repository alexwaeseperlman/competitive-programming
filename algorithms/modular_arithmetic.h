#include <iostream>
#include <functional>

namespace number_theory {
	using namespace std;
	using ull = unsigned long long;
	using ll = long long;

	struct gcd  {
		ll a, b, gcd;
	};
	gcd extended_euclidean(gcd old = {1, 0, -1}, gcd out = {0, 1, -1}) {
		if (out.gcd == 0) return old;

		ll q = old.gcd / out.gcd;

		return extended_euclidean({out.a, out.b, out.gcd}, {old.a - q*out.a, old.b-q*out.b, old.gcd-q*out.gcd});
	}
	gcd extended_euclidean(ll a, ll b) {
		return extended_euclidean({1, 0, a}, {0, 1, b});
	}

	template<typename Child>
	class field {
	public:
		virtual Child operator-() const = 0;
		virtual Child operator+(const Child &rhs) const = 0;
		virtual Child operator*(const Child &rhs) const = 0;
		virtual Child& operator=(const Child &rhs) = 0;
		virtual bool operator==(const Child &rhs) const = 0;
		virtual Child inverse() const = 0;
		virtual Child mult_identity() const = 0;
		virtual Child add_identity() const = 0;

		template<typename T>
		Child operator-(const T &rhs) const {
			return *this + (Child)(-rhs);
		}

		template<typename T>
		Child& operator+=(const T &rhs) {
			return *this = (*this + rhs);
		}
		template<typename T>
		Child& operator-=(const T &rhs) {
			return *this = (*this - rhs);
		}
		template<typename T>
		Child& operator*=(const T &rhs) {
			return *this = (*this * rhs); 
		}


		// Modular exponent using repeated squaring
		virtual Child pow(const ll &rhs) const {
			if (rhs == 0) return mult_identity();
			
			ll e = 1;
			Child out = static_cast<const Child&>(*this);

			while (2*e <= rhs) {
				out *= out;
				e *= 2;
			}

			return out * (pow(rhs-e));
		}
	};

	class mod_int: public field<mod_int> {
	private:
		ll val, base;
	public:
		static inline ll default_base{10};
		ll get_base() {
			return base;
		}

		mod_int& set_base(ll b) {
			base = b;
			return *this;
		}

		mod_int& in_base(ll b) {
			mod_int out(*this);
			return out.set_base(b);
		}

		ll get_val() const {
			return val;
		}

		mod_int(ll x, ll base): base(base) {
			default_base = base;
			val = ((x % base) + base) % base;
		}

		mod_int(ll x) {
			base = default_base;
			val = ((x%base)+base)%base;
		}

		bool operator==(const mod_int &rhs) const override {
			return rhs.val == val;
		}

		mod_int& operator=(const mod_int &rhs) override { return (*this) = rhs.val%base; };
		mod_int operator+(const mod_int &rhs) const override { return mod_int(val+rhs.val, base); }
		mod_int operator*(const mod_int &rhs) const override { return mod_int(val*rhs.val, base); }
		mod_int inverse() const override {
			gcd g = extended_euclidean(val, base);
			if (g.gcd != 1) return mod_int(0, base);
			else return mod_int(g.a, base);
		}
		mod_int mult_identity() const override {
			return mod_int(1, base);
		}
		mod_int add_identity() const override {
			return mod_int(0, base);
		}
		mod_int operator-() const override {
			return mod_int(base - val, base);
		}

		mod_int operator-(const mod_int &rhs) const {
			return *this + (-rhs);
		}

		mod_int& operator=(const ll &rhs) {
			val = rhs%base;
			return *this;
		}
		
		mod_int& operator++() {
			*this = (*this + 1ll);
			return *this;
		}
		mod_int operator++(int) {
			ll old = val;
			*this = (*this + 1ll);
			return mod_int(old, base);
		}

		// Assumes the base is prime
		bool is_residue() const {
			return pow((base-1)/2) == 1ll;
		}

		// https://en.wikipedia.org/wiki/Cipolla%27s_algorithm
		mod_int sqrt() const; 
		friend ostream& operator<<(ostream &os, const mod_int &i) {
			return os << i.val << " (mod " << i.base << ")";
		}
	};

	template<typename Child>
	class complex_field: public field<complex_field<Child>> {
	private:
		Child real, imag, i2;
	public:
		static inline Child default_i2{0ll};
		complex_field(Child real, Child imag, Child i2): real(real), imag(imag), i2(i2) {
			default_i2 = Child(i2);
		};
		complex_field(Child real): i2(default_i2), imag(real.add_identity()), real(real) {}

		Child get_real() const { return real; }
		Child get_imag() const { return imag; }
		Child get_i() const { return i2; }

		bool operator==(const complex_field &rhs) const override {
			return real == rhs.real && imag == rhs.imag && i2 == rhs.i2;
		}
		complex_field operator*(const complex_field &rhs) const override {
			complex_field out(*this);
			out.real = real * rhs.real + imag * rhs.imag * i2;
			out.imag = real * rhs.imag + imag * rhs.real;
			return out;
		}
		complex_field operator*(const Child &rhs) const {
			complex_field out(*this);
			out.real = rhs * real;
			out.imag = rhs * imag;
			return out;
		}

		complex_field operator+(const complex_field &rhs) const override {
			complex_field out(*this);
			out.real = real + rhs.real;
			out.imag = imag + rhs.imag;
			return out;
		}
		complex_field operator+(const Child &rhs) const {
			complex_field out(*this);
			out.real = real + rhs;
			out.imag = imag;
			return out;
		}

		complex_field operator-() const override {
			complex_field out(*this);
			out.real = -real;
			out.imag = -imag;
			return out;
		}
		complex_field& operator=(const complex_field &rhs) override {
			real = rhs.real;
			imag = rhs.imag;
			i2 = rhs.i2;
			return *this;
		}
		complex_field mult_identity() const override {
			complex_field out(*this);
			out.real = real.mult_identity();
			out.imag = real.add_identity();
			return out;
		}
		complex_field add_identity() const override {
			complex_field out(*this);
			out.real = real.add_identity();
			out.imag = real.add_identity();
			return out;
		}
		complex_field inverse() const override {
			complex_field out(*this);
			out.real = real;
			out.imag = imag * i2;
			out *= (real*real + imag*imag).inverse();
			return out;
		}
	};

	mod_int mod_int::sqrt() const {
		//using f = pair<mod_int, mod_int>;
		if (val == 0) return mod_int(0, base);
		mod_int a(2, base);
		while ((a*a - val).is_residue()) {
			a++;
		}
		complex_field<mod_int> w(a, mult_identity(), a*a - val);
		mod_int out = w.pow((base+1)/2).get_real();
		return (out.val * 2 > base) ? -out : out;
	}

}
