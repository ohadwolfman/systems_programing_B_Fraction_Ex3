#include "Fraction.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
namespace ariel {

    Fraction::Fraction(int numerator, int denominator) {
        if (denominator == 0) {
            throw invalid_argument("Denominator can't be zero");
        }
        if ((numerator > INT_MAX) || (denominator > INT_MAX ) || (numerator < INT_MIN) || (denominator  < INT_MIN)) {
            throw overflow_error("The numbers must be in the Integer's range");
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

    void Fraction::setNumerator(int numerator){
        this->_numerator = numerator;
    }

    void Fraction::setDenominator(int denominator){
        this->_denominator=denominator;
    }

    int Fraction::gcd(int a, int b) {  // https://www.tutorialspoint.com/cplusplus-program-to-find-gcd
        a = abs(a);
        b = abs(b);
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
    Fraction Fraction::operator+(const Fraction &frac) {
        long numerator = long(_numerator * frac._denominator) + long(_denominator * frac._numerator);
        long denominator = long(_denominator * frac._denominator);
        if (numerator > INT_MAX || denominator > INT_MAX || numerator < INT_MIN || denominator< INT_MIN) {
            throw overflow_error("Overflow, Fraction can contain only numbers in the Integer's range ");
        }

        Fraction f((_numerator * frac._denominator) + (_denominator * frac._numerator),
                   _denominator * frac._denominator);
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
        long longNumerator = long(_numerator * frac._denominator) - long(_denominator * frac._numerator);
        long longDenominator = long(_denominator * frac._denominator);
        if (longNumerator > INT_MAX || longDenominator > INT_MAX || longNumerator < INT_MIN || longDenominator< INT_MIN) {
            throw overflow_error("Overflow, Fraction can contain only numbers in the Integer's range ");
        }

        int numerator = _numerator * frac._denominator - _denominator * frac._numerator;
        int denominator = _denominator * frac._denominator;
        return Fraction(numerator, denominator).reducedForm();
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
        long longNumerator = long(_numerator) * frac._numerator;
        long longDenominator = long(_denominator) * frac._denominator;

        if ((longNumerator > INT_MAX) || (longNumerator < INT_MIN) || (longDenominator > INT_MAX) || (longDenominator < INT_MIN)) {
            throw overflow_error("Overflow, Fraction can contain only numbers in the Integer's range ");
        }

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
        if (frac._numerator == 0)
            throw runtime_error("You can't divide by zero");

        long longNumerator = long(_numerator) * frac._denominator;
        long longDenominator = long(_denominator) * frac._numerator;

        if ((longNumerator > INT_MAX) || (longNumerator < INT_MIN) || (longDenominator > INT_MAX) || (longDenominator < INT_MIN)) {
            throw overflow_error("Overflow, Fraction can contain only numbers in the Integer's range ");
        }

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
        ist >> frac._numerator >> frac._denominator;
        if(!ist)
            throw runtime_error("Invalid input");

        if (frac._denominator < 0) {
            frac._numerator = -1*frac._numerator;
            frac._denominator = abs(frac._denominator);
        }
        if (frac._denominator == 0)
            throw runtime_error("Denominator can't be zero");

        if (frac._numerator == 0)
            frac._denominator = 1;

        return ist;
    }
}