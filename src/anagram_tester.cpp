#include <string>
#include <iostream>
#include <iomanip>

bool isAnagram(std::string originalWord, std::string_view anagram) {
    if (originalWord == anagram || originalWord.length() != anagram.length())
        return false;


    for (std::size_t i{}; i < anagram.length(); ++i) {
        bool isAnagram{};

        for (std::size_t j{}; j < originalWord.length(); ++j) {
            if (anagram[i] != originalWord[j])
                continue;

            isAnagram = true;
            originalWord.erase(j, 1);
            break;
        }

        if (!isAnagram)
            return false;
    }

    return true;
}

int main() {

    std::cout << std::boolalpha << isAnagram("amor", "roma") << '\n'
        << isAnagram("amor", "mora") << '\n'
        << isAnagram("", "");

    return 0;
}