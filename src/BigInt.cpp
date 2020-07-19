#include"BigInt.h"

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
    value = s;
    positive = (s[0] != '-');
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
