#pragma once
#include <iostream>

class Book
{
private:
	int id;
public:
	Book(int id): id(id) {}
	int getId() const { return id; }
	int setId(int idm) { id = idm; }
};