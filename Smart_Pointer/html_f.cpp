#include <iostream>
#include <fstream>
#include <string>
#include <memory>

bool validateHTML(const std::unique_ptr<std::string>& filename) {
    std::ifstream file(*filename);
    if (!file) {
        std::cout << "cant open";
        return false;
    }

    char ch;
    int op = 0;
    int cl = 0;

    while (file.get(ch)) {
        if (ch == '>')
            cl++;
        else if (ch == '<')
            op++;
    }

    if (op == cl)
        return true;
    else
        return false;
}

int main() {
    std::string filename;
    std::cout << "input way: ";
    std::cin >> filename;
    auto fn = std::make_unique<std::string>(filename);

    if (validateHTML(fn)) {
        std::cout << "valid" << std::endl;
    }
    else {
        std::cout << "invalid" << std::endl;
    }

    return 0;
}