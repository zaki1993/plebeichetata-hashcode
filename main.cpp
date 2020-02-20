#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include "Book.cpp"
#include "Library.cpp"

Book createBook(int id) {
	return Book(id);
}

Library createLibrary(int id, std::vector<Book> books, int scanTime, int shipBooksPerDay) {
	return Library(id, books, scanTime, shipBooksPerDay);
}

int main() {

	//readInput("test.txt");

	std::string fileName = "test.txt";
	std::fstream infile(fileName);

	if (infile.is_open()) {
		// first line has information for number of books, number of libraries and number of days untill the deadline separated by spaces
		std::string mainLine;
		std::getline(infile, mainLine);
		
		int numberOfLibraries, numberOfBooks, numberOfDays;
		std::istringstream mainLineIs(mainLine);
		mainLineIs >> numberOfLibraries >> numberOfBooks >> numberOfDays;

		// second line contains books ids
		std::string booksLine;
		std::getline(infile, booksLine);

		// initialize map of unique books with key id and value book
		std::map<int, Book> books;
		int currBook = 0;
		std::istringstream booksLineIs(booksLine);
		int id;
		while (currBook <= numberOfBooks && booksLineIs >> id)
		{
			Book book = createBook(id);
			books.insert(std::pair<int, Book>(id, book));
		}

		// each of the next 2 lines contains information of:
		// 1) first line has information for the library, how many books are there, how many days it takes to signup the library and how many books a library can process per 
		// 2) second line contains information for which books are in the library
		std::string libraryInfo;
		std::string booksIdsInLibrary;

		std::vector<Library> libraries;
		int currentLibraryNumber = 0;
		while (std::getline(infile, libraryInfo) && std::getline(infile, booksIdsInLibrary))
		{
			// process line
			std::istringstream libraryInfoIs(libraryInfo);
			int booksInLibraryNumber, scanTime, shipBooksPerDay;
			libraryInfoIs >> booksInLibraryNumber >> scanTime >> shipBooksPerDay;

			// insert all the books for this library
			std::vector<Book> booksInLibrary;
			std::istringstream booksIdsInLibraryIs(booksIdsInLibrary);
			int bookId;
			while (booksIdsInLibraryIs >> bookId)
			{
				Book currentBook = books[bookId];
				booksInLibrary.push_back(currentBook);
			}
			// insert library into the vector of libraries
			Library library = createLibrary(currentLibraryNumber++, booksInLibrary, scanTime, shipBooksPerDay);
			libraries.push_back(library);
		}

		for (int i = 0; i < libraries.size(); i++) 
		{
			Library currentLibrary = libraries.at(i);
			std::cout << "Process library id=" << currentLibrary.getId() << ", scanTime=" << currentLibrary.getScanTime() << ", shipBooksPerDay=" << currentLibrary.getShipBooksPerDay() << std::endl;
			std::vector<Book> libraryBooks = currentLibrary.getBooks();
			for (int j = 0; j < libraryBooks.size(); j++)
			{
				Book currentBook = libraryBooks.at(j);
				std::cout << currentBook.getId() << std::endl;
			}
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