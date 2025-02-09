#include <iostream>
#include <direct.h>
#include <climits>


class task_1
{
private:
	FILE* inputFile;
	FILE* outputFile;

public:
	task_1(const char* inputN, const char* outputN){
		errno_t openingResult1 = fopen_s(&inputFile, inputN, "r");
		if (openingResult1 != 0)
			std::cout << "input error";
		errno_t openingResult2 = fopen_s(&outputFile, outputN, "w");
		if (openingResult2 != 0)
			std::cout << "output error";
	}
	~task_1() {
		fclose(inputFile);
		fclose(outputFile);
	}
	bool symbol(char ch) {
		return ((ch != ' ') && (ch != ',') && (ch != '.') && (ch != '!') && (ch != '?') && (ch != ':') && (ch != '-') && (ch != '"'));
	}

    void task1() {
        char word[20];
        int length = 0;
        char letter;

        while (fread(&letter, sizeof(char), 1, inputFile) == 1) {
            if (symbol(letter)) { 
                if (length < 20) {
                    word[length++] = letter;
                }
            }
            else {
                if (length >= 7) {
                    for (int i = 0; i < length; i++) {
                        fputc(word[i], outputFile);
                    }
                    fputc(' ', outputFile);
                }
                length = 0;
            }
        }
    }
    void task_2() {
        char line[1000];

        while (fgets(line, sizeof(line), inputFile)) {
            fputs(line, outputFile);
        }
    }
    void task_3() {
        char lines[500][1000];
        int count = 0;

        while (fgets(lines[count], sizeof(lines[count]), inputFile)) {
            count++;
        }

        for (int i = count - 1; i >= 0; i--) {
            fputs(lines[i], outputFile);
        }
    }

    bool vowel(char letter) {
        return ((letter == 'E') || (letter == 'Y') || (letter == 'U') || (letter == 'I') || (letter == 'O') || (letter == 'A') || (letter == 'e') || (letter == 'y') || (letter == 'u') || (letter == 'i') || (letter == 'o') || (letter == 'a'));
    }

    bool consonant(char letter) {
        return !vowel(letter);
    }

    void task_6() {
        if (!inputFile || !outputFile)  
            return;

        int symbols = 0;
        int rows = 0;
        int vowel_l = 0;
        int consonant_l = 0;
        int numbers = 0;
        char letter;

        while (fread(&letter, sizeof(char), 1, inputFile) == 1) {
            symbols++;

            if (letter == '\n') {
                rows++;
            }
            else if (vowel(letter)) {
                vowel_l++;
            }
            else if (consonant(letter)) {
                consonant_l++;
            }
            else if (letter >= '0' && letter <= '9') {
                numbers++;
            }
        }

        fprintf(outputFile, "symbols: %d", symbols);
        fprintf(outputFile, "\nrows: %d", rows);
        fprintf(outputFile, "\nvowel letters: %d", vowel_l);
        fprintf(outputFile, "\nconsonant letters: %d", consonant_l);
        fprintf(outputFile, "\nnumbers: %d", numbers);
    }
};



   

int main() {
    task_1 F_obj_1("in.txt", "out_1.txt");
    F_obj_1.task1();
    task_1 F_obj_2("in.txt", "out_2.txt");
    F_obj_2.task_2();
    task_1 F_obj_3("in.txt", "out_3.txt");
    F_obj_3.task_3();
    task_1 F_obj_6("in.txt", "out_4.txt");
    F_obj_6.task_6();
    return 0;
}