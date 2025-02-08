#pragma once
#include "WorldsManager.h"
#include "GameWorld.h"

using std::shared_ptr;

class GameWordsBuitder
{
private:
	vector<string> buffer;
	shared_ptr<WorldsManager> manager;
public:
	GameWordsBuitder(const shared_ptr<WorldsManager>& manager):manager(manager)
	{
		buffer = manager->GetWords();
	}

	GameWorld GetRandomWord() {
		GameWorld result(buffer.front());
		buffer.erase(buffer.begin());
		return result;
	}
};
