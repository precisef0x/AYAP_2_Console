#include "Library.h"

Library::Library()
{
    name = "Unknown library";
    address = "Unknown place";
    booksNumber = 0;
}

Library::Library(string name, string address, vector<Book> books, Schedule schedule)
{
    this->name = name;
    this->address = address;
    this->books = books;
    this->booksNumber = (int)books.size();
    this->schedule = schedule;
}

Library::Library(Library& input)
{
    this->name = input.name;
    this->address = input.address;
    this->books = input.books;
    this->booksNumber = input.booksNumber;
    this->schedule = input.schedule;
}

Library::~Library()
{

}

Library& Library::operator=(const Library &input)
{
    Library *newLibrary = new Library(input.name, input.address, input.books, input.schedule);
    return *newLibrary;
}

string Library::getName()
{
    return name;
}

string Library::getAddress()
{
    return address;
}

int Library::getBooksNumber()
{
    return booksNumber;
}

vector<Book> Library::getBooks()
{
    return books;
}

Schedule Library::getSchedule()
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
    booksNumber = (int)arg1.size();
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
    cout << "Books number: " << booksNumber << endl;
}

void Library::printBooks()
{
    if(booksNumber==0) cout << "No books in this library" << endl;
    else
    {
        for(int i=0;i<booksNumber;i++)
        {
            books[i].printBookInfo();
        }
    }
}

void Library::addBook(Book arg1)
{
    books.emplace_back(arg1);
    booksNumber++;
}

void Library::deleteBook(Book& arg1)
{
    vector<Book>::iterator position = find(books.begin(), books.end(), arg1);
    if (position != books.end()) // == vector.end() means the element was not found
    {
        books.erase(position);
        booksNumber--;
    }
    else cout << "Deletion error! There is no such book in this library" << endl;
}

bool Library::containsBook(Book& arg1)
{
    if(find(books.begin(), books.end(), arg1) != books.end()) return true;
    else return false;
}

//Book& Library::findBookByName(string)
//{
//    return NULL;
//}
