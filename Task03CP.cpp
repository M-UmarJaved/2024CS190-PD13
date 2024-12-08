#include<iostream>
#include<windows.h>
#include<fstream>
using namespace std;

string getBirthdayCake(string line, int field)
{
    string item;
    int commaCount = 1;
    for(int i = 0; i < line.length(); i++)
    {
        if(line[i] == ',')
        {
            commaCount += 1;
        }
        else if(commaCount == field)
        {
            item += line[i];
        }
    }
    return item;
}

void output(string result,int age, string resultAge)
{
    int age = stoi(resultAge);
    fstream file;
    file.open("output.txt", ios :: out);
    if(age % 2 == 0)
    {
        file << "####################" << endl << "#   " << age << " HB " << result << " !     #" << endl << "####################" << endl;
    }
    else
    {
        file << "********************" << endl << "*   " << age << " HB " << result << " !   *" << endl << "********************" << endl;
    }

    file.close();

}

main()
{
    string result, resultAge;
    string name,line;
    int age, field;

    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your age: ";
    cin >> age;

    fstream file;
    file.open("names.txt", ios :: out);
    file << name << "," << age << endl;
    file.close();
    file.open("names.txt", ios :: in);
    getline(file,line);
    file.close();

    result = getBirthdayCake(line, 1);
    resultAge = getBirthdayCake(line, 2);
    output(result, age, resultAge);
}
