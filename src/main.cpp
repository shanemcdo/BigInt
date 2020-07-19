#include<iostream>
#include"BigInt.h"

int main(){
    BigInt a(-55555);
    std::cout << a << " " << a << std::endl;
    bool b = BigInt(-12222) < BigInt(-12224);
    std::cout << (b ? "true" : "false") << std::endl;
	return 0;
}
