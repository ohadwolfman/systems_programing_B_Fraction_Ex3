#include "doctest.h"
#include "sources/Fraction.hpp"
using namespace std;
using namespace ariel;

TEST_CASE("Returns the reduced form"){
    Fraction a = 23/10
    Fraction b = 18/5;
    CHECK((a+b == 59/10));
    CHECK((a-b == -13/10));
    CHECK((a*b == ));
    CHECK((a/b == ));
    CHECK((a<b == ));
    CHECK((a>b == ));
    CHECK_MESSAGE(a==b ,"false");

}

TEST_CASE("") {
    CHECK("");
    CHECK_NOTHROW();
}