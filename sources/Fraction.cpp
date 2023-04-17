#include "Fraction.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;
using namespace ariel;

int Fraction::getNumerator(){
    return this->_numerator;
}
int Fraction::getDenominator(){
    return this->_denominator;
}

Fraction Fraction::reducedForm(){
    if(this->_denominator!=0) {
        if (this->_numerator == 0)
            return Fraction(0, 1);
        else if (this->_numerator < this->_denominator)
            return *this;
        else if (this->_numerator == this->_denominator)
            return Fraction(1, 1);
        else {
            double answer = this->_numerator/this->_denominator;
            this->_numerator = this->_numerator-(answer*_denominator);
            return answer + (this->_numerator/this->_numerator);
        }
    }
    else{
        throw "error";
    }
}

Fraction Fraction::operator+(const Fraction& other) const {
    Fraction f = Fraction((this->_numerator*other._denominator) + (this->_denominator*other._numerator), this->_denominator*other._denominator);
    return f.reducedForm();
}
Fraction Fraction::operator-(const Fraction& other) const{
    return Fraction(1,1);
}
Fraction Fraction::operator*(const Fraction& other) const{
    return Fraction(1,1);
}
Fraction Fraction::operator*(const double other) const{
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
