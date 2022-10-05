#ifndef TEMINAL_USER_INPUT
#define TERMINAL_USER_INPUT
#include <string>
using std:: string;
/**
 * The function will prompts the user for input and reads the text that the user enters
 * The functon at the Terminal. This will read in a line of text and return this as string
 * 
 * @param prompt  The display show message ask user input
 * @return The text user enters as a string
 */
string read_string (string prompt); //Prompts the user for inout and reads the text that theuser enters

/**
 * The function will prompt the user for input and reads the text that the user enters
 * The function is read in a line of text and return it as integer
 * 
 * @param prompt The display show message ask user input
 * @return int The text user enters as a string
 */
int read_integer(string prompt); 
#endif