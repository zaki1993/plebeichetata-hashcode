#include "Book.cpp"
#include <vector>

class Library
{
private:
	std::vector<Book> books;
	int scanTime;
	int shipBooksPerDay;

public:
	Library(std::vector<Book> books, int scanTime, int shipBooksPerDay) : scanTime(scanTime), shipBooksPerDay(shipBooksPerDay)
	{
		this->books = books;
	}


};