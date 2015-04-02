#pragma once

#include <vector>
#include "Book.h"
#include "Schedule.h"

class Library
{
private:
    string name;
    string address;
    vector <Book> books;
    Schedule schedule;
public:
    Library();
    Library(string name, string address);
    Library(string name, string address, vector<Book> books, Schedule schedule);
    Library(Library&);
    ~Library();
    Library& operator=(const Library &);
    Library& operator+(Library &);
    string getName() const;
    string getAddress() const;
    int getCount() const;
    vector <Book>& getBooks();
    Schedule& getSchedule();
    void setName(string);
    void setAddress(string);
    void setBooks(vector<Book>);
    void setSchedule(Schedule);
    void printLibraryInfo();
    void printBooks();
    void add(const Book& book);
    void remove(const Book& book);
    void remove(int index);
    bool has(const Book& book);
    Book& get(int i);
//    Book& findBookByName(string);
};
