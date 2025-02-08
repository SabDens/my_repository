#include <iostream>
#include <string>
#include <fstream>
#include <memory>

class HTML_V {
private:
    std::unique_ptr<std::string> fileName;
public:
    HTML_V(const std::string& filename) {
        fileName = std::make_unique<std::string>(filename);
    }

    bool Validate() {
        char symbol;
        int open = 0;
        int close = 0;

        std::ifstream file(*fileName);
        if (!file) {
            std::cout << "Error\n";
            return false;
        }

        while (file.get(symbol)) {
            if (symbol == '<') {
                open++;
            }
            else if (symbol == '>') {
                close++;
            }
        }

        return (open == close);
    }

    void Show() {
        
        if (Validate()) {
            std::cout << "Valid" << std::endl;
        }
        else {
            std::cout << "Invalid" << std::endl;
        }
    }

};



int main() {
    std::string filename;
    std::cin >> filename;

    HTML_V validator(filename);
    validator.Show();
    return 0;
}