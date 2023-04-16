#include "Fraction.hpp"
#include <stdexcept>

using namespace std;
using namespace ariel;
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

}
Fraction Fraction::operator*(const Fraction& other) const{

}
Fraction Fraction::operator/(const Fraction& other) const{

}
bool Fraction::operator==(const Fraction& other) const{

}
bool Fraction::operator<(const Fraction& other) const{

}
bool Fraction::operator>(const Fraction& other) const{

}
bool Fraction::operator<=(const Fraction& other) const{

}
bool Fraction::operator>=(const Fraction& other) const{

}
Fraction& Fraction::operator++(){

}
Fraction Fraction::operator++(int dummy_flag_for_postfix_increment){

}
Fraction& Fraction::operator--(){

}
Fraction Fraction::operator--(int dummy_flag_for_postfix_increment){

}
ostream& Fraction::operator<<(ostream& os, const Fraction& f){
    os << f._numerator <<'/' << f._denominator;
    return os;
}


