#include <iostream>
#include <fstream>
using namespace std;

string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
string morseCodes[100] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
    "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-.-.-.-"};

// Function to turn a single letter into Morse code
string toMorse(char letter)
{
    if (letter >= 'a' && letter <= 'z')
    {
        letter -= 32; // Make it uppercase
    }
    for (int i = 0; i < letters.length(); i++)
    {
        if (letters[i] == letter)
        {
            return morseCodes[i];
        }
    }
    return "";
}

// Function to turn a whole message into Morse code
void makeMorse(string message)
{
    fstream outputFile;
    outputFile.open("MorseOutput.txt", ios::out);

    string morseMessage = "";
    for (int i = 0; i < message.length(); i++)
    {
        string morseChar = toMorse(message[i]);
        if (!morseChar.empty())
        {
            morseMessage += morseChar + " ";
        }
    }

    outputFile << "Original message: " << message << endl;
    outputFile << "Morse code: " << morseMessage << endl;
    outputFile.close();
}

int main()
{
    string userInput;
    cout << "Enter the message to turn into Morse: ";
    getline(cin, userInput);

    makeMorse(userInput);
}
