#ifndef BIG_INT_H
#define BIG_INT_H

#include<string>
#include<iostream>

class BigInt{
private:
    std::string value;
    bool positive;
    std::string align(unsigned long long zeros);
    BigInt add(BigInt other);
    BigInt add(long long l);
public:
    // constructors
    BigInt();
    BigInt(std::string s);
    BigInt(long long l);
    // setters and getters
    void set_value(std::string s);
    void set_value(long long l);
    void set_positive(bool b);
    std::string get_value();
    bool get_positive();
    // operators
    friend std::ostream& operator<<(std::ostream& out, BigInt num);
    bool operator<(BigInt other);
    bool operator>(BigInt other);
    bool operator<=(BigInt other);
};

#endif //BIG_INT_H
