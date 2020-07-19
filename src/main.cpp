#include<iostream>
#include"BigInt.h"

int main(){
    BigInt a(55555);
    std::cout << a.get_value() << " " << a.get_positive() << std::endl;
	return 0;
}
