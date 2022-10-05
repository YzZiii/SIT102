// Pointer variables - address and value, Pass by value and Pass by pointer
#include "splashkit.h"
#include <string>
#include <iostream>
#include <cstdlib>

#define CONSOLE_RED "\x1b[31m"
#define CONSOLE_GREEN "\x1b[32m"
#define CONSOLE_YELLOW "\x1b[33m"
#define CONSOLE_BLUE "\x1b[34m"
#define CONSOLE_RESET "\x1b[0m"

using namespace std;

void swap_pass_by_value(string s, string name) // part B
{
    // 1. Print the passed in values to Terminal
    write_line("\nInside swap_pass_by_value");
    write_line("---------------------------");
    write_line("Parameters passed by value : \ts = " + s + ",\t\t name = " + name);

    // 2. Apply a simple swap mechanism
    string temp = s;
    s = name;
    name = temp;

    // 3. Print the updated values to the Terminal just after the swap
    write_line("Values just after swap  : \ts = " + s + ",\t\t name = " + name);
}

void swap_pass_by_pointer(string *z, string *name_pointer)
{   
    write_line("\nInside swap_pass_by_value");
    write_line("---------------------------");
    write_line("Parameters passed by value : \ts = " + *z + ",\t\t name = " + *name_pointer);

    // apply a simple swap mechanism
    string temp = *z;
    *z = *name_pointer;
    *name_pointer = temp;

    // print the update after swap
    write_line("Values just after swap  : \ts = " + *z + ",\t\t name = " + *name_pointer);
}

void pretty_print(string message)
{
    write_line("\n\n");
    write_line("*******************************************************************************************");
    write_line("\t\t" + message + "\t\t");
    write_line("*******************************************************************************************");
}

void pointer_var_info()
{
    double d = 7.99, *x;
    string s = "SIT102", *z;
    string name;
    cout << "input your name please: ";
    cin >> name;
    string *name_pointer;
    name_pointer = &name;

    // initialisation of pointers
    x = &d;
    z = &s;

    write_line(CONSOLE_YELLOW);
    pretty_print("Part A: Ordinary var d, s");
    write_line("Ordinary var\t\t --->  d  = " + to_string(d) + ",\t\t s  = " + s);
    write_line("Ordinary var ADDRESS\t --->  &d = " + to_string((int64_t)&d) + ",\t &s = " + to_string((int64_t)&s));

    // part A
    write_line(CONSOLE_RED);
    pretty_print("Part A: Pointer var x, z");
    // < Start your code here to obtain and show the pointer variables' information onto Terminal >
    write_line("Pointer var\t\t --->  x  = " + to_string((int64_t)x) + ",\t\t z  = " + to_string((int64_t)z));
    write_line("Ordinary var ADDRESS\t --->  &d = " + to_string((int64_t)&x) + ",\t &s = " + to_string((int64_t)&z));
    write_line(CONSOLE_RESET);
    // end part A

    // part B - pass by pointer
    pretty_print("Part B: Pass by value versus Pass by pointer");

    // pass by value
    write_line(CONSOLE_GREEN);
    write_line("\nPass by value");
    swap_pass_by_value(s, name);
    write_line("\nBack in pointer_var_info()");
    write_line("---------------------------");
    write_line("After swap call in pointer_var_info()    : \ts = " + s + ",\t\t name = " + name);
    write_line(CONSOLE_RESET);

    // < Start your code here >
    write_line(CONSOLE_RED);
    write_line("\nPass by reference");
    swap_pass_by_pointer(z, name_pointer);
    write_line("\nBack in pointer_var_info()");
    write_line("---------------------------");
    write_line("After swap call in pointer_var_info()    : \ts = " + *z + ",\t\t name = " + *name_pointer);
    write_line(CONSOLE_RESET);

    // end part B
}

int main()
{
    write_line("Let's try pointers for data manipulation!");
    pointer_var_info();

    return 0;
}