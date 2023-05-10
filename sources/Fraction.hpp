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
        // Constructors
        Fraction(): _numerator(0), _denominator(1){}
        Fraction (int numerator, int denominator);
        Fraction(float num);

        int getNumerator() const;
        int getDenominator() const;
        void setNumerator(int numerator);
        void setDenominator(int denominator);
        int gcd(int first, int second);
        Fraction reducedForm();


        // Arithmetic Operators
        // Operator +
        Fraction operator+(const Fraction& other);
        Fraction operator+(const float& num);
        friend Fraction operator+(const float& num, const Fraction& frac);

        // Operator -
        Fraction operator-(const Fraction& other);
        Fraction operator-(const float& num);
        friend Fraction operator-(const float& num, const Fraction& frac);


        // Operator *
        Fraction operator*(const Fraction& other);
        Fraction operator*(const float& other);
        friend Fraction operator*(const float& num, const Fraction& frac);


        // Operator /
        Fraction operator/(const Fraction& other);
        Fraction operator/(const float& other);
        friend Fraction operator/(const float& num, const Fraction& frac);


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
        bool operator==(const Fraction& frac) const;
        bool operator==(const float& other) const;
        friend bool operator==(const float& num, const Fraction& frac);

        // Operator <
        bool operator<(const Fraction& frac) const;
        bool operator<(const float& num) const;
        friend bool operator<(const float& num, const Fraction& frac);


        // Operator >
        bool operator>(const Fraction& frac) const;
        bool operator>(const float& num) const;
        friend bool operator>(const float& num, const Fraction& frac);


        // Operator <=
        bool operator<=(const Fraction& frac) const;
        bool operator<=(const float& num) const;
        friend bool operator<=(const float& num, const Fraction& frac);


        // Operator >=
        bool operator>=(const Fraction& frac) const;
        bool operator>=(const float& num) const;
        friend bool operator>=(const float& num, const Fraction& frac);


        // ioStream Operators
        // Operator <<
        friend ostream& operator<<(ostream& ost, const Fraction& frac);
        // Operator >>
        friend istream& operator>>(istream& ist, Fraction& frac);
    };
}
#endif