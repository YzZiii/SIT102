#include "splashkit.h"

using namespace std;

string read_string(string prompt)
{
    string result;
    write(prompt);
    return read_line();
}

int read_integer(string prompt)
{
    string line;
    int result;
    line = read_string(prompt);

    while (not is_integer(line))
    {
        write_line("Please enter a whole number.");
        line = read_string(prompt);
    }
    
    result = convert_to_integer(line);
    return result;
}

int read_integer(string prompt, int min, int max)
{
    int result;
    result = read_integer(prompt);

    while (result < min or result > max)
    {
        write_line("Please enter a number between" + to_string(min) + "and" + to_string(max));
        result = read_integer(prompt);
    }
    return result;
}

double read_double(string prompt)
{
    string line;
    double result;
    line = read_string(prompt);

    while (not is_double(line))
    {
        write_line("Please enter a double number");
        line = read_string(prompt);
    }
    result = convert_to_double(line);
    return result;
}

double read_double(string prompt, double min, double max)
{
    double result;
    result = read_double(prompt);

    while (result < min or result > max)
    {
        write_line("Please enter a number between" + to_string(min) + "and" + to_string(max));
        result = read_double(prompt);
    }
    return result;
}

bool read_boolean(string prompt)
{
    string line;

    line = trim(to_lowercase(read_string(prompt)));

    while (line != "yes" && line != "no" && line != "y" && line != "n")
    {
        write_line("Please enter yes or no");
        line = trim(to_lowercase(read_string(prompt)));
    }

    if (line == "y" || line == "yes")
    {
        return true;
    }
    else
    {
        return false;
    }
}
