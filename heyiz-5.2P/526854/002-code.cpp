#include "splashkit.h"
#include <string>

using namespace std;

struct knight_data
{
    string name;
    string month_of_birth;
    string gender;
    int age;
    //int month_of_birth;
};

string read_string(string prompt)
{
    string result;
    write(prompt);
    return read_line();
    return result;
}

int read_integer(string prompt)
{
    string line;
    line = read_string(prompt);
    return convert_to_integer(line);
}

knight_data read_knight()
{
    knight_data result;

    result.name = read_string(" Enter name: ");
    result.age = read_integer(" Enter age: ");
    result.month_of_birth =read_string("Enter birth: ");
    result.gender =read_string("Enter gender: ");

    return result;
}

void write_knight(const knight_data &knight)
{
    write_line("Hello: " + knight.name + " age: " + to_string(knight.age) + " birth: " + (knight.month_of_birth) + " gender: " +(knight.gender));
}

enum knight_update_option
{
    UPDATE_NAME,
    UPDATE_AGE,
    UPDATE_BIRTH,
    UPDATE_GENDER,
    FINISH_UPDATE
};

knight_update_option read_knight_update_option()
{
    int result;

    write_line("1: Update name");
    write_line("2: Update age");
    write_line("3: Update birth");
    write_line("4: Update gender");
    write_line("5: Finish update");
    result = read_integer("Select option: ");

    return static_cast<knight_update_option>(result - 1);
}

void update_knight(knight_data &knight)
{
    knight_update_option option;

    do
    {
        write_line();
        write_line("== Update Knight ==");
        write_knight(knight);
        write_line();
        option = read_knight_update_option();

        switch (option)
        {
        case UPDATE_NAME:
            knight.name = read_string("Enter new name: ");
            break;
        case UPDATE_AGE:
            knight.age = read_integer("Enter new age: ");
            break;
        case UPDATE_BIRTH:
            knight.month_of_birth =read_string("Enter new birth: ");
            break;
        case UPDATE_GENDER:
            knight.gender =read_string("Enter new gender: ");
            break;
        case FINISH_UPDATE:
            break;
        default:
            write_line("Please select a valid option");
        }
    } while (option != FINISH_UPDATE);
}

int main()
{
    knight_data my_knight;

    my_knight = read_knight();
    write_knight(my_knight);

    update_knight(my_knight);
    write_line("After update.... back in main");
    write_knight(my_knight);

    return 0;
}
