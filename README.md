# Valid Age Checker in C++

## Description
This is a simple C++ program that prompts the user to enter their age and validates that the input is a numeric value between 1 and 99, with no extra characters. If the input does not meet these criteria, the program displays an error message (“Dude be real!”) and asks again until a valid age is entered. Once a valid number is provided, it outputs a confirmation message including the entered age.

## Installation and Build
1. Make sure you have a C++ compiler installed (for example, g++).  
2. Save the source code below into a file named `io.cpp`.  
3. Open a terminal in the same directory as `io.cpp` and run:

  g++ io.cpp -o valid_age
   
Usage
After a successful build, execute the program by typing:


./valid_age
When prompted:

Enter Age:
type a number between 1 and 99 and press Enter.

If the input is invalid (non-numeric characters, numbers outside 1–99, or extra characters), the program will print:

Dude be for real!
and prompt again.

Once a valid age is entered, you will see:

You are <age> years old, seems legit!
For example:

You are 25 years old, seems legit!
Source Code (io.cpp)

#include <iostream>
#include <sstream>
#include <string>

int main()
{
    int age = 0;
    bool valid = false;
    char null = '\0';

    while (!valid)
    {
        std::cout << "Enter Age: ";

        std::string line;
        std::getline(std::cin, line);

        std::stringstream is(line);

        // Validate:  
        // 1. Attempt to extract an integer into `age`.  
        // 2. Check for any extra characters after the number.  
        // 3. Ensure age is between 1 and 99 (inclusive).
        if (!(is >> age) || (is >> std::ws && is.get(null)) || age >= 100 || age <= 0)
            std::cout << "Dude be for real!" << std::endl;
        else
            valid = true;
    }

    std::cout << "You are " << age << " years old, seems legit!" << std::endl;
    return 0;
}
How It Works
Variables

age (int): Stores the user’s age.

valid (bool): Becomes true once a valid age is entered.

null (char): Used to detect any extra character after the numeric input.

Input Loop

The while (!valid) loop repeatedly prompts the user to enter their age.

std::getline(std::cin, line) reads the entire line of input as a string.

String Parsing and Validation

A std::stringstream named is is initialized with the input line.

is >> age attempts to parse an integer; if this fails, the input is not a valid number.

(is >> std::ws && is.get(null)) checks for any non-whitespace characters remaining in the stream after parsing the integer (for example, letters or extra digits). If it finds anything, the input is considered invalid.

The conditions age >= 100 || age <= 0 ensure the age is within the range [1, 99].

If any validation step fails, the program prints “Dude be for real!” and repeats the prompt.

Successful Input

When a valid age is provided, the loop exits and the program prints:


You are <age> years old, seems legit!
Exit

The program returns 0 to indicate successful execution.
