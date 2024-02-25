#include <iostream>
#include <iomanip>
#include <string.h>
#include <string>

using namespace std;

int main(int argv, char **argc)
{
    char text[1000]; // cstring

    cout << "Type in something and I will identify - WORDS, NUMBERS, PUNCTUATION\n";
    cin.getline(text, 1000);       // read the whole line (disregarding spaces)
    char *ptr = strtok(text, " "); // points to the cstring

    // until the null terminator
    while (ptr != NULL)
    {
        cout << ptr << ": ";

        // checks if the first character is alpha, digit or punc
        // assuming the user will type in the same type of the first char
        if (isalpha(*ptr))
        {
            cout << "WORDS\n";
        }
        else if (isdigit(*ptr))
        {
            cout << "NUMBERS\n";
        }
        else
        {
            cout << "PUNCTUATIONS\n";
        }

        ptr = strtok(NULL, " ");
    }

    return 0;
}
