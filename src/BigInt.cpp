#include"BigInt.h"

// private

std::string BigInt::align(unsigned long long zeros){
    std::string new_value = value;
    for(int i = 0; i < zeros; i++){
        new_value = '0' + new_value;
    }
    return new_value;
}

BigInt BigInt::add(BigInt other){ //only functional when the second number is smaller
    unsigned long long zeros = value.length() - other.get_value().length();
    std::string aligned = other.align(zeros);
    std::string result = "";
    short carry = 0;
    for(int i = value.length() - 1; i >= 0; i--){
        short x = std::stoi(value.substr(i, 1)) + std::stoi(aligned.substr(i, 1)) + carry;
        carry = x / 10;
        result = std::to_string(x % 10)+ result;
    }
    result = std::to_string(carry) + result;
    return BigInt(result);
}

BigInt BigInt::subtract(BigInt other){
    unsigned long long zeros = value.length() - other.get_value().length();
    std::string aligned = other.align(zeros);
    std::string result = "";
    short carry = 0;
    for(int i = value.length() - 1; i >= 0; i--){
        short x = std::stoi(value.substr(i, 1)) - std::stoi(aligned.substr(i, 1)) - carry;
        if(x < 0){
            x += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        result = std::to_string(x) + result;
    }
    return BigInt(result);
}

void BigInt::clean_leading_zeros(){
    std::string new_value = value;
    for(int i = 0; i < value.length() - 1; i++){
        if(value[i] == '0') new_value = value.substr(i + 1);
        else break;
    }
    value = new_value;
    if(value == "0") positive = true;
}

// public

BigInt::BigInt(){
    value = "0";
    positive = true;
}

BigInt::BigInt(std::string s){
    set_value(s);
}

BigInt::BigInt(long long l){
    set_value(l);
}

void BigInt::set_value(std::string s){
    positive = true;
    if(s.length() == 0){
        value = "0";
    } else if(s[0] == '-'){
        value = s.substr(1);
        positive = false;
    } else {
        value = s;
    }
    clean_leading_zeros();
}

void BigInt::set_value(long long l){
    set_value(std::to_string(l));
}

void BigInt::set_positive(bool b){
    positive = b;
}

std::string BigInt::get_value(){
    return value;
}

bool BigInt::get_positive(){
    return positive;
}

std::ostream& operator<<(std::ostream& out, BigInt num){
    if(!num.get_positive()){
        out << '-';
    }
    out << num.get_value();
    return out;
}

bool BigInt::operator<(BigInt other){
    if(positive && !other.get_positive()) return false;
    else if(!positive && other.get_positive()) return true;
    unsigned long long len = value.length();
    std::string other_value = other.get_value();
    unsigned long long other_len = other_value.length();
    if(len != other_len){
        if(positive) return len < other_len;
        else return len > other_len;
    }
    for(int i = 0; i < len; i++){
        if(value[i] != other_value[i]){
            if(positive) return value[i] < other_value[i];
            else return value[i] > other_value[i];
        }
    }
    return false;
}

bool BigInt::operator<(std::string s){
    return *this < BigInt(s);
}

bool BigInt::operator<(long long l){
    return *this < BigInt(l);
}

bool BigInt::operator>(BigInt other){
    return !(*this <= other);
}

bool BigInt::operator>(std::string s){
    return *this > BigInt(s);
}

bool BigInt::operator>(long long l){
    return *this > BigInt(l);
}

bool BigInt::operator<=(BigInt other){
    return *this < other || *this == other;
}

bool BigInt::operator<=(std::string s){
    return *this <= BigInt(s);
}

bool BigInt::operator<=(long long l){
    return *this <= BigInt(l);
}

bool BigInt::operator>=(BigInt other){
    return !(*this < other);
}

bool BigInt::operator>=(std::string s){
    return *this >= BigInt(s);
}

bool BigInt::operator>=(long long l){
    return *this >= BigInt(l);
}

bool BigInt::operator==(BigInt other){
    return value == other.get_value() && positive == other.get_positive();
}

bool BigInt::operator==(std::string s){
    return *this == BigInt(s);
}

bool BigInt::operator==(long long l){
    return *this == BigInt(l);
}

bool BigInt::operator!=(BigInt other){
    return !(*this == other);
}

bool BigInt::operator!=(std::string s){
    return *this != BigInt(s);
}

bool BigInt::operator!=(long long l){
    return *this != BigInt(l);
}

BigInt BigInt::operator-(){
    BigInt new_BigInt = *this;
    new_BigInt.set_positive(!new_BigInt.get_positive());
    return new_BigInt;
}

BigInt BigInt::operator+(BigInt other){
    if(positive){
        if(other.get_positive()){ // a + b
            if(abs() > other.abs()) return add(other); // a + b
            else return other.add(*this); // b + a
        } else { // a + ( - b ) == a - b
            if(abs() > other.abs()) return subtract(other); // a - b
            else return -other.subtract(*this); // a - b == -( b - a )
        }
    } else {
        if(other.get_positive()){ // ( - a ) + b == b - a
            if(abs() > other.abs()) return -subtract(other); // b - a == -( a - b )
            else return other.subtract(*this);// b - a
        } else { // ( - a) + ( - b) == - ( a + b )
            if(abs() > other.abs()) return -add(other); // - ( a + b )
            else return -other.add(*this); // - ( b + a )
        }
    }
}

BigInt BigInt::operator+(std::string s){
    return *this + BigInt(s);
}

BigInt BigInt::operator+(long long l){
    return *this + BigInt(l);
}

BigInt BigInt::operator-(BigInt other){
    if(positive){
        if(other.get_positive()){ // a - b
            if(abs() >= other.abs()) return subtract(other); // a - b
            else return -other.subtract(*this); // - ( b - a )
        } else { // a - ( - b) = a + b
            if(abs() > other.abs()) return add(other); // a + b
            else return other.add(*this); // b + a
        }
    } else {
        if(other.get_positive()){ // ( - a ) - b == -( a + b )
            if(abs() > other.abs()) return -add(other); // -( a + b )
            else return -other.add(*this); // -( b + a )
        } else { // ( - a ) - ( - b ) == -( a - b )
            if(abs() > other.abs()) return -subtract(other); // -( a - b )
            else return other.subtract(*this); // -( -( b - a )) == b - a
        }
    }
}

BigInt BigInt::operator-(std::string s){
    return *this - BigInt(s);
}

BigInt BigInt::operator-(long long l){
    return *this - BigInt(l);
}

BigInt* BigInt::operator+=(BigInt other){
    *this = *this + other;
    return this;
}

BigInt* BigInt::operator+=(std::string s){
    return *this += BigInt(s);
}

BigInt* BigInt::operator+=(long long l){
    return *this += BigInt(l);
}

BigInt* BigInt::operator-=(BigInt other){
    *this = *this - other;
    return this;
}

BigInt* BigInt::operator-=(std::string s){
    return *this -= BigInt(s);
}

BigInt* BigInt::operator-=(long long l){
    return *this -= BigInt(l);
}

BigInt* BigInt::operator=(std::string s){
    set_value(s);
    return this;
}

BigInt* BigInt::operator=(long long l){
    set_value(l);
    return this;
}

BigInt BigInt::abs(){
    if(positive) return *this;
    return -(*this);
}
