#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class RationalDivisionByZero {
};

int64_t NOD(int64_t p, int64_t q);

class Rational {
private:
    int64_t p_ = 1;
    int64_t q_ = 1; // is maint64_tained to be positive

    void reduce()
    {
        int64_t sign = ( (p_ * q_ < 0) ? -1 : 1);
        p_ = abs(p_);
        q_ = abs(q_);
        int64_t nod = NOD(p_, q_);
        p_ /= nod;
        p_ *= sign;
        q_ /= nod;
    }

public:
    Rational() = default;
    Rational(int64_t p) {
        p_ = p;
    }
    Rational(int64_t p, int64_t q) {
        p_ = p;
        q_ = q;
        reduce();
    }
    explicit Rational(const string r) {
        char ChNumerator[6];
        char ChDenominator[6];
        ChNumerator[0] = ChDenominator[0] = '\0';
        int64_t L = r.size();
        int64_t flag = 1;
        int64_t j = 0;
        int64_t i;
        for (i = 0; i < L; ++i) {
            if (r[i] == '/') {
                ChNumerator[i] = '\0';
                flag = 2;
                continue;
            }
            ((flag == 1) ? ChNumerator[i] : ChDenominator[j++]) = r[i];
        }
        if (strlen(ChDenominator) == 0) {
            ChNumerator[i] = '\0';
        }
        ChDenominator[j] = '\0';

        p_ = atoi(ChNumerator);
        if (strlen(ChDenominator) != 0) {
            q_ = atoi(ChDenominator);
        }
        reduce();
    }


    int64_t getNumerator() const {
        return p_;
    }
    int64_t getDenominator() const {
        return q_;
    }

    void Print64_tRational() const {
        cout << p_;
        if (q_ != 1)
            cout << '/' << q_;
    }


};
bool operator==(Rational lhs, Rational rhs) {
    return (lhs.getNumerator() == rhs.getNumerator() && lhs.getDenominator() == rhs.getDenominator());
}
bool operator!=(Rational lhs, Rational rhs) {
    return (!(lhs == rhs));
}
bool operator<(Rational lhs, Rational rhs) {
    return (lhs.getNumerator() * rhs.getDenominator() < rhs.getNumerator() * lhs.getDenominator());
}
bool operator>=(Rational lhs, Rational rhs) {
    return (!(lhs < rhs));
}
bool operator>(Rational lhs, Rational rhs) {
    return (lhs.getNumerator() * rhs.getDenominator() > rhs.getNumerator() * lhs.getDenominator());
}
bool operator<=(Rational lhs, Rational rhs) {
    return (!(lhs > rhs));
}

Rational operator+(Rational lhs, Rational rhs) {
    int64_t p = 1;
    int64_t q = 1;
    p = lhs.getNumerator() * rhs.getDenominator() + rhs.getNumerator() * lhs.getDenominator();
    q = lhs.getDenominator() * rhs.getDenominator();
    return Rational(p, q);
}
Rational operator-(Rational lhs, Rational rhs) {
    int64_t p = 1;
    int64_t q = 1;
    p = lhs.getNumerator() * rhs.getDenominator() - rhs.getNumerator() * lhs.getDenominator();
    q = lhs.getDenominator() * rhs.getDenominator();
    return Rational(p, q);
}

Rational operator*(Rational lhs, Rational rhs) {
    int64_t p = 1;
    int64_t q = 1;
    p = lhs.getNumerator() * rhs.getNumerator();
    q = lhs.getDenominator() * rhs.getDenominator();
    return Rational(p, q);
}
Rational operator/(Rational lhs, Rational rhs) {
    int64_t p = 1;
    int64_t q = 1;
    if (rhs == 0) {
        throw RationalDivisionByZero();
    }
    p = lhs.getNumerator() * rhs.getDenominator();
    q = lhs.getDenominator() * rhs.getNumerator();
    return Rational(p, q);
}


Rational operator+(Rational lhs) {
    return lhs;
}
Rational operator-(Rational lhs) {
    return (-1) * lhs;
}

Rational& operator+=(Rational& lhs, Rational rhs) {
    lhs = lhs + rhs;
    return lhs;
}
Rational& operator-=(Rational& lhs, Rational rhs) {
    lhs = lhs - rhs;
    return lhs;

}
Rational& operator*=(Rational& lhs, Rational rhs) {
    lhs = lhs * rhs;
    return lhs;
}
Rational& operator/=(Rational& lhs, Rational rhs) {
    lhs = lhs / rhs;
    return lhs;
}

Rational operator++(Rational& lhs, int) {
    lhs += 1;
    return lhs - 1;
}
Rational& operator++(Rational& lhs) {
    lhs += 1;
    return lhs;
}
Rational operator--(Rational& lhs, int) {
    lhs -= 1;
    return lhs + 1;
}
Rational& operator--(Rational& lhs) {
    lhs -= 1;
    return lhs;
}

istream& operator>>(istream& is, Rational& r) {
    string r_str;
    is >> r_str;
    r = Rational(r_str);
    return is;
}
ostream& operator<<(ostream& os, Rational r) {
    r.Print64_tRational();
    return os;
}


int64_t NOD(int64_t p, int64_t q) {
    while (q != 0) {
        p %= q;
        swap(p, q);
    }
    return p;
}

int main() {
//    cout << Rational (-1111, 9);

    int64_t a;
    cin >> a;

    int64_t p, q;
    cin >> p >> q;
    const Rational rc(p, q); // q != 0 is guaranteed by author of tests
    cout << rc.getNumerator() << ' ' << rc.getDenominator() << endl;

    Rational r1, r2;
    cin >> r1 >> r2;

    cout << r1 << endl;
    cout << r2 << endl;

    try {
        cout << 1/r1 << endl;
    } catch (const RationalDivisionByZero& ex) {
        cout << "Cannot get reciprocal of r1." << endl;
    }

    try {
        cout << rc/r2 << endl;
    } catch (const RationalDivisionByZero& ex) {
        cout << "Cannot divide by r2." << endl;
    }

    cout << (r1 < r2) << endl;
    cout << (r1 <= r2) << endl;
    cout << (r1 > r2) << endl;
    cout << (r1 >= r2) << endl;
    cout << (r1 == r2) << endl;
    cout << (r1 != r2) << endl;

    cout << (r1 < a) << endl;
    cout << (r1 <= a) << endl;
    cout << (r1 > a) << endl;
    cout << (r1 >= a) << endl;
    cout << (r1 == a) << endl;
    cout << (r1 != a) << endl;

    cout << (a < r2) << endl;
    cout << (a <= r2) << endl;
    cout << (a > r2) << endl;
    cout << (a >= r2) << endl;
    cout << (a == r2) << endl;
    cout << (a != r2) << endl;

    cout << rc + a << endl
         << a + rc << endl
         << -rc * r1 << endl
         << (+r1 - r2 * rc) * a << endl;

    cout << ++r1 << endl;
    cout << r1 << endl;
    cout << r1++ << endl;
    cout << r1 << endl;
    cout << --r1 << endl;
    cout << r1 << endl;
    cout << r1-- << endl;
    cout << r1 << endl;
    cout << ++(++r1) << endl;
    cout << r1 << endl;

    cout << ((((r1 += r2) /= Rational(-5,3)) -= rc) *= a) << endl;
    cout << (r1 += r2 /= 3) << endl;
    cout << r1 << endl;
    cout << r2 << endl;
    return 0;

}