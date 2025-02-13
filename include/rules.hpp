#pragma once

#include <array>
#include <map>
#include <optional>

namespace RSG {
    constexpr unsigned char RULES_COUNT = 3;
    constexpr unsigned char REQUIRES_COUNT = 3;
    constexpr unsigned char MODES_COUNT = 3;

    constexpr std::array<unsigned char, MODES_COUNT> ALLOWED_MODES {0, 1, 2};

    constexpr std::array<bool, MODES_COUNT> MAX_REPEAT_OF_THE_SAME_CHARACTER_CATEGORY_REQUIRED_VALUES {false, true, true};
    constexpr std::array<bool, MODES_COUNT> MAX_REPEAT_OF_THE_SAME_CHARACTER_REQUIRED_VALUES {false, true, true};
    constexpr std::array<bool, MODES_COUNT> MAX_REPEAT_OF_THE_SAME_CHARACTER_IN_DIFFERENT_CATEGORIES_REQUIRED_VALUES {false, false, true};

    constexpr std::array<unsigned char, MODES_COUNT> MAX_REPEAT_OF_THE_SAME_CHARACTER_CATEGORY_VALUES {NULL, 5, 3};
    constexpr std::array<unsigned char, MODES_COUNT> MAX_REPEAT_OF_THE_SAME_CHARACTER_VALUES {NULL, 3, 1};
    constexpr std::array<unsigned char, MODES_COUNT> MAX_REPEAT_OF_THE_SAME_CHARACTER_IN_DIFFERENT_CATEGORIES_VALUES {NULL, NULL, 3};

    class Rules {
    private:
        // If the *_REQUIRED variable is set to `false`, then this rule will have no effect
        bool MAX_REPEAT_OF_THE_SAME_CHARACTER_CATEGORY_REQUIRED = false;
        bool MAX_REPEAT_OF_THE_SAME_CHARACTER_REQUIRED = false;
        bool MAX_REPEAT_OF_THE_SAME_CHARACTER_IN_DIFFERENT_CATEGORIES_REQUIRED = false;
        std::optional<unsigned short> MAX_REPEAT_OF_THE_SAME_CHARACTER_CATEGORY;                        // This variable specifies the maximum number of consecutive characters allowed from the same category (e.g., AAAAA, aaaaa, @@@@@).
        std::optional<unsigned short> MAX_REPEAT_OF_THE_SAME_CHARACTER;                                 // This variable specifies the maximum number of consecutive occurrences of the same character (e.g., aaaaa, bbbbb, !!!!!).
        std::optional<unsigned short> MAX_REPEAT_OF_THE_SAME_CHARACTER_IN_DIFFERENT_CATEGORIES;         // This variable specifies the maximum number of occurrences of the same character across different categories (e.g., AaaAa, BbbBBb, oOoOO).
    public:
        Rules(unsigned char mode);

        // Getters
        std::map<std::string, bool> GetRequires();                           // Return all *_REQUIRED variables
        std::map<std::string, std::optional<unsigned short>> GetRules();     // Return all rule variables
    };
}

