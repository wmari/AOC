#include <fstream>
#include <iostream>
#include <string>

int main()
{
    int nbRed = 12;
    int nbBlue= 14;
    int nbGreen = 13;

    std::ifstream input("input");
	if (!input.is_open())
		return (0);
	std::string	line;

    while (std::getline(input, line))
    {
        
    }
}