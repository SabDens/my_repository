#pragma once
#include "GameWorld.h"
#include "GameWordsBuitder.h"
#include <memory>

using std::unique_ptr;

class Game
{
private:
	unique_ptr<GameWorld> current_word;
	int mistakes;
	GameWordsBuitder wordsBuilder;
public:
	Game(const shared_ptr<WorldsManager>& manager) :wordsBuilder(manager) {
		mistakes = 6;
	}
	void Start() {
		while (!current_word->IsGuessed() && mistakes < 6)
		{
			current_word = std::make_unique<GameWorld>(wordsBuilder.GetRandomWord());
			char letter;
			std::cout << "Enter: ";
			std::cin >> letter;
			if (current_word->InputLetter(letter))
			{
				std::cout << "Guessed!\n";
			}
			else {
				std::cout << "Ungessed";
				mistakes++;
			}
		}
	}

	void End() {

	}


};