#include"splashkit.h"
using namespace std;

string read_string ( string prompt)// Return a string of the input line from the terminal
{
    string result;
    write(prompt);
    result = read_line();
    return result;
}
// user input value
int read_integer (string prompt) 
{
    string line;
    int result;

    line = read_string(prompt);
    result = convert_to_integer(line);  //The text the user enters

    return result;
}

