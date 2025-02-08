#pragma once
#include <iostream>
#include <string>

class GameWorld
{
private:
	std::string hidden_world;
	std::string external_world;

public:
	GameWorld(std::string& word)
		:hidden_world(word), external_world(word)
	{

	}
	bool InputLetter(char letter) {
		return false;
	}
	std::string& GetExternalWord() {
		return external_world;
	}
	bool IsGuessed()const {
		return hidden_world == external_world;
	}
};
