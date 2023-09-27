#include <iostream>

bool isPrimeNumber(int value) {
    if (value < 2)
        return false;

    for (int i{ 2 }; i < value; ++i) {
        if (value % i == 0)
            return false;
    }

    return true;
}

int main() {
    for (int i{ 1 }; i <= 100; ++i) {
        if (isPrimeNumber(i))
            std::cout << i << '\n';
    }
    
    return 0;
}