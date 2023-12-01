#include <iostream>
#include <string>
#include <fstream>

int getFirstd(std::string line)
{
	std::string tab[18] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
	std::string::size_type n = std::string::npos;
	int lowest = -1;
	for (int i = 0; i < 18; i++)
	{
		if (line.find(tab[i]) != std::string::npos)
		{
			if (n == std::string::npos)
			{
				n = line.find(tab[i]);
				lowest = i;
			}
			else if (n > line.find(tab[i]))
			{
				n = line.find(tab[i]);
				lowest = i;
			}
		}
	}
	if (lowest != -1)
		return ((lowest % 9) + 1);
	return (0);
}

int getLastd(std::string line)
{
	std::string tab[18] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
	std::string::size_type n = std::string::npos;
	int lowest = -1;
	for (int i = 0; i < 18; i++)
	{
		if (line.rfind(tab[i]) != std::string::npos)
		{
			if (n == std::string::npos)
			{
				n = line.rfind(tab[i]);
				lowest = i;
			}
			else if (n < line.rfind(tab[i]))
			{
				n = line.rfind(tab[i]);
				lowest = i;
			}
		}
	}
	if (lowest != -1)
		return ((lowest % 9) + 1);
	return (0);
}

int main()
{
	std::ifstream input("input");
	if (!input.is_open())
		return (0);
	std::string	line;
	int total = 0;
	int first;
	int last;
	int count = 0;
	while(std::getline(input, line))
	{
		if (count < 5)
		{
			std::cout << total << std::endl;
			count++;
		}
		total += (getFirstd(line) * 10)+ getLastd(line);
	}
	input.close();
	std::cout << total << std::endl;
}