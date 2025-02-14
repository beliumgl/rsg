#include <iostream>

#include <include/rsg.hpp>

int main() {
    unsigned short length = 20;
    unsigned char mode = 0; // truly random
    // Example usage
    RSG::RSG rsg = RSG::RSG("charset (you can edit this btw)", length, mode);

    std::cout << rsg.Generate() << '\n';
}
