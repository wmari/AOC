#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> splitString(const std::string& input, const std::string& separators) {
    std::vector<std::string> tokens;
    std::istringstream stream(input);
    std::string token;

    while (std::getline(stream, token)) {
        size_t start = 0, end = 0;

        while ((end = token.find_first_of(separators, start)) != std::string::npos) {
            if (end != start) {
                tokens.push_back(token.substr(start, end - start));
            }
            start = end + 1;
        }

        if (start < token.length()) {
            tokens.push_back(token.substr(start));
        }
    }

    return tokens;
}

// part 1
// int main()
// {
//     int nbRed = 12;
//     int nbBlue= 14;
//     int nbGreen = 13;
// 	int retur = 0;
//     std::ifstream input("input");
// 	if (!input.is_open())
// 		return (0);
// 	std::string	line;
//     while (std::getline(input, line))
//     {
// 		int ret = 1;
// 		int id;
// 		int nb;
// 		std::vector<std::string> result = splitString(line, ":,;");
// 		for (std::string param : result)
// 		{
// 			if (param.find("Game") != std::string::npos)
// 			{
// 				id = std::atoi(param.substr(5).c_str());
// 				std::cout << param.substr(5).c_str() << std::endl;
// 			}
// 			else if (param.find("red") != std::string::npos)
// 			{
// 				nb = std::atoi(param.c_str());
// 				if (nb > nbRed)
// 					ret = 0;
// 			}
// 			else if (param.find("blue") != std::string::npos)
// 			{
// 				nb = std::atoi(param.c_str());
// 				if (nb > nbBlue)
// 					ret = 0;
// 			}
// 			else if (param.find("green") != std::string::npos)
// 			{
// 				nb = std::atoi(param.c_str());
// 				if (nb > nbGreen)
// 					ret = 0;
// 			}
// 		}
// 		std::cout << "id = " << id << std::endl;
// 		if (ret)
// 			retur += id;
//     }
// 	std::cout << retur << std::endl;
// 	return 0;
// }

// part 2
int main()
{
    int nbRed;
    int nbBlue;
    int nbGreen;
	int retur = 0;
    std::ifstream input("input");
	if (!input.is_open())
		return (0);
	std::string	line;
    while (std::getline(input, line))
    {
		int id;
		int nb;
		nbRed = 0;
		nbBlue = 0;
		nbGreen = 0;
		std::vector<std::string> result = splitString(line, ":,;");
		for (std::string param : result)
		{
			if (param.find("Game") != std::string::npos)
			{
				id = std::atoi(param.substr(5).c_str());
				std::cout << param.substr(5).c_str() << std::endl;
			}
			else if (param.find("red") != std::string::npos)
			{
				nb = std::atoi(param.c_str());
				if (nb > nbRed)
					nbRed = nb;
			}
			else if (param.find("blue") != std::string::npos)
			{
				nb = std::atoi(param.c_str());
				if (nb > nbBlue)
					nbBlue = nb;
			}
			else if (param.find("green") != std::string::npos)
			{
				nb = std::atoi(param.c_str());
				if (nb > nbGreen)
					nbGreen = nb;
			}
		}
		std::cout << "id = " << id << std::endl;
		retur += nbRed * nbBlue * nbGreen;
    }
	std::cout << retur << std::endl;
	return 0;
}