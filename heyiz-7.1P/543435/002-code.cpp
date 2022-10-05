#include "splashkit.h"
#include <string>
#include <vector>
using std::vector;
using namespace std;

struct knight_data // the struct for knights data
{
    string name;
    int age;
    vector<string> tools;
};

struct kingdom_data // kingdom data, stores the data of the knights
{
    string name;
    vector<knight_data> knights;
};

string read_string(string prompt)
{
    string result;
    write(prompt);
    result = read_line();
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
    result.name = read_string("Enter name: ");
    result.age = read_integer("Enter your age: ");
    result.tools.push_back(read_string("Enter first tools: "));
    return result;
}

enum knight_update_option // functions within the knight menu
{
    UPDATE_NAME,
    UPDATE_AGE,
    ADD_TOOLS,
    DEL_TOOLS,
    FINISH_UPDATE
};

int read_knight_update_option() // knight update menu
{
    int result;
    write_line("<== Update Knight ==>");
    write_line("1: Update name ");
    write_line("2: Update age ");
    write_line("3: Add a tool ");
    write_line("4: Delete a tool ");
    write_line("5: Finish update");
    result = read_integer("Select option: ");
    return static_cast<knight_update_option>(result - 1);
}

enum kingdom_create_option // functions within the kingdom menu
{
    ADD_KNIGHT,
    QUERY_KNIGHT,
    UPDATE_KNIGHT,
    DELETE_KNIGHT,
    DISPLAY_KINGDOM,
    END_KINGDOM
};

int read_kingdom_create_option() // kingdom update menu
{
    int result;
    write_line("<== Kingdom Menu ==>");
    write_line("1: Add a Knight ");
    write_line("2: Query a Knight ");
    write_line("3: Update a Knight ");
    write_line("4: Delete a Knight ");
    write_line("5: Display the Kingdom ");
    write_line("6: Exit the Kingdom ");
    result = read_integer("Select option: ");
    return static_cast<kingdom_create_option>(result - 1);
}

void add_knight(kingdom_data &kingdom) // adding a knight function
{
    knight_data new_knight;
    new_knight = read_knight();
    kingdom.knights.push_back(new_knight);
}

void write_knight(const knight_data &knights) // allows the compliter to not change the data
{
    write_line(knights.name + " aged " + to_string(knights.age) + " Your tools are: ");
    for (int i = 0; i < knights.tools.size(); i++)
    {
        write_line(knights.tools[i]);
    }
}

// writing the kingdom function
void write_kingdom(const kingdom_data &kingdom) // data will not change// outputs the details of the kingdom including the knight details
{   
    write_line("Kingdom: " +kingdom.name);
    if (kingdom.knights.empty()) // will display this error if there are no knights in the kingdom
    {
        write_line("no knight");
    }
    else
    {
        for (int i = 0; i < kingdom.knights.size(); i++)
        {
            write_knight(kingdom.knights[i]); // gets the current knights
        }
    }
}

// selecting a knight function
int select_knight(const kingdom_data &kingdom)
{
    for (int i=0; i<kingdom.knights.size();i++)
    {
        write("[" + to_string(i+1) + "]");
        write_line(kingdom.knights[i].name);
    }
    int index =read_integer("Plz select knight and index number: ");
    while (index>kingdom.knights.size())
    {
        index =read_integer("Enter valid index: ");
    }
    return index-1;
}

void delete_knight(kingdom_data &kingdom) // procedure allows the user to delete the knight
{
    int index = 0;
    index = select_knight(kingdom) - 1;
    if (index >= 0 and index < kingdom.knights.size())
    {
        int last_idx;
        last_idx = kingdom.knights.size() - 1;
        kingdom.knights[index] = kingdom.knights[last_idx];
        kingdom.knights.pop_back();
    }
}

int select_tool(const knight_data &knights) // selecting a knight function
{
    write_knight(knights);
    int i = -1;
    while (i < 1 or i > knights.tools.size())
    {
        write_line("Select a tool like 1 coins,2 sheield");
        i = read_integer("Select a Tool: ");
        if (i < 1 or i > knights.tools.size())
        {
            write_line("Invalid option! Tool does not exist!");
        }
    }
    return i - 1;
}

void delete_tool(knight_data &knights, int index) // used to remove a tool
{
    if (index >= 0 and index < knights.tools.size())
    {
        int last_idx;
        last_idx = knights.tools.size() - 1;
        knights.tools[index] = knights.tools[last_idx];
        knights.tools.pop_back();
    }
}

void delete_knight_tool(knight_data &knights) // deletes a knight from the kingdom
{
    int i = select_tool(knights);
    delete_tool(knights, i);
}

kingdom_data read_kingdom() // enables the user to read Fthe kingdom name and output the result
{
    kingdom_data result;
    result.name = read_string("Enter Kingdom name: ");
    return result;
}

void query_knight(kingdom_data &kingdom) //  query knight
{
    int idx_of = select_knight(kingdom);
    write_knight(kingdom.knights[idx_of]);
}

void update_knight(knight_data &knight) // update knight 
{
    int option;
    do
    {
        write_line();
        write_line("==Update Knight==");
        write_knight(knight);
        write_line();

        option = read_knight_update_option();
        switch (option)
        {
        case UPDATE_NAME:
            knight.name = read_string("Enter new name ");
            break;
        case UPDATE_AGE:
            knight.age = read_integer("Enter a new age ");
            break;
        case ADD_TOOLS:
            write_line("Add tools sheild, coins, bettary.");
            knight.tools.push_back(read_string("Enter a tool to add "));
            break;
        case DEL_TOOLS:
            write_line("Del tools like sheild, coins, bettary.");
            delete_knight_tool(knight); // calls the previous delete toolfunction

            break;
        case FINISH_UPDATE:
            break;
        default:
            write_line("Please select a valid option");
        }
    } while (option != FINISH_UPDATE);
}

void update_kingdom(kingdom_data &kingdom)//Update kingdom
{
    int option;
    int kingdom_menu;// creating kingdom menu
    do
    {
        write_line();
        write_line("==== Kingdom Menu ====");

        option = read_kingdom_create_option();
        switch (option)
        {
        case ADD_KNIGHT: // add the knight to the kingdom
            add_knight(kingdom);
            break;
        case QUERY_KNIGHT: // needs to use the select function
            query_knight(kingdom);
            break;
        case UPDATE_KNIGHT: // will call the existing knight menu// requires the select knight function to work too
            kingdom_menu = select_knight(kingdom);
            update_knight(kingdom.knights[kingdom_menu]);
            break;
        case DELETE_KNIGHT: // will remove the knight at index i
            delete_knight(kingdom);
            break;
        case DISPLAY_KINGDOM:
            write_kingdom(kingdom);
            break;
        case END_KINGDOM:
            break;
        default:
            write_line("Please select a valid option");
        }
    }
    while (option != END_KINGDOM)
        ;
}

int main()
{
    kingdom_data my_kingdom = read_kingdom();
    write_kingdom(my_kingdom);
    update_kingdom(my_kingdom);

    write_line(" O O");
    write_line("{o)xxx|===============- * -===============|xxx(o}");
    write_line(" O Exiting the Realm O");
    return 0;
}
