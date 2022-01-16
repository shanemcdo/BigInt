#include<iostream>
#include"BigInt.h"

BigInt factorial(BigInt n){
    if(n < 0)
        throw "Expected a value greater than or equal to 0";
    if(n <= 1)
        return 1;
    BigInt result = 1;
    for(BigInt i = 2; i <= n; i++)
        result *= i;
    return result;
};

int main(){
    BigInt a(123456);
    for(int i = 0; i < 64; i++){
        std::cout << i << ": " << BigInt(2).pow(i) << std::endl;
    }
    std::cout << a << " " << -a << std::endl;
    a = -a;
    std::cout << a << std::endl;
    std::cout << a.abs() << " " << a.abs() << std::endl;
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
    std::cout << BigInt(-500) + BigInt(-600) << std::endl;
    std::cout << BigInt("-10000000000000000000000000000") + BigInt(-1) << std::endl;
    std::cout << BigInt(500) - BigInt(-200) << std::endl;
    std::cout << BigInt(-500) - BigInt(-200) << std::endl;
    std::cout << BigInt(1) - BigInt("1000000000000000000000000000000000000000000000000") << std::endl;
    a = BigInt(12345);
    a += BigInt(54321);
    std::cout << a << std::endl;
    a -= BigInt(9999999);
    std::cout << a << std::endl;
    a = 91231312312312;
    std::cout << a << std::endl;
    a = "99999999999999999999999999999999999999999999";
    std::cout << a << std::endl;
    b = a < "5000";
    std::cout << (b ? "true" : "false") << std::endl;
    b = a < 10000;
    std::cout << (b ? "true" : "false") << std::endl;
    b = a > "5000";
    std::cout << (b ? "true" : "false") << std::endl;
    b = a > 10000;
    std::cout << (b ? "true" : "false") << std::endl;
    b = a <= "5000";
    std::cout << (b ? "true" : "false") << std::endl;
    b = a <= 10000;
    std::cout << (b ? "true" : "false") << std::endl;
    b = a >= "5000";
    std::cout << (b ? "true" : "false") << std::endl;
    b = a >= 10000;
    std::cout << (b ? "true" : "false") << std::endl;
    b = a == "5000";
    std::cout << (b ? "true" : "false") << std::endl;
    b = a == 10000;
    std::cout << (b ? "true" : "false") << std::endl;
    b = a != "5000";
    std::cout << (b ? "true" : "false") << std::endl;
    b = a != 10000;
    std::cout << (b ? "true" : "false") << std::endl;
    std::cout << a << std::endl;
    a += 10;
    a += "10";
    std::cout << a << std::endl;
    a -= 20;
    a -= "99999999999999999999999999999999999999999999";
    std::cout << a << std::endl;
    std::cout << BigInt(10) - "10" << std::endl;
    std::cout << -BigInt(-99999999) * -500 << std::endl;
    a = "99999999999999999999999999999999";
    a *= "99999999999999999999999999999999";
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << a-- << std::endl;
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << --a << std::endl;
    a = 2;
    std::cout << a.pow("100") << std::endl;
    for(BigInt i = 0; i < 1000; i++)
        std::cout << factorial(i) << std::endl;
	return 0;
}
