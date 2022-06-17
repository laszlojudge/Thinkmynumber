//
//  main.cpp
//  Thinkmynumber
//
//  Created by Biro Laszlo on 17.06.22.
//

#include <iostream>
#include <time.h>

void welcome();
bool game();

int main(int argc, const char * argv[]) {
    
    welcome();
    
    return 0;
}

void welcome()
{
    std::cout << "Welcome in Thinkmynumber.\nYou have to figure it out what number i think." << std::endl;
    bool play = true;
    while (play)
        play = game();
}
bool game()
{
    srand(unsigned(time(NULL)));
    int number = rand() % 100;
    int in;
    bool gotit = false;
    int tiplower = 0;
    int tiphigher = 100;
    while(!gotit)
    {
        std::cout << "Write a number: ";
        std::cin >> in;
        if(in == number)
        {
            std::cout << "You found it!" << std::endl;
            gotit = true;
        } else if (in < number)
        {
            std::cout << "Try higher(" << in << "-" << tiphigher << "): " << std::endl;
            tiplower = in;
        } else if (in > number)
        {
            std::cout << "Try lower(" << tiplower << "-" << in << ")" << std::endl;
            tiphigher = in;
        }
    }
    std::cout << "Want a new game?(y/n): ";
    char cIn;
    std::cin >> cIn;
    if (cIn == 'y')
        return true;
    else
        return false;
}
