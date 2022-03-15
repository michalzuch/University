#include <iostream>

using namespace std;

class Converter {
protected:
    unsigned long value;
    
public:
    void operator= (char character) {
        value = character;
    }
    
    void operator= (const char* characters) {
        string word(characters);
        for (auto i : word) value += i;
    }
    
    void operator= (string word) {
        for (auto i : word) value += i;
    }
};

int main() {
    Converter converter;
    return 0;
}
