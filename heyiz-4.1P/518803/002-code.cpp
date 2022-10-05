#include "splashkit.h"
#include <string>
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

void user_details()
{
   string name, line, user_name;
   int age;
   user_name = "yi";

   name = read_string("What is your name?: ");
   age = read_integer("What is your age?: ");

   write_line("Hello" + name);

   write("Age: ");
   write_line(age);

   if (to_lowercase(name) == user_name)
   {
      write_line("yizheng he is a student");
      write_line("He like learning code");
   }
   else if (to_lowercase(name) == "tom")
   {
      write_line("Tom is yi roommate");
   }
   else
   {
      write_line("Who you are? ");
   }
}
void play_guess_that_number() // Guess the number
{

   int guess, target;
   guess = 0;
   target = rnd(100) + 1;

   write_line("Guess number between 1 and 100");

   while (guess != target)
   {

      guess = read_integer("Enter guess: ");
      if (guess < target)
      {
         write_line("Sorry, my number is greater than" + to_string(guess));
      }
      else if (guess > target)
      {
         write_line("No, my number is less than" + to_string(guess));
      }
   }
   write_line("Wow...you got it. my number was" + to_string(target));
}

int main()
{
   int option;

   write_line("1: Test your name");
   write_line("2: Guess that number");
   write_line("3: Quit");
   // Choice which one you like
   do
   {
      option = read_integer("choose option: ");

      switch (option)
      {
      case 1:
         user_details();
         break;
      case 2:
         play_guess_that_number();
         break;
      case 3:
         write_line("See you soon");
         break;
      default:
         write_line("Please enter an option from the menu");
      }
   } while (option != 3);
   return 0;
}