#include "doctest.h"
#include "sources/Fraction.hpp"
using namespace std;
using namespace ariel;

TEST_CASE("Basic arithmetic operators actions") {
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    Fraction f3 = f1 + f2;
    CHECK((f3.getNumerator() == 5 && f3.getDenominator() == 4));
    f3 = f1 - f2;
    CHECK((f3.getNumerator() == -1 && f3.getDenominator() == 4));
    f3 = f1 * f2;
    CHECK((f3.getNumerator() == 3 && f3.getDenominator() == 8));
    f3 = f1 / f2;
    CHECK((f3.getNumerator() == 2 && f3.getDenominator() == 3));
}

TEST_CASE("Complex Fraction, Returns the reduced form"){
    Fraction a(23,10);
    Fraction b (18,5);
    CHECK((a+b == Fraction(59,10)));
    CHECK((a-b == Fraction(-13,10)));
    CHECK((a*b == Fraction(207,25)));
    CHECK((a/b == Fraction(23,36)));
    CHECK_FALSE((a<b));
    CHECK((a>b));
    CHECK((a*0 == Fraction(0,1)));
    a--;
    CHECK((a.getNumerator() == 13 && a.getDenominator() == 10));
    --a;
    CHECK((a.getNumerator() == 3 && a.getDenominator() == 10));
}

TEST_CASE("ostream works properly") {
    Fraction f1(1, 4);
    Fraction f2(8,4);
    Fraction f3 = f1 * f2;
    stringstream ss;
    ss << f3;
    CHECK(ss.str() == "1/2");
    ss << f1;
    CHECK(ss.str() == "1/4");
    f3 = f1*2 + f2;
    ss << f3;
    CHECK(ss.str() == "5/2");
    ss << f3;
    CHECK(ss.str() == "1/2");
}

TEST_CASE("Forbidden commands"){
    CHECK_THROWS(Fraction(4,0));
    CHECK_THROWS(Fraction(0,0));
    CHECK_THROWS(Fraction(4,7) / 0);
    CHECK_THROWS(Fraction(184523489223649,15));
}

TEST_CASE("Reducing properly"){
    CHECK(Fraction(18,30) == Fraction(3,5));
    CHECK(Fraction(30,18) == Fraction(5,3));
    CHECK(Fraction(7,4) == Fraction(7,4));
}
