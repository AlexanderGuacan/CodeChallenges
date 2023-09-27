/*
 * Crea un programa que cuente cuantas veces se repite cada palabra
 * y que muestre el recuento final de todas ellas.
 * - Los signos de puntuación no forman parte de la palabra.
 * - Una palabra es la misma aunque aparezca en mayúsculas y minúsculas.
 * - No se pueden utilizar funciones propias del lenguaje que
 *   lo resuelvan automáticamente.
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>

std::string stringToLowerCase(std::string_view string) {
    std::string lowercase{};

    for (auto character : string) {
        if (character >= 'A' && character <= 'Z')
            character = character + ('a' - 'A');

        lowercase.push_back(character);
    }

    return lowercase;
}

template <typename T>
bool existElementInVector(const T& element, const std::vector<T>& vector) {
    for (const auto& elementInVector : vector) {
        if (element == elementInVector)
            return true;
    }

    return false;
}

std::string removeCharacters(std::string_view string, const std::vector<unsigned char>& charactersToRemove) {
    std::string formatted{};

    for (unsigned char character : string) {
        if (!existElementInVector(character, charactersToRemove))
            formatted.push_back(character);
    }

    return formatted;
}

std::vector<std::string> stringToArray(std::string_view phrase, unsigned char separator) {
    std::vector<std::string> words{};
    std::string word{};

    for (std::size_t character{}; character < phrase.length(); ++character) {
        if (phrase[character] == separator) {
            words.push_back(word);
            word.clear();
            continue;
        }

        word.push_back(phrase[character]);
    }

    words.push_back(word);

    return words;
}

int main() {
    setlocale(LC_ALL, "es_ES.UTF-8");
    std::vector<unsigned char> punctuationMarks{ '!', ',', '.', ':', '?' };

    std::string phrase{ "La música es, según la definición tradicional del término, el arte de crear y organizar sonidos y silencios respetando los principios fundamentales de la melodía, la armonía y el ritmo, mediante la intervención de complejos procesos psicoanímicos. El concepto de música ha ido evolucionando desde su origen en la Antigua Grecia, en que se reunía sin distinción a la poesía, la música y la danza como arte unitario." };

    std::string formattedPhrase{ removeCharacters(stringToLowerCase(phrase), punctuationMarks) };

    const auto words{ stringToArray(formattedPhrase, ' ') };

    std::map<std::string_view, int> wordsCounter{};

    for (const auto& word : words) {
        if (wordsCounter.find(word) == wordsCounter.end())
            wordsCounter.insert({word, 1});
        else
            ++wordsCounter[word];
    }

    for (const auto& keyValue : wordsCounter)
        std::cout << keyValue.first << " => " << keyValue.second << '\n';

    return 0;
}