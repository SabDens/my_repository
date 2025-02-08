#pragma once
#include <string>
#include <vector>

using std:: vector;
using std:: string;

class WorldsManager
{
private:
	vector<string> words;
public:
	const vector<string>& GetWords() const  {
		return words;
	}
	void Save() {

	}
	void Load() {

	}
	void append(std::string& word) {

	}
};

