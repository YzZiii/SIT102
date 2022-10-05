#include "splashkit.h"
#include <string>

using namespace std;

#define STROUHAL 0.33;
#define PI 3.14;
//Calculate resultant STROUHAL air speed by reading in freq and amp
double calculate_air_speed(int freq, int amp)
{
    double result;
    result=freq*amp* 0.01 / STROUHAL; //amp is converted form CM to M
    return result;
}

// Output Calculate and dispaly the Air speed
void output_air_speed( string bird_name, int freq, int amp, int age)
{
    
     write(bird_name + ":");
     write_line(calculate_air_speed(freq, amp));
}
// Return a string of the input line from the terminal
string read_string(string prompt)
{
   string result;
   write(prompt);
   result = read_line();
   return result;
}
// user input value
int read_integer(string prompt)
{
    string line;
    line = read_string(prompt);
    return convert_to_integer(line);
}
double read_double(string prompt)
{
    string line;
    line=read_string(prompt);
    return convert_to_double(line);
}
// Calculate circle area using the users inouts
double circle_area(double radius)
{
    double result;
    result =radius*radius*PI;
    return result;
}
void output_circle_area( double radius)
{
    write_line(to_string( radius) +":");
    write("area of circle is: ");
    write_line(circle_area(radius));
}
int main()
{
    
    string name,bird_name;
    int freq,amp,age; 
    double radius;
    
    name = read_string("What is your name: ");
    age = read_integer("What is your age?: ");
    bird_name = read_string("What is the bird name?: ");
    freq =read_integer("Frequency of bird: ");
    amp = read_integer("Amplitude of bird: ");
    radius = read_double("What is the raduis: ");
  
    output_air_speed(bird_name,freq,amp,age);
    output_circle_area(radius);
   
    write_line("* End of Program.*");
    return 0;
}