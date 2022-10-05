#include "splashkit.h"
#include <vector>
#include <string>
using std::vector;
using namespace std;

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

int total_length(const vector<string> &names)
{
     int result = 0;

     for (int i = 0; i < names.size(); i++)
     {
          string name = names[i];
          result += name.length();
     }
     return result;
}
bool contains(vector<string> &names, string name)
{
     for (int i = 0; i < names.size(); i++)
     {
          if (to_lowercase(names[i]) == to_lowercase(name))
          {
               return true;
          }
     }
     return false;
}
string longest_name(vector<string> &names)
{
     string max;
     max = names[0];
     for (int i = 1; i < names.size(); i++)
     {
          if (max.length() < names[i].length())
          {
               max = names[i];
          }
     }
     return max;
}

int index_of(const vector<string> &names, string name)
{
     for (int i = 0; i < names.size(); i++)
     {
          if (to_lowercase(names[i]) == to_lowercase(name))
          {
               return i; 
          }
     }
     return  -1; 
}

void print_summary(vector<string> &names)
{
     write("SUMMARY: ");
     write("\n");
     for (int i = 0; i < names.size(); i++)
     {
          write_line(names[i]);
     }
     int total;
     total = total_length(names);
     write("Total lenghth: ");
     write_line(total);
     write("The longest name is: ");
     write_line(longest_name(names));
     write("The index of my name is: ");
     write_line(index_of(names, "yi"));
}

void change_name(vector<string> &names)
{
     string newname;
     string oldname;
     oldname = read_string("Which name you want change?");
     newname = read_string("Enter new name: ");
     if (contains(names, oldname))
     {
          int i;
          i = index_of(names, oldname);
          names[i] = newname;
     }
     else
     {
          write_line("The name was not.....");
     }
}

int main()
{

     string name;
     vector<string> names;
     int i = 0;
     int size = read_integer("How many names you want add? ");
     while (i < size)
     {
          names.push_back(read_string("Enter a name: "));
          i++;
     }
     print_summary(names);
     write_line(index_of(names, "yi"));
     change_name(names);

     print_summary(names);

     return 0;
}
