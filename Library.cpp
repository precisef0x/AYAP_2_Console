// Copyright 2015 <precisef0x>

#include <string>
#include <vector>
#include "Library.h"
#include "Exceptions.h"

Library::Library() {
  name = "Unknown library";
  address = "Unknown place";
}

Library::Library(const string& name, const string& address) {
  this->name = name;
  this->address = address;
}

Library::Library(const string& name, const string& address, vector <Book> books,
                 Schedule schedule) {
  this->name = name;
  this->address = address;
  this->books = books;
  this->schedule = schedule;
}

Library::Library(const Library& input) {
  this->name = input.name;
  this->address = input.address;
  this->books = input.books;
  this->schedule = input.schedule;
}

Library::~Library() { books.clear(); }

Library& Library::operator=(const Library& input) {
  this->name = input.name;
  this->address = input.address;
  this->books = input.books;
  this->schedule = input.schedule;
  return *this;
}

Library& Library::operator+(const Library& input) {
  Library* newLibrary = new Library();
  newLibrary->setName(this->getName() + " & " + input.getName());
  vector<Book> newVector = this->getBooks();
  newVector.insert(newVector.end(), input.books.begin(), input.books.end());
  newLibrary->setBooks(newVector);
  newLibrary->setAddress(this->getAddress() + " & " + input.getAddress());
  newLibrary->setSchedule(this->getSchedule() + input.schedule);
  return *newLibrary;
}

Book& Library::operator[](int index) {
  if (index < books.size())
    return books[index];
  else
    throw BookNotFoundException(index);
}

string Library::getName() const { return name; }

string Library::getAddress() const { return address; }

int Library::getCount() const { return (int)books.size(); }

vector<Book>& Library::getBooks() { return books; }

Schedule& Library::getSchedule() { return schedule; }

void Library::setName(const string& arg1) { name = arg1; }

void Library::setAddress(const string& arg1) { address = arg1; }

void Library::setBooks(vector<Book> arg1) { books = arg1; }

void Library::setSchedule(const Schedule& arg1) { schedule = arg1; }

void Library::printLibraryInfo() {
  cout << "Library \"" << name << "\":" << endl;
  cout << "Opened from " << schedule.printOpen() << " to "
       << schedule.printClose() << endl;
  cout << "Address: " << address << endl;
  cout << "Books number: " << books.size() << endl;
}

void Library::printBooks() {
    if (getCount() == 0) {
    cout << "No books in this library" << endl;
    } else {
    for (int i = 0; i < getCount(); i++) {
      books[i].printBookInfo();
    }
  }
}

void Library::add(const Book& book) {
  for (Book& value : books) {
    if (value == book) throw BookAlreadyExistsException(book);
  }
  books.emplace_back(book);
}

void Library::remove(const Book& book) {
  vector<Book>::iterator position = find(books.begin(), books.end(), book);
  if (position != books.end()) {
    books.erase(position);
  } else {
    throw BookNotFoundException(book);
  }
}

void Library::remove(int index) {
  if (index <= getCount())
    books.erase(books.begin() + index);
  else
    throw BookNotFoundException(index);
}

bool Library::has(const Book& book) {
  if (find(books.begin(), books.end(), book) != books.end())
    return true;
  else
    return false;
}
