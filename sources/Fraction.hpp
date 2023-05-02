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
        // Constructor
        Fraction (const int& numerator= 0, const int& denominator= 1);
        // Copy constructor
        Fraction (const Fraction& copy) :
        _numerator(copy._numerator),
        _denominator(copy._denominator) {}

        int getNumerator() const;
        int getDenominator() const;
        int gcd(int a, int b);
        Fraction reducedForm();


        // Arithmetic Operators
        // Operator +
        Fraction operator+(const Fraction& other) const;
        Fraction operator+(float& num) const;
        friend Fraction operator+(const float num, const Fraction& f);

        // Operator -
        Fraction operator-(const Fraction& other) const;
        Fraction operator-(const float& num) const;
        friend Fraction operator-(const float num, const Fraction& f);


        // Operator *
        Fraction operator*(const Fraction& other) const;
        Fraction operator*(const float& other);
        friend Fraction operator*(const float num, const Fraction& f);


        // Operator /
        Fraction operator/(const Fraction& other) const;
        Fraction operator/(const float& other);
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
        bool operator==(const Fraction& other) const;
        bool operator==(const float& other);
        friend bool operator==(const float num, const Fraction& f);


        // Operator <
        bool operator<(const Fraction& other) const;
        bool operator<(const float& other);
        friend bool operator<(const float num, const Fraction& f);


        // Operator >
        bool operator>(const Fraction& other) const;
        bool operator>(const float& other);
        friend bool operator>(const float num, const Fraction& f);


        // Operator <=
        bool operator<=(const Fraction& other) const;
        bool operator<=(const float& other);
        friend bool operator<=(const float num, const Fraction& f);


        // Operator >=
        bool operator>=(const Fraction& other) const;
        bool operator>=(const float& other);
        friend bool operator>=(const float num, const Fraction& f);


        // ioStream Operators
        // Operator <<
        friend ostream& operator<<(ostream& os, const Fraction& f);
        // Operator >>
        friend istream& operator>>(istream& is, Fraction& f);

        // Conversion Operators
        operator Fraction() const;
        operator float() const;
        operator string() const;
    };
}
#endif