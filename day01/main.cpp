#include <iostream>
#include <string>
#include <fstream>

int get_num(int i)
{
	switch (i)
	{
		case 0:
			return (1);
		case 1:
			return (2);
		case 2:
			return (3);
		case 3:
			return (4);
		case 4:
			return (5);
		case 5:
			return (6);
		case 6:
			return (7);
		case 7:
			return (8);
		case 8:
			return (9);
		case 9:
			return (1);
		case 10:
			return (2);
		case 11:
			return (3);
		case 12:
			return (4);
		case 13:
			return (5);
		case 14:
			return (6);
		case 15:
			return (7);
		case 16:
			return (8);
		case 17:
			return (9);
	}
	return (0);
}

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
		return (get_num(lowest));
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
		return (get_num(lowest));
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