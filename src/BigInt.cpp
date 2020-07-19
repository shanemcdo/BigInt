#include"BigInt.h"

BigInt::BigInt(){
    value = "0";
    positive = true;
}

BigInt::BigInt(std::string s){
    value = s;
    positive = (s[0] != '-');
}

BigInt::BigInt(long long l){
    value = std::to_string(l);
    positive = (value[0] != '-');
}
