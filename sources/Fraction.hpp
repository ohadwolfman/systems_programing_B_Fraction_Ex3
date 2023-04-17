#ifndef FRACTION_HPP
#define FRACTION_HPP
#include <iostream>

using namespace std;
namespace ariel{
    class Fraction{
        int _numerator;
        int _denominator;

    public:
        Fraction (const int& numerator= 0, const int& denominator= 1):
        _numerator(numerator),
        _denominator(denominator) {}

        Fraction reducedForm();
        Fraction operator+(const Fraction& other) const;
        Fraction operator-(const Fraction& other) const;
        Fraction operator*(const Fraction& other) const;
        Fraction operator*(const double other);
        Fraction operator/(const Fraction& other) const;
        bool operator==(const Fraction& other) const;
        bool operator<(const Fraction& other) const;
        bool operator>(const Fraction& other) const;
        bool operator<=(const Fraction& other) const;
        bool operator>=(const Fraction& other) const;
        Fraction& operator++(); //prefix: ++n
        Fraction operator++(int dummy_flag_for_postfix_increment); //postfix n++
        Fraction& operator--(); //prefix: --n
        Fraction operator--(int dummy_flag_for_postfix_increment); //postfix n--
        friend ostream& operator<<(ostream& os, const Fraction& f);
        friend istream& operator>>(istream& is, Fraction& f);



    };
}
#endif