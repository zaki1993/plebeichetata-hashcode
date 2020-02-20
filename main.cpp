#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Book.cpp"
#include "Library.cpp"

//Book createBook(int id) {
//	return new Book(id);
//}
//
//Library createLibrary(std::vector<Books> books, int scanTime, int shipBooksPerDay) {
//	return new Library(books, scanTime, shipBooksPerDay);
//}

int main() {

	//readInput("test.txt");

	std::string fileName = "test.txt";
	std::fstream infile(fileName);

	if (infile.is_open()) {
		// first line has information for number of books, number of libraries and number of days untill the deadline separated by spaces
		std::string mainLine;
		std::getline(infile, mainLine);
		
		int numberOfLibraries, numberOfBooks, numberOfDays;
		std::istringstream is(mainLine);
		mainLine >> numberOfLibraries >> numberOfBooks >> numberOfDays;

		// second line contains books ids
		std::string booksLine;
		std::getline(infile, booksLine);

		// each of the next 2 lines contains information of
		// 1) first line has information for the library, how many books are there, how many days it takes to signup the library and how many books a library can process per 
		// 2) second line contains information for which books are in the library
		std::string libraryInfo;
		std::string booksInLibrary;

		while (std::getline(infile, libraryInfo) && std::getline(infile, booksInLibrary))
		{
			// process line
			std::cout << libraryInfo << std::endl;
			std::cout << booksInLibrary << std::endl;
		}

		// close file
		infile.close();
	}
	else
	{
		std::cout << "Could not open file with name " << fileName << std::endl;
	}

	return 0;
}