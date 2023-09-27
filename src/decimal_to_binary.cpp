#include <string>
#include <iostream>

std::string decimalToBinary(int value) {
    std::string binary{};

    while (value > 1) {
        short binaryValue{ static_cast<short>(value % 2) };
        binary.insert(binary.begin(),  '0' + binaryValue);
        value /= 2;
    }
    
    binary.insert(binary.begin(),  '0' + value);

    return binary;
}

int main() {
    
    for (short i{}; i < 10; ++i)
        std::cout << i << " => " << decimalToBinary(i) << '\n';
    
    return 0;
}