// Copyright 2015 <precisef0x>

#pragma once

#include <vector>
#include <string>
#include "Book.h"
#include "Schedule.h"

using ::std::vector;

class Library {
 private:
  string name;
  string address;
  vector<Book> books;
  Schedule schedule;

 public:
  Library();
  Library(const string& name, const string& address);
  Library(const string& name, const string& address, vector<Book> books,
          Schedule schedule);
  Library(const Library& library);
  ~Library();
  Library& operator=(const Library& library);
  Library& operator+(const Library& library);
  Book& operator[](int index);
  string getName() const;
  string getAddress() const;
  int getCount() const;
  vector<Book>& getBooks();
  Schedule& getSchedule();
  void setName(const string& name);
  void setAddress(const string& address);
  void setBooks(vector<Book> books);
  void setSchedule(const Schedule& schedule);
  void printLibraryInfo();
  void printBooks();
  void add(const Book& book);
  void remove(const Book& book);
  void remove(int index);
  bool has(const Book& book);
  Book& get(int i);
};
