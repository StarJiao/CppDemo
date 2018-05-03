#include <string>
#include <iostream>

using namespace std;

class Book
{
	private :
	int id;
	string name;
	double price;

	public :
	void setId(int id);
	int getId();
	void setName(string name);
	string getName();
	void setPrice(double price);
	double getPrice();
	void display();
};

void Book::setId(int id)
{
	this->id = id;
}
int Book::getId()
{
	return this->id;
}
void Book::setName(string name)
{
	this->name = name;
}
string Book::getName()
{
	return this->name;
}
void Book::setPrice(double price)
{
	this->price = price;
}
double Book::getPrice()
{
	return this->price;
}
void Book::display()
{
	cout<< "Book id :" << this->id << endl;
	cout<< "Book name :" << this->name << endl;
	cout<< "Book price :" << this->price << endl;
}
