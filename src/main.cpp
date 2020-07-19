#include<iostream>
#include"BigInt.h"

int main(){
    BigInt a(-54321);
    std::cout << a.get_value() << " " << a.get_positive() << std::endl;
    a.set_value(12345);
    a.set_positive(false);
    std::cout << a.get_value() << " " << a.get_positive() << std::endl;
	return 0;
}
