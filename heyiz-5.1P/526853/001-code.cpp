#include "splashkit.h"
#include <string>
using namespace std;

#define ENERGY 4.18
//#define Joules = Calorie * 4.18//Calorie to Joules is calculated as
//#define Calorie = Joules  / 4.18//Joules to Calorie is calculated as

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
double read_double(string prompt)
{
   string line;
   line = read_string(prompt);
   return convert_to_double(line);
}
double calorie_to_joules(double Calorie)
{
   double result;
   result = Calorie * 4.18;
   return result;
}
double joules_to_calorie(double Joules)
{
   double result;
   result = Joules / 4.18;
   return result;
}
void cal_to_jou()
{
   double calorie;
   calorie = read_double("The caloris to joules is: ");
   write("Result is: ");
   write_line(calorie_to_joules(calorie));
}
void jou_to_cal()
{
   double Joules;
   Joules = read_double("The joules to caloris is: ");
   write("Result is: ");
   write_line(joules_to_calorie(Joules));
}
int main()
{

   int option;
   do
   {
      write_line("1:Calorie to Joules  ");
      write_line("2:Joules to Calorie");
      write_line("3: Quit");
      // Choice which one you like

      option = read_integer("Choose the option: ");
      switch (option)
      {
      case 1:
         cal_to_jou();
         break;
      case 2:
         jou_to_cal();
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