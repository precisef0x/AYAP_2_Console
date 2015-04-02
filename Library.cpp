#include "Library.h"

Library::Library()
{
    name = "Unknown library";
    address = "Unknown place";
}

Library::Library(string name, string address)
{
    this->name = name;
    this->address = address;
}

Library::Library(string name, string address, vector<Book> books, Schedule schedule)
{
    this->name = name;
    this->address = address;
    this->books = books;
    this->schedule = schedule;
}

Library::Library(Library& input)
{
    this->name = input.name;
    this->address = input.address;
    this->books = input.books;
    this->schedule = input.schedule;
}

Library::~Library()
{
    books.clear();
}

Library& Library::operator=(const Library &input)
{
    this->name = input.name;
    this->address = input.address;
    this->books = input.books;
    this->schedule = input.schedule;
    return *this;
}

Library& Library::operator+(Library &input)
{
    Library *newLibrary = new Library();
    newLibrary->setName(this->getName() + " & " + input.getName());
    vector<Book> newVector = this->getBooks();
    newVector.insert( newVector.end(), input.getBooks().begin(), input.getBooks().end());
    newLibrary->setBooks(newVector);
    newLibrary->setAddress(this->getAddress() + " & " + input.getAddress());
    newLibrary->setSchedule(this->getSchedule() + input.schedule);
    return *newLibrary;
}

string Library::getName() const
{
    return name;
}

string Library::getAddress() const
{
    return address;
}

int Library::getCount() const
{
    return (int)books.size();
}

vector<Book>& Library::getBooks()
{
    return books;
}

Schedule& Library::getSchedule()
{
    return schedule;
}

void Library::setName(string arg1)
{
    name = arg1;
}

void Library::setAddress(string arg1)
{
    address = arg1;
}

void Library::setBooks(vector<Book> arg1)
{
    books = arg1;
}

void Library::setSchedule(Schedule arg1)
{
    schedule = arg1;
}

void Library::printLibraryInfo()
{
    cout << "Library \"" << name << "\":" << endl;
    cout << "Opened from " << schedule.printOpen() << " to " << schedule.printClose() << endl;
    cout << "Address: " << address << endl;
    cout << "Books number: " << books.size() << endl;
}

void Library::printBooks()
{
    if(getCount()==0) cout << "No books in this library" << endl;
    else
    {
        for(int i=0;i<getCount();i++)
        {
            books[i].printBookInfo();
        }
    }
}

void Library::add(const Book& book)
{
    books.emplace_back(book);
}

void Library::remove(const Book& book)
{
    vector<Book>::iterator position = find(books.begin(), books.end(), book);
    if (position != books.end())
    {
        books.erase(position);
    }
    else cout << "Deletion error! There is no such book in this library" << endl;
}

void Library::remove(int index)
{
    if(index <= getCount()) books.erase(books.begin() + index);
    else cout << "No book at index" << index << " found";
}

bool Library::has(const Book& book)
{
    if(find(books.begin(), books.end(), book) != books.end()) return true;
    else return false;
}

//Book& Library::findBookByName(string)
//{
//    return NULL;
//}
