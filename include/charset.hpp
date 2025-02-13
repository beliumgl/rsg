#pragma once

#include <string>
#include <string_view>
#include <memory>

namespace RSG {
    class Charset {
    private:
        std::string capitalLettersCharset;
        std::string lowercaseLettersCharset;
        std::string digitsCharset;
        std::string specialCharactersCharset;
        std::string otherCharset;
    public:
        Charset(std::string_view charset);
        std::unique_ptr<std::string_view> GetCharset(char c);

        // Getters
        std::string_view GetCapialLettersCharset();
        std::string_view GetLowercaseLettersCharset();
        std::string_view GetDigitsCharset();
        std::string_view GetSpecialCharactersCharset();
        std::string_view GetOtherCharset();
    };
}
