# Random String Generator
A project written in C++17 that allows you to generate strings with different modes, different character sets, and any length (within a specified range).

# Build
```
mkdir build && cd build
cmake ..
cmake --build .
```
# Run
```
./testapp
```

# Usage
```cpp
#include <iostream>

#include <include/rsg.hpp>

int main() {
    unsigned short length = 20;
    unsigned char mode = 0; // truly random
    // Example usage
    RSG::RSG rsg = RSG::RSG("charset (you can edit this btw)", length, mode);

    std::cout << rsg.Generate() << '\n';
}
```
