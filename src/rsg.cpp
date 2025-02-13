#include <optional>
#include <cctype>
#include <random>

#include <include/rsg.hpp>
#include <include/charset.hpp>

namespace RSG {
    std::string RSG::Generate() {
        std::string result;

        std::map<std::string, bool> requires{ this->rules.GetRequires() };
        std::map<std::string, std::optional<unsigned short>> rules{ this->rules.GetRules() };
        std::optional<Charset> charset;
        std::random_device rd;

        std::optional<unsigned short> repeatedSameCategoryCount;
        std::optional<unsigned short> repeatedCharacterCount;
        std::optional<unsigned short> repeatedCharacterInTheDifferentCategoriesCount;
        std::optional<char> usedCharacter;
        std::optional<ECharset> usedCategory;

        if (requires.at("MAX_REPEAT_OF_THE_SAME_CHARACTER_CATEGORY_REQUIRED")) {
            repeatedCharacterCount = 0;
            charset = Charset(this->charset);
        }
        if (requires.at("MAX_REPEAT_OF_THE_SAME_CHARACTER_REQUIRED")) {
            repeatedCharacterCount = 0;
        }
        if (requires.at("MAX_REPEAT_OF_THE_SAME_CHARACTER_IN_DIFFERENT_CATEGORIES_REQUIRED")) {
            repeatedCharacterInTheDifferentCategoriesCount = 0;
            charset = Charset(this->charset);
        }

        for (size_t i{ 0 }; i < length; ++i) {
            GENERATE_CHAR:
                std::uniform_int_distribution<size_t> dist(0, this->charset.size());
                char randomChar{ this->charset[dist(rd)] };

                if (randomChar == '\0') {
                    goto GENERATE_CHAR;
                }
                if (requires.at("MAX_REPEAT_OF_THE_SAME_CHARACTER_CATEGORY_REQUIRED") &&
                    usedCategory.has_value() && charset->GetCharset(randomChar) == usedCategory.value() &&
                    repeatedSameCategoryCount.has_value() && repeatedSameCategoryCount.value() >= rules.at("MAX_REPEAT_OF_THE_SAME_CHARACTER_CATEGORY").value())
                {
                    goto GENERATE_CHAR;
                }
                else if (requires.at("MAX_REPEAT_OF_THE_SAME_CHARACTER_REQUIRED") &&
                        usedCharacter.has_value() && randomChar == usedCharacter.value() &&
                        repeatedCharacterCount.has_value() && repeatedCharacterCount.value() >= rules.at("MAX_REPEAT_OF_THE_SAME_CHARACTER").value())
                {
                    goto GENERATE_CHAR;
                }
                else if (requires.at("MAX_REPEAT_OF_THE_SAME_CHARACTER_IN_DIFFERENT_CATEGORIES_REQUIRED") &&
                        usedCharacter.has_value() && std::tolower(randomChar) == std::tolower(usedCharacter.value()) &&
                        repeatedCharacterInTheDifferentCategoriesCount.has_value() && repeatedCharacterInTheDifferentCategoriesCount.value() >= rules.at("MAX_REPEAT_OF_THE_SAME_CHARACTER_IN_DIFFERENT_CATEGORIES").value())
                {
                    goto GENERATE_CHAR;
                }
                result.push_back(randomChar);
                if (requires.at("MAX_REPEAT_OF_THE_SAME_CHARACTER_CATEGORY_REQUIRED")) {
                    if (usedCategory.has_value() && charset->GetCharset(randomChar) == usedCategory.value()) {
                        ++repeatedSameCategoryCount.value();
                    }
                    else {
                        repeatedSameCategoryCount = 0;
                    }
                }
                if (requires.at("MAX_REPEAT_OF_THE_SAME_CHARACTER_REQUIRED")) {
                    if (usedCharacter.has_value() && randomChar == usedCharacter.value()) {
                        ++repeatedCharacterCount.value();
                    }
                    else {
                        repeatedCharacterCount = 0;
                    }
                }
                if (requires.at("MAX_REPEAT_OF_THE_SAME_CHARACTER_IN_DIFFERENT_CATEGORIES_REQUIRED")) {
                    if (usedCharacter.has_value() && std::tolower(randomChar) == std::tolower(usedCharacter.value())) {
                        ++repeatedCharacterInTheDifferentCategoriesCount.value();
                    }
                    else {
                        repeatedCharacterInTheDifferentCategoriesCount.value() = 0;
                    }
                }
                usedCategory = charset->GetCharset(randomChar);
                usedCharacter = randomChar;
        }

        return result;
    }
}
