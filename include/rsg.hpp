#pragma once

#include <string>
#include <string_view>

#include <include/rules.hpp>

namespace RSG {
    class RSG {
    private:
        std::string_view charset;
        unsigned short length;
        Rules rules;
    public:
        /*
         * Constructor for the Random String Generator (RSG).
         *
         * Parameters:
         *  - charset: any valid string_view.
         *  - length: the desired length of the generated string.
         *  - mode:
         *      - mode 0: generates a truly random string.
         *      - mode 1: generates a more secure string with additional checks.
         *      - mode 2: generates a highly secure string.
         */

        RSG(const std::string_view& charset, unsigned short length, unsigned char mode)
            : charset(charset), length(length), rules(Rules(mode)) {}

        std::string Generate();
    };
}
