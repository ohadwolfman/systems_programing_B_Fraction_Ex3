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
        void reducedForm();

        // Arithmetic Operators
        // Operator +
        Fraction operator+(const Fraction& other) const;
        Fraction operator+(const float& num) const;

        // Operator -
        Fraction operator-(const Fraction& other) const;
        Fraction operator-(const float& num) const;

        // Operator *
        Fraction operator*(const Fraction& other) const;
        Fraction operator*(const float& other);

        // Operator /
        Fraction operator/(const Fraction& other) const;
        Fraction operator/(const float& other);

        // prefix: ++n
        Fraction& operator++();
        //postfix n++
        Fraction operator++(int dummy_flag_for_postfix_increment);

        //prefix: --n
        Fraction& operator--();
        //postfix n--
        Fraction operator--(int dummy_flag_for_postfix_increment);


        // Comparison Operators
        // Operator ==
        bool operator==(const Fraction& other) const;
        bool operator==(const float& other);

        // Operator <
        bool operator<(const Fraction& other) const;
        bool operator<(const float& other);

        // Operator >
        bool operator>(const Fraction& other) const;
        bool operator>(const float& other);

        // Operator <=
        bool operator<=(const Fraction& other) const;
        bool operator<=(const float& other);

        // Operator >=
        bool operator>=(const Fraction& other) const;
        bool operator>=(const float& other);

        // ioStream Operators
        // Operator <<
        friend ostream& operator<<(ostream& os, const Fraction& f);
        // Operator >>
        friend istream& operator>>(istream& is, Fraction& f);

        // Conversion Operators
        operator float() const;
        operator string() const;
    };
}
#endif