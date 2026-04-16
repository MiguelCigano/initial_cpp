#include <iostream>
#include <string>

/** 
 * A word is considered valid if:
 *  
 *    It contains only digits (0 - 9), and english letters (Upper or lowercase).
 *    It contains a minimum of 3 characters.
 *    It includes at least one vowel.
 *    It includes at least on consonant.
 *    You are given string word. Return TRUE if is valid word o otherwise return FALSE.
    
 *     Example:
 *     word = "234Adas"
 *     Output: True

 *     Example:
 *     word = "a3$e"
 *     Output: False

      Constraints:
      word.length() <= 20
      word consists of english uppercase and lowercase letters, digits, "@", "#", and "$"
 */
class Solution {
    public:
        bool is_valid(std::string word) {
            if ((word.length() >= 20) || (word.length() < 3))  {
                return false;
            }
            for (const auto& letter : word) {
                if (!std::isalnum(static_cast<unsigned char>(letter))) {
                    std::cout << "No cumple" << std::endl;
                    return false;
                }
            }

            return ((is_vowel(word)) && (is_consonant(word)));
        }

        bool is_vowel(std::string word) {
            static constexpr std::string_view vowel = "aeiouAEIOU";
            return word.find_first_of(vowel) != std::string_view::npos;
        }
        bool is_consonant(std::string word) {
            static constexpr std::string_view consonants = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
            return word.find_first_of(consonants) != std::string_view::npos;
        }
};

int main() {
    Solution s;
    bool result = s.is_valid("UuE6");
    std::cout << result << std::endl;
    return 0;
}


