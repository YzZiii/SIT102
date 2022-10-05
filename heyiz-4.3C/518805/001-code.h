#ifndef TERMINAL_USER_INPUT
#define TERMINAL_USER_INPUT
#include <string>
using std::string;
/**
 * The function will Prompt the user for inout and reads the text that the user enters
 * The function read an integer value from the console, we first have to input the integer value in a string and then convert it to an integer.
 *
 * @param prompt The display show message ask user input
 * @return int The text user enters as a string
 */
string read_string(string prompt);



/**
 * The function will prompts Minimum value for a variable of type int and Maximum value for a variable of type int.
 * The functon double read_double to make sure it checks if the user has entered a vaild number before doing the conversion,
 * And also we give double range to read a number between minmum and maximum inclusive values,read double between 0.0 and 1.0.
 * Read_boolean function to ask "yes"/"no" type questions.User should be able to type"yes"or"y"(for true) and "no" or "n" for false
 * @param prompt  The display show message ask user input
 * @return The text user enters as a integer
 */
int read_integer(string prompt);
int read_integer(string prompt, int min, int max);

/**
 * The function will prompts Minimum value for a variable of type int and Maximum value for a variable of type double.
 * The functon double read_double to make sure it checks if the user has entered a vaild number before doing the conversion,
 * And also we give double range to read a number between minmum and maximum inclusive values,read double between 0.0 and 1.0.
 * @param prompt  The display show message ask user input
 * @return The text user enters as a double
 */
double read_double(string prompt);
double read_double(string prompt, double min, double max);

/**
 * Read_boolean function to ask "yes"/"no" type questions.User should be able to type"yes"or"y"(for true) and "no" or "n" for false
 * @param prompt  The display show message ask user input
 * @return The text user enters as a boolean value
 */
bool read_boolean(string prompt);

#endif