#ifndef AYAP_2_Console_Library_h
#define AYAP_2_Console_Library_h

#include <vector>
#include "Book.h"
#include "Schedule.h"

class Library
{
private:
    string name;
    string address;
    vector<Book>books;
    Schedule schedule;
public:
    Library();
    Library(string name, string address, vector<Book> books, Schedule schedule);
    Library(Library&);
    ~Library();
    Library& operator=(const Library &);
    Library& operator+(Library &);
    string getName() const;
    string getAddress() const;
    int getBooksNumber() const;
    vector<Book>& getBooks();
    Schedule& getSchedule();
    void setName(string);
    void setAddress(string);
    void setBooks(vector<Book>);
    void setSchedule(Schedule);
    void printLibraryInfo();
    void printBooks();
    void addBook(Book);
    void deleteBook(Book&);
    bool containsBook(Book&);
//    Book& findBookByName(string);
};

#endif
