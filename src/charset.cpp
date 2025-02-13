#include <include/charset.hpp>

namespace RSG {
    Charset::Charset(std::string_view charset) {
        std::string capitalLettersCharset;
        std::string lowercaseLettersCharset;
        std::string digitsCharset;
        std::string specialCharactersCharset;
        std::string otherCharset;

        for (const char x: charset) {
            if (std::isupper(x)) {
                capitalLettersCharset.push_back(x);
            }
            else if (std::islower(x)) {
                lowercaseLettersCharset.push_back(x);
            }
            else if (std::isdigit(x)) {
                digitsCharset.push_back(x);
            }
            else if (!std::isalnum(x)) {
                specialCharactersCharset.push_back(x);
            }
            else {
                otherCharset.push_back(x);
            }
        }

        this->capitalLettersCharset = capitalLettersCharset;
        this->lowercaseLettersCharset = lowercaseLettersCharset;
        this->digitsCharset = digitsCharset;
        this->specialCharactersCharset = specialCharactersCharset;
        this->otherCharset = otherCharset;
    }

    std::unique_ptr<std::string_view> Charset::GetCharset(char c) {
        if (std::isupper(c)) {
            return std::make_unique<std::string_view>(this->capitalLettersCharset);
        }
        else if (std::islower(c)) {
            return std::make_unique<std::string_view>(this->lowercaseLettersCharset);
        }
        else if (std::isdigit(c)) {
            return std::make_unique<std::string_view>(this->digitsCharset);
        }
        else if (!std::isalnum(c)) {
            return std::make_unique<std::string_view>(this->specialCharactersCharset);
        }
        else {
            return std::make_unique<std::string_view>(this->otherCharset);
        }
    }

    std::string_view Charset::GetCapialLettersCharset() {
        return this->capitalLettersCharset;
    }

    std::string_view Charset::GetLowercaseLettersCharset() {
        return this->lowercaseLettersCharset;
    }

    std::string_view Charset::GetDigitsCharset() {
        return this->digitsCharset;
    }

    std::string_view Charset::GetSpecialCharactersCharset() {
        return this->specialCharactersCharset;
    }

    std::string_view Charset::GetOtherCharset() {
        return this->otherCharset;
    }
}
