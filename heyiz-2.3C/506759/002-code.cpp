#include "splashkit.h"
#include "terminal_user_input.h"

#define STROUHAL 0.33

//Calculate resultant STROUHAL air speed by reading in freq and amp
double calculate_air_speed( int freq, int amp)
{
    double result;
    result=freq*amp* 0.01 / STROUHAL; 
    return result;
}
// Calculate and dispaly the Air speed
void output_air_speed( string bird_name,int freq, int amp)
{    
   write(bird_name+ ":");
   write_line(calculate_air_speed(freq, amp));
}
int main()
{
    string name,bird_name;
    int age,freq,amp; 
    name = read_string("What is your name: ");
    age = read_integer("What is your age: ");
    bird_name = read_string("What is the bird name?: ");
    freq =read_integer("freq:");
    amp = read_integer("amp: ");


    output_air_speed(bird_name,freq,amp);
    write_line("* End of Program.*");
    return 0;
}

















