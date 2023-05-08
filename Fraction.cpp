#include "Fraction.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
namespace ariel {

    Fraction::Fraction(int numerator, int denominator) {
        if (denominator == 0) {
            throw invalid_argument("You cant choose 0 as denominator");
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

    Fraction::Fraction(float num) {
        Fraction temp = Fraction(int(1000*num),1000);
        this->_numerator = temp.getNumerator();
        this->_denominator = temp.getDenominator();
        reducedForm();
    }


    int Fraction::getNumerator() const {
        return this->_numerator;
    }

    int Fraction::getDenominator() const {
        return this->_denominator;
    }

    int Fraction::gcd(int a, int b) {  // https://www.tutorialspoint.com/cplusplus-program-to-find-gcd
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    Fraction Fraction::reducedForm() {
        int GCD = gcd(this->_numerator, this->_denominator);
        this->_numerator /= GCD;
        this->_denominator /= GCD;
        return *this;
    }

// Arithmetic Operators
// Operator +
    Fraction Fraction::operator+(const Fraction &other) {
        Fraction f((_numerator * other._denominator) + (_denominator * other._numerator),
                   _denominator * other._denominator);
        f.reducedForm();
        return f;
    }

    Fraction Fraction::operator+(const float& num) {
        Fraction temp =Fraction(num);
        temp = temp + *this;
        return temp.reducedForm();
    }

    Fraction operator+(const float& num, const Fraction &frac) {
        Fraction temp = Fraction(int(num*1000),1000);
        return (temp + frac).reducedForm();

    }

// Operator -
    Fraction Fraction::operator-(const Fraction &frac) {
        int nn = _numerator * frac._denominator - _denominator * frac._numerator;
        int dd = _denominator * frac._denominator;
        return Fraction(nn, dd).reducedForm();
    }

    Fraction Fraction::operator-(const float& num) {
        Fraction temp = Fraction(num);
        temp = (*this) - temp;
        return temp.reducedForm();
    }

    Fraction operator-(const float& num, const Fraction& frac) {
        Fraction temp = Fraction(num);
        return (temp - frac).reducedForm();
    }

// Operator *
    Fraction Fraction::operator*(const Fraction &frac) {
        int numerator = _numerator * frac._numerator;
        int denominator = _denominator * frac._denominator;
        return Fraction(numerator, denominator);
    }

    Fraction Fraction::operator*(const float& num) {
        Fraction temp = Fraction(num);
        temp = temp * (*this);
        return temp.reducedForm();
    }

    Fraction operator*(const float& num, const Fraction& frac) {
        Fraction temp = Fraction(num);
        temp = temp * frac;
        return temp.reducedForm();
    }

// Operator /
    Fraction Fraction::operator/(const Fraction &frac) {
        int numerator = _numerator * frac._denominator;
        int denominator = _denominator * frac._numerator;
        return Fraction(numerator, denominator);
    }

    Fraction Fraction::operator/(const float& num) {
        Fraction temp = Fraction(num);
        temp = *this/ temp;
        return temp.reducedForm();
    }

    Fraction operator/(const float& num, const Fraction &frac) {
        Fraction temp = Fraction(num);
        return (temp / frac).reducedForm();
    }

// prefix: ++n
    Fraction &Fraction::operator++() {
        _numerator += this->_denominator;
        return *this;
    }

//postfix n++
    Fraction Fraction::operator++(int postfix) {
        Fraction temp = *this; // create a copy of the current object
        _numerator += _denominator; // call the prefix increment operator to perform the actual increment
        return temp; // return the copy of the original value
    }

//prefix: --n
    Fraction &Fraction::operator--() {
        _numerator -= this->_denominator;
        return *this;
    }

//postfix n--
    Fraction Fraction::operator--(int postfix) {
        Fraction temp = *this; // create a copy of the current object
        _numerator -= _denominator; // call the prefix increment operator to perform the actual increment
        return temp;
    }


// Comparison Operators
// Operator ==
    bool Fraction::operator==(const Fraction &frac) const{
        int left = _numerator * frac._denominator;
        int right = _denominator * frac._numerator;
        return left == right;
    }

    bool Fraction::operator==(const float& num) const {
        Fraction temp = Fraction(num);
        return (*this) == temp;
    }

    bool operator==(const float& num, const Fraction &frac) {
        Fraction temp =Fraction(num);
        return (temp==frac);
    }

// Operator <
    bool Fraction::operator<(const Fraction &frac) const{
        int left = _numerator * frac._denominator;
        int right = _denominator * frac._numerator;
        return left < right;
    }

    bool Fraction::operator<(const float& num) const{
        Fraction temp = Fraction(num);
        return (*this) < temp;
    }

    bool operator<(const float& num, const Fraction &frac){
        Fraction temp =Fraction(num);
        return (temp < frac);
    }

// Operator >
    bool Fraction::operator>(const Fraction &frac) const {
        int left = _numerator * frac._denominator;
        int right = _denominator * frac._numerator;
        return left > right;
    }

    bool Fraction::operator>(const float& num) const{
        Fraction temp = Fraction(num);
        return (*this) > temp;
    }

    bool operator>(const float& num, const Fraction& frac){
        Fraction temp = Fraction(num);
        return (temp > frac);
    }

// Operator <=
    bool Fraction::operator<=(const Fraction &frac) const{
        int left = _numerator * frac._denominator;
        int right = _denominator * frac._numerator;
        return left <= right;
    }

    bool Fraction::operator<=(const float& num) const{
        Fraction temp = Fraction(num);
        return (*this) <= temp;
    }

    bool operator<=(const float& num, const Fraction &frac) {
        Fraction temp = Fraction(num);
        return (temp <= frac);
    }

// Operator >=
    bool Fraction::operator>=(const Fraction &frac) const{
        int left = _numerator * frac._denominator;
        int right = _denominator * frac._numerator;
        return left >= right;
    }

    bool Fraction::operator>=(const float& num) const{
        Fraction temp = Fraction(num);
        return (*this) >= temp;
    }

    bool operator>=(const float& num, const Fraction &frac) {
        Fraction temp =Fraction(num);
        return (temp >= frac);
    }


// ioStream Operators
// Operator <<
    ostream &operator<<(ostream &ost, const Fraction &frac) {
        ost << frac.getNumerator() << '/' << frac.getDenominator();
        return ost;
    }

// Operator >>
    istream &operator>>(istream& ist, Fraction& frac) {
        if(!ist)
            throw runtime_error("error : invalid input");

        int numerator = 0, denominator = 0;
        ist >> numerator >> denominator;

        if (denominator == 0) {
            throw runtime_error("Denominator cannot be zero");
        }
        char slash = '/';

        ist >> numerator >> slash >> denominator;

        if (denominator == 0) {
            throw std::invalid_argument("Denominator cannot be zero");
        }
        frac = Fraction(numerator, denominator);
        return ist;
    }


//// Conversion operator to convert a Fraction object to a string
//Fraction::operator string() const {
//    std::ostringstream output;
//    output << _numerator << "/" << _denominator;
//    return output.str();
////    return to_string(_numerator) + "/" + to_string(_denominator);
//}
}