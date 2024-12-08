#include <iostream>
#include <fstream>
using namespace std;

void findMissingLetters(string givenLetters)
{
    bool hasLetter[26] = {false};

    // Marking existing letters
    for (int i = 0; i < givenLetters.size(); i++)
    {
        char letter = givenLetters[i];
        if (letter >= 'a' && letter <= 'z')
        {
            hasLetter[letter - 'a'] = true;
        }
    }

    // Finding the missing letters
    string missingLetters = "";
    for (int i = 0; i < 26; i++)
    {
        if (!hasLetter[i])
        {
            missingLetters += char(i + 'a');
        }
    }

    // Writing missing letters to a file
    fstream letterFile;
    letterFile.open("letters.txt", ios::app);
    if (!missingLetters.empty())
    {
        letterFile << "\n"
                   << missingLetters;
    }
    else
    {
        letterFile << "\n";
    }
    letterFile.close();
}

int main()
{
    string userLetters;
    cout << "Enter some letters (a-z): ";
    cin >> userLetters;

    // Writing user input to file
    fstream letterFile;
    letterFile.open("letters.txt", ios::out);
    letterFile << userLetters;
    letterFile.close();

    // Check for missing letters
    findMissingLetters(userLetters);
}
