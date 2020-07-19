#include<iostream>
#include"BigInt.h"

int main(){
    BigInt a(55555);
    std::cout << a.get_value() << " " << a.get_positive() << std::endl;
    std::cout << a.add(BigInt(123)).get_value() << std::endl;
	return 0;
}
