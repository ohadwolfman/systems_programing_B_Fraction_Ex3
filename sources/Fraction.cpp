#include "Fraction.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;
using namespace ariel;

Fraction::Fraction (const int& numerator= 0, const int& denominator= 1):
        _numerator(numerator),
        _denominator(denominator) {
    if(denominator == 0) {
        throw invalid_argument("You cant select 0 as denominator")
    }
    if (numerator > INT_MAX || denominator > INT_MAX) {
        throw overflow_error("Too large number");
    }
    if (denominator < 0) {
        _numerator = -1 * numerator;
        _denominator = abs(denominator);
    }
    reducedForm();
}

int Fraction::getNumerator() const{
    return this->_numerator;
}
int Fraction::getDenominator() const{
    return this->_denominator;
}

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void Fraction::reducedForm(){
    int GCD = gcd(this->_numerator, this->_denominator);
    this->_numerator = this->_numerator / GCD;
    this->_denominator = this->_denominator / GCD;
}

Fraction Fraction::operator+(const Fraction& other) const {
    Fraction f = Fraction((this->_numerator*other._denominator) + (this->_denominator*other._numerator),
                          this->_denominator*other._denominator);
    return f.reducedForm();
}
Fraction Fraction::operator-(const Fraction& other) const{
    int nn = _numerator * other._denominator - _denominator * other._numerator;
    int dd = _denominator * other._denominator;
    return Fraction(nn, dd).reducedForm();
}
Fraction Fraction::operator*(const Fraction& other) const{
    return Fraction(1,1);
}
Fraction Fraction::operator*(const float other) const{
    return Fraction(1,1);
}
Fraction Fraction::operator/(const Fraction& other) const{
    return Fraction(1,1);
}
bool Fraction::operator==(const Fraction& other) const{
    return false;
}
bool Fraction::operator<(const Fraction& other) const{
    return false;
}
bool Fraction::operator>(const Fraction& other) const{
    return false;
}
bool Fraction::operator<=(const Fraction& other) const{
    return false;
}
bool Fraction::operator>=(const Fraction& other) const{
    return false;
}
Fraction& Fraction::operator++(){
    return Fraction(1,1);
}
Fraction Fraction::operator++(int dummy_flag_for_postfix_increment){
    return Fraction(1,1);
}
Fraction& Fraction::operator--(){
    return Fraction(1,1);

}
Fraction Fraction::operator--(int dummy_flag_for_postfix_increment){
    return Fraction(1,1);

}
friend ostream& Fraction::operator<<(ostream& os, const Fraction& f){
    os << f._numerator <<'/' << f._denominator;
    return os;
}

friend istream& operator>>(istream& is, Fraction& f) {
    int numerator, denominator;
    char slash;

    is >> numerator >> slash >> denominator;

    if (denominator == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    f = Fraction(numerator, denominator);
    return is;
}

operator float() const {              // conversion operator
    cout << "converting Fraction to float" << endl;
    return float(numerator) / float(denominator);
}

operator string() const {              // conversion operator
    return to_string(numerator)+"/"+to_string(denominator);
}