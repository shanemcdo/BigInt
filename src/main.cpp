#include<iostream>
#include"BigInt.h"

int main(){
    BigInt a(1000000000);
    // a = a.add(3);
    // a = a.subtract(987654321);
    std::cout << a << std::endl;
    std::cout << -a << std::endl;
    std::cout << a << std::endl;
    bool b = BigInt(-12222) < BigInt(-12224);
    std::cout << (b ? "true" : "false") << std::endl;
    b = BigInt(22) > BigInt(-23);
    std::cout << (b ? "true" : "false") << std::endl;
    b = BigInt("232323232323232323232323232323232323232") <= BigInt("3232323232323232323232323232323232323232");
    std::cout << (b ? "true" : "false") << std::endl;
    b = BigInt(50) >= BigInt(50);
    std::cout << (b ? "true" : "false") << std::endl;
    b = BigInt(50) == BigInt(50);
    std::cout << (b ? "true" : "false") << std::endl;
    b = BigInt(50) != BigInt(50);
    std::cout << (b ? "true" : "false") << std::endl;
    a = BigInt(500) + BigInt(100);
    std::cout << a << std::endl;
	return 0;
}
