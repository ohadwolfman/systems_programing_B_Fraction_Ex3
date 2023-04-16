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
        ostream& operator<<(ostream& os, const Fraction& f);
        ostream& operator>>(ostream& os, const Fraction& f);



    };
}
#endif