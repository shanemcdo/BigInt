#ifndef BIG_INT_H
#define BIG_INT_H

#include<string>

class BigInt{
private:
    std::string value;
    bool positive;
public:
    BigInt();
    BigInt(std::string s);
    BigInt(long long l);
};

#endif //BIG_INT_H
