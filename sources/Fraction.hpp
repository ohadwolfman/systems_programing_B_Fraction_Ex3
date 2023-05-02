#ifndef FRACTION_HPP
#define FRACTION_HPP
#include <iostream>
#include <stdlib.h>
using namespace std;

namespace ariel{
    class Fraction{
        int _numerator;
        int _denominator;

    public:
        Fraction(): _numerator(0), _denominator(1){}
        // Constructor
        Fraction (const int numerator, const int denominator);
        // Copy constructor
        Fraction (const Fraction& copy) :
        _numerator(copy._numerator),
        _denominator(copy._denominator) {}
        Fraction (float f) : _numerator((int) f*1000), _denominator(1000) {}


        int getNumerator() const;
        int getDenominator() const;
        int gcd(int a, int b);
        Fraction reducedForm();


        // Arithmetic Operators
        // Operator +
        Fraction operator+(const Fraction& other);
        Fraction operator+(float num);
        friend Fraction operator+(const float num, const Fraction& f);

        // Operator -
        Fraction operator-(const Fraction& other);
        Fraction operator-(const float num);
        friend Fraction operator-(const float num, const Fraction& f);


        // Operator *
        Fraction operator*(const Fraction& other);
        Fraction operator*(const float other);
        friend Fraction operator*(const float num, const Fraction& f);


        // Operator /
        Fraction operator/(const Fraction& other);
        Fraction operator/(const float other);
        friend Fraction operator/(const float num, const Fraction& f);


        // prefix: ++n
        Fraction& operator++();
        //postfix n++
        Fraction operator++(int postfix);

        //prefix: --n
        Fraction& operator--();
        //postfix n--
        Fraction operator--(int postfix);


        // Comparison Operators
        // Operator ==
        bool operator==(const Fraction& other);
        bool operator==(const float other);
        friend bool operator==(const float num, const Fraction& f);


        // Operator <
        bool operator<(const Fraction& other);
        bool operator<(const float other);
        friend bool operator<(const float num, const Fraction& f);


        // Operator >
        bool operator>(const Fraction& other);
        bool operator>(const float other);
        friend bool operator>(const float num, const Fraction& f);


        // Operator <=
        bool operator<=(const Fraction& other);
        bool operator<=(const float other);
        friend bool operator<=(const float num, const Fraction& f);


        // Operator >=
        bool operator>=(const Fraction& other);
        bool operator>=(const float other);
        friend bool operator>=(const float num, const Fraction& f);


        // ioStream Operators
        // Operator <<
        friend ostream& operator<<(ostream& os, const Fraction& f);
        // Operator >>
        friend istream& operator>>(istream& ist, Fraction& frac);

//        // Conversion Operators
//        operator Fraction() const;
//        operator float() const;
//        operator string() const;
    };
}
#endif