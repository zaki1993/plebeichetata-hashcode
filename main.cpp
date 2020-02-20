#include <iostream>
#include <fstream>

// Reads file with the following format. Each line will contain numbers separated by spaces.
void readInput(std::string file_name)
{
	std::ifstream infile(file_name);
	std::string line;
	while (infile >> line)
	{
		// process line
		std::cout << line << std::endl;
	}
}

int main() {

	readInput("test.txt");
	int x;
	std::cin >> x;
	return 0;
}