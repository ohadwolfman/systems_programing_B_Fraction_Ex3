#include "Fraction.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
using namespace ariel;

Fraction::Fraction (const int numerator, const int denominator){
    if(denominator == 0) {
        throw invalid_argument("You cant select 0 as denominator");
    }
    if (_numerator > INT_MAX || _denominator > INT_MAX) {
        throw overflow_error("Too large number");
    }
    _numerator = numerator;
    _denominator = denominator;

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

int gcd(int a, int b) {  // https://www.tutorialspoint.com/cplusplus-program-to-find-gcd
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

Fraction Fraction::reducedForm(){
    int GCD = gcd(this->_numerator, this->_denominator);
    this->_numerator = this->_numerator / GCD;
    this->_denominator = this->_denominator / GCD;
    return *this;
}

// Arithmetic Operators
// Operator +
Fraction Fraction::operator+(const Fraction& other) {
    Fraction f ((_numerator*other._denominator) + (_denominator * other._numerator),
                          _denominator * other._denominator);
    f.reducedForm();
    return f;
}
Fraction Fraction::operator+(float num) {
    return Fraction(1,1);
}
Fraction operator+(float num, const Fraction& f){
    return Fraction(1,1);
}

// Operator -
Fraction Fraction::operator-(const Fraction& other){
    int nn = _numerator * other._denominator - _denominator * other._numerator;
    int dd = _denominator * other._denominator;
    return Fraction(nn, dd).reducedForm();
}
Fraction Fraction::operator-(float num) {
    return Fraction(1,1);
}
Fraction operator-(float num, const Fraction& f){
    return Fraction(1,1);
}

// Operator *
Fraction Fraction::operator*(const Fraction& other){
    int numerator = _numerator * other._numerator;
    int denominator = _denominator * other._denominator;
    return Fraction(numerator, denominator);
}
Fraction Fraction::operator*(const float other){
    int numerator = _numerator * other;
    return Fraction(numerator, _denominator);
}
Fraction operator*(float num, const Fraction& f){
    return Fraction(1,1);
}

// Operator /
Fraction Fraction::operator/(const Fraction& other){
    int numerator = _numerator * other._denominator;
    int denominator = _denominator * other._numerator;
    return Fraction(numerator, denominator);
}
Fraction Fraction::operator/(const float other){
    int numerator = _numerator * other;
    return Fraction(numerator, _denominator);
}
Fraction operator/(float num, const Fraction& f){
    return Fraction(1,1);
}

// prefix: ++n
Fraction& Fraction::operator++(){
    _numerator += this->_denominator;
    return *this;
}
//postfix n++
Fraction Fraction::operator++(int postfix){
    Fraction temp = *this; // create a copy of the current object
    _numerator += _denominator; // call the prefix increment operator to perform the actual increment
    return temp; // return the copy of the original value
}

//prefix: --n
Fraction& Fraction::operator--(){
    _numerator -= this->_denominator;
    return *this;

}
//postfix n--
Fraction Fraction::operator--(int postfix){
    Fraction temp = *this; // create a copy of the current object
    _numerator -= _denominator; // call the prefix increment operator to perform the actual increment
    return temp;
}


// Comparison Operators
// Operator ==
bool Fraction::operator==(const Fraction& other){
    return (_numerator == other._numerator) && (_denominator == other._denominator);
}
bool Fraction::operator==(const float other){return true;}
bool operator==(const float num, const Fraction& f){return true;}

// Operator <
bool Fraction::operator<(const Fraction& other){
    int numerator = _numerator * other._denominator;
    int other_numerator = other._numerator * _denominator;
    return numerator < other_numerator;
}
bool Fraction::operator<(const float other){return true;}
bool operator<(const float num, const Fraction& f){return true;}

// Operator >
bool Fraction::operator>(const Fraction& other){
    int numerator = _numerator * other._denominator;
    int other_numerator = other._numerator * _denominator;
    return numerator > other_numerator;
}
bool Fraction::operator>(const float other){return true;}
bool operator>(const float num, const Fraction& f){return true;}

// Operator <=
bool Fraction::operator<=(const Fraction& other){
    int numerator = _numerator * other._denominator;
    int other_numerator = other._numerator * _denominator;
    return numerator >= other_numerator;
}
bool Fraction::operator<=(const float other){return true;}
bool operator<=(const float num, const Fraction& f){return true;}

// Operator >=
bool Fraction::operator>=(const Fraction& other){
    int numerator = _numerator * other._denominator;
    int other_numerator = other._numerator * _denominator;
    return numerator >= other_numerator;
}
bool Fraction::operator>=(const float other){return true;}
bool operator>=(const float num, const Fraction& f){return true;}


// ioStream Operators
// Operator <<
ostream& operator<<(ostream& os, const Fraction& f){
    os << f.getNumerator() <<'/' << f.getDenominator();
    return os;
}

// Operator >>
istream& operator>>(istream& is, Fraction& f) {
    int numerator, denominator;
    char slash;

    is >> numerator >> slash >> denominator;

    if (denominator == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    f = Fraction(numerator, denominator);
    return is;
}

//// Conversion operator to convert a float to Fraction object
//Fraction::operator Fraction(float f) const {
//    int den = 1000; // maximum of 3 digits after the decimal point
//    int num = round(f * den);
//    int gcd_val = gcd(num, den);
//    num /= gcd_val;
//    den /= gcd_val;
//    return Fraction(num, den);
//}
//// Conversion operator to convert a Fraction object to float
//Fraction::operator float() const {
//    return float(_numerator) / float(_denominator);
//}
//
//// Conversion operator to convert a Fraction object to a string
//Fraction::operator string() const {
//    std::ostringstream output;
//    output << _numerator << "/" << _denominator;
//    return output.str();
////    return to_string(_numerator) + "/" + to_string(_denominator);
//}