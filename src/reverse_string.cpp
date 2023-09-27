/*
 * Crea un programa que invierta el orden de una cadena de texto
 * sin usar funciones propias del lenguaje que lo hagan de forma automática.
 * - Si le pasamos "Hola mundo" nos retornaría "odnum aloH"
 */

#include <string>
#include <iostream>

std::string reverseString(std::string_view str) {
    std::string reverse{};

    for (int i{ static_cast<int>(str.length() - 1ull) }; i >= 0; --i)
        reverse.push_back(str[i]);

    return reverse;
}

int main() {
    std::string original{ "Hola mundo" };
    std::cout << original << " => " << reverseString(original);
    
    return 0;
}