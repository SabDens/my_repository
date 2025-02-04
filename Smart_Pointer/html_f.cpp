#include <iostream>
#include <string>
#include <fstream>
#include <memory>

bool HTML_V(const std::unique_ptr<std::string>& file_n) {
    char simbol;
    int open = 0;
    int closed = 0;
    
    std::ifstream file(*file_n);
    if (!file) {
        std::cout << "Error";
        return false;
    }

 
    while (file.get(simbol)) {
        if (simbol == '>')
            closed++;
        else if (simbol == '<')
            open++;
    }

    if (open == closed)
        return true;
    else
        return false;
}

int main() {
    std::string filename;
    std::cin >> filename;

    auto file = std::make_unique<std::string>(filename);

    if (HTML_V(file)) {
        std::cout << "Valid" << "\n";
    }
    else {
        std::cout << "Invalid" << "\n";
    }

    return 0;
}