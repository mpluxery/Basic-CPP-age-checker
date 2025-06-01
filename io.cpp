#include <iostream>
#include <sstream>
#include <string>

int main() {
    int age = 0;
    bool valid = false;
    char null = '\0';

    while (!valid)
    {
        std::cout << "Enter Age: ";

        std::string line;
        getline(std::cin, line);

        std::stringstream is(line);


        if (!(is >> age) || (is >> std::ws && is.get(null)) || age >= 100 || age <=0)
            std::cout << "Dude be for real!" << std::endl;
        else
            valid = true ; 
    }

    std::cout << "Youer " << age << " years old, seems legit!" << std::endl;
    return 0;
}


