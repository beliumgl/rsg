#include <algorithm>
#include <stdexcept>

#include <include/rules.hpp>

namespace RSG {
    Rules::Rules(unsigned char mode) {
        // Check if the mode is valid
        if (std::find(ALLOWED_MODES.begin(), ALLOWED_MODES.end(), mode) == ALLOWED_MODES.end()) {
            throw std::invalid_argument("Incorrect mode.");
        }

        this->MAX_REPEAT_OF_THE_SAME_CHARACTER_CATEGORY_REQUIRED = MAX_REPEAT_OF_THE_SAME_CHARACTER_CATEGORY_REQUIRED_VALUES[mode];
        this->MAX_REPEAT_OF_THE_SAME_CHARACTER_REQUIRED = MAX_REPEAT_OF_THE_SAME_CHARACTER_REQUIRED_VALUES[mode];
        this->MAX_REPEAT_OF_THE_SAME_CHARACTER_IN_DIFFERENT_CATEGORIES_REQUIRED = MAX_REPEAT_OF_THE_SAME_CHARACTER_IN_DIFFERENT_CATEGORIES_REQUIRED_VALUES[mode];

        if (this->MAX_REPEAT_OF_THE_SAME_CHARACTER_CATEGORY_REQUIRED) {
            this->MAX_REPEAT_OF_THE_SAME_CHARACTER_CATEGORY = MAX_REPEAT_OF_THE_SAME_CHARACTER_CATEGORY_VALUES[mode];
        }

        if (this->MAX_REPEAT_OF_THE_SAME_CHARACTER_REQUIRED) {
            this->MAX_REPEAT_OF_THE_SAME_CHARACTER = MAX_REPEAT_OF_THE_SAME_CHARACTER_VALUES[mode];
        }

        if (this->MAX_REPEAT_OF_THE_SAME_CHARACTER_IN_DIFFERENT_CATEGORIES_REQUIRED) {
            this->MAX_REPEAT_OF_THE_SAME_CHARACTER_IN_DIFFERENT_CATEGORIES = MAX_REPEAT_OF_THE_SAME_CHARACTER_IN_DIFFERENT_CATEGORIES_VALUES[mode];
        }
    }

    std::map<std::string, bool> Rules::GetRequires() {
        return {
            {"MAX_REPEAT_OF_THE_SAME_CHARACTER_CATEGORY_REQUIRED", this->MAX_REPEAT_OF_THE_SAME_CHARACTER_CATEGORY_REQUIRED},
            {"MAX_REPEAT_OF_THE_SAME_CHARACTER_REQUIRED", this->MAX_REPEAT_OF_THE_SAME_CHARACTER_REQUIRED},
            {"MAX_REPEAT_OF_THE_SAME_CHARACTER_IN_DIFFERENT_CATEGORIES_REQUIRED", this->MAX_REPEAT_OF_THE_SAME_CHARACTER_IN_DIFFERENT_CATEGORIES_REQUIRED}
        };
    }

    std::map<std::string, std::optional<unsigned char>> Rules::GetRules() {
        return {
            {"MAX_REPEAT_OF_THE_SAME_CHARACTER_CATEGORY", this->MAX_REPEAT_OF_THE_SAME_CHARACTER_CATEGORY},
            {"MAX_REPEAT_OF_THE_SAME_CHARACTER", this->MAX_REPEAT_OF_THE_SAME_CHARACTER},
            {"MAX_REPEAT_OF_THE_SAME_CHARACTER_IN_DIFFERENT_CATEGORIES", this->MAX_REPEAT_OF_THE_SAME_CHARACTER_IN_DIFFERENT_CATEGORIES}
        };
    }
}
