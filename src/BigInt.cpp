#include"BigInt.h"

// private

BigInt BigInt::align(unsigned long long zeros){
    std::string new_value = value;
    for(int i = 0; i < zeros; i++){
        new_value = '0' + new_value;
    }
    return BigInt(new_value);
}

BigInt BigInt::add(BigInt other){ //only functional when the second number is smaller
    unsigned long long zeros = value.length() - other.get_value().length();
    std::string aligned = other.align(zeros).get_value();
    std::string result = "";
    for(int i = 0; i < value.length(); i++){
        result += std::to_string(std::stoi(value.substr(i, 1)) + std::stoi(aligned.substr(i, 1)));
    }
    return BigInt(result);
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
