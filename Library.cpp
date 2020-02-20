#include "Book.cpp"
#include <vector>

class Library
{

private:
	std::vector<Book> books;
	int id;
	int scanTime;
	int shipBooksPerDay;

public:
	Library(int id, std::vector<Book> books, int scanTime, int shipBooksPerDay) : 
		id(id), scanTime(scanTime), shipBooksPerDay(shipBooksPerDay)
	{
		this->books = books;
	}

	std::vector<Book> getBooks() { return books; }
	int getId() { return id; }
	int getScanTime() { return scanTime; }
	int getShipBooksPerDay() { return shipBooksPerDay; }

};