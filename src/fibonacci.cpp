/*
 * Escribe un programa que imprima los 50 primeros números de la sucesión
 * de Fibonacci empezando en 0.
 * - La serie Fibonacci se compone por una sucesión de números en
 *   la que el siguiente siempre es la suma de los dos anteriores.
 *   0, 1, 1, 2, 3, 5, 8, 13...
 */

#include <iostream>

int main() {
    short n{ 50 };

    unsigned long long n0{};
    unsigned long long n1{ 1 };

    for (short i{}; i < n; ++i) {
        std::cout << n0 << '\n';

        unsigned long long fib{ n0 + n1 };

        n0 = n1;
        n1 = fib;
    }

    return 0;
}