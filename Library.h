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
    Library(const string& name, const string& address);
    Library(const string& name, const string& address, vector<Book> books, Schedule schedule);
    Library(const Library&);
    ~Library();
    Library& operator=(const Library &);
    Library& operator+(const Library &);
    Book& operator[](int);
    string getName() const;
    string getAddress() const;
    int getCount() const;
    vector <Book>& getBooks();
    Schedule& getSchedule();
    void setName(const string&);
    void setAddress(const string&);
    void setBooks(vector<Book>);
    void setSchedule(Schedule);
    void printLibraryInfo();
    void printBooks();
    void add(const Book& book);
    void remove(const Book& book);
    void remove(int index);
    bool has(const Book& book);
    Book& get(int i);
};
