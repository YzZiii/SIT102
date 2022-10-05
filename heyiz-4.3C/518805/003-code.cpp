#include "splashkit.h"
#include "terminal_user_input.h"
using namespace std;

int main()
{
   string name;
   int age;
   double height;
   bool test;
   bool again;

   do
   {
      name = read_string("Enter your name: ");
      write_line("Welcome " + name);

      age = read_integer("Enter your age: ",1,200);
      write_line("Great you are " + to_string(age));
      write_line(" -eg '3.1415'and 'fred' ");
      
      height = read_double("Enter your height: ", 1, 200);
      write_line("read boolean test errors with text other then yes and no");

      test = read_boolean("Enter test value: ");
      write_line(to_string(test));

      write_line("Got values");
      write("String: ");
      write_line(name);
      write("Integer: ");
      write_line(age);
      write("Double: ");
      write_line(height);
      write("Boolean: ");
      if (test)
         write_line("yes");
      else
         write_line("no");

      again = read_boolean("Try this again: ");
   } while (again);

   return 0;
}
