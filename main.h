#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <string>
#include <vector>

using namespace std;

void initializeGame();

void cleanupGame();

int parseScript(string currentLine, Player &myPlayer);

string nextSection(int &asterisk, string &fullString);

void displayText(string x);

string getScript(vector<string> x, int nextLine);

void loadFile(string filename, vector<string> &gameScript);

#endif // MAIN_H_INCLUDED
