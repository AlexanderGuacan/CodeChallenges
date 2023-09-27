/*
 * Escribe un programa que muestre por consola (con un print) los
 * números de 1 a 100 (ambos incluidos y con un salto de línea entre
 * cada impresión), sustituyendo los siguientes:
 * - Múltiplos de 3 por la palabra "fizz".
 * - Múltiplos de 5 por la palabra "buzz".
 * - Múltiplos de 3 y de 5 a la vez por la palabra "fizzbuzz".
 */

#include <iostream>

bool isMultipleOf(int value, int multiple) {
    return value >= multiple && value % multiple == 0;
}

int main() {
    int min{ 1 };
    int max{ 100 };

    for (int i{ min }; i <= max; ++i) {
        std::string output{};
        
        if (isMultipleOf(i, 3))
            output += "fizz";

        if (isMultipleOf(i, 5))
            output += "buzz";

        if (!output.empty())
            std::cout << output;
        else
            std::cout << i;

        std::cout << '\n';
    }

    return 0;
}