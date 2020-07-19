#ifndef BIG_INT_H
#define BIG_INT_H

#include<string>

class BigInt{
private:
public:
    std::string value;
    bool positive;
    BigInt();
    BigInt(std::string s);
};

#endif //BIG_INT_H
