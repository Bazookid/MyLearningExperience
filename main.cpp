#include <fstream>
#include <iostream>
#include <sstream>

#include "player.cpp"
#include "main.h"
using namespace std;

int main()
{
    int nextLine = 0; //Keeps track of which line to print next(from vector gameScript).
    vector<string> gameScript; //Will hold all the text from frind.txt.
    bool isRunning = true;
    string filename = "frind.txt"; //Name of file to be loaded.
    Player myPlayer; //Holds information about the player, such as the money they have.

    loadFile(filename, gameScript); //Puts text into the vector that is passed.
    initializeGame();

    while(isRunning)
    {
        string currentLine = getScript(gameScript, nextLine);
        if(currentLine.empty())
            isRunning = false;
        else
            nextLine = parseScript(currentLine, myPlayer);
        if(nextLine==-1)
            isRunning=false;
    }
    //cout << "ended the game with " << myPlayer.CurGold() << " gold." << endl;
    cleanupGame();
    return 0;
}

void initializeGame()
{

}

int parseScript(string currentLine, Player &myPlayer)
{
    string tempString; //Holds substrings
    int choices = 0; //Holds the number of available choices

    int found = currentLine.find("*");
    tempString = currentLine.substr(0, found); //Puts the text into a temporary string
    displayText(tempString); //Display the part of the string that comes before "*" (the dialog)

    tempString = nextSection(found, currentLine);

    stringstream convert; //Used to convet Strings to ints
    if(tempString.substr(0,1)=="$")//Indicates that the player either gains or loses gold
    {
        int gold;
        if(tempString.substr(1,1)=="-") //Lose gold
        {
            convert << tempString.substr(2,found-2); //Convert the number found inbetween the '$-' and the '*'
            convert >> gold;
            //cout << "You just lost " << gold << " gold." << endl;
            myPlayer.LoseGold(gold);
        }
        else //gain gold
        {
            convert << tempString.substr(1,found-1);
            convert >> gold;
            //cout << "You just gained " << gold << " gold." << endl;
            myPlayer.GainGold(gold);
        }
        tempString = nextSection(found, currentLine);
    }
    if(found==string::npos)
        return -1;

    //Convert the number in string (the number of available options) to an int
    convert.clear();
    convert.str("");
    convert << tempString;
    convert >> choices;

    int userChoice = 0;

    if(choices > 0)
    {
        while(userChoice<1 || userChoice>choices)//Makes user enter a valid option
        {
            cin >> userChoice;
        }
        for(int i=0; i<userChoice; i++)
        {
            tempString = nextSection(found, currentLine);
        }
    }
    else
    tempString = nextSection(found, currentLine);//If number of choices is zero, find next value in string

    convert.clear();
    convert.str("");
    convert << tempString;
    convert >> userChoice;
    return userChoice;
}

string nextSection(int &asterisk, string &fullString)
{
    fullString.erase(0, ++asterisk); //Erase the first "*" and everything before it (erase sentance portion)
    asterisk = fullString.find("*"); //Find the next "*"
    return fullString.substr(0, asterisk); //Return a substring containing all the text before the first "*"
}

void displayText(string x)//Displays the text without cutting off words
{
    while(!x.empty())
    {
        if(x.length()>79)
        {
            int spacePos;
            string y;

            spacePos = x.rfind(" ", 79);
            y = x.substr(0, spacePos);
            cout << y << endl;
            x.erase(0, spacePos);//Erase the part of the string that was printed
        }
        else
        {
            cout << x << endl;
            x.erase();
        }
    }
}


string getScript(vector<string> x, int nextLine) //Return the next line from gameScript
{
    string temporary = x[nextLine];
    return temporary;
}

void cleanupGame()
{

}

void loadFile(string filename, vector<string> &gameScript) //Load the text file frind.txt into the vector gameScript
{
    string input;
    ifstream inf(filename.c_str());
    while(inf)
    {
        getline(inf, input);
        gameScript.push_back(input);
    }
}
