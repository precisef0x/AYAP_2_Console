// Copyright 2015 <precisef0x>

#pragma once

#include <iostream>
#include <string>

using ::std::string;
using ::std::ostream;
using ::std::endl;
using ::std::cout;
using ::std::exception;
using ::std::ostringstream;

class Book {
 private:
  string author;
  string title;
  int pubYear;
  float rating;
  int pagesNumber;
  bool available;

 public:
  Book();
  Book(const Book& book);
  Book(string title, string author, int pubYear, float rating, int pagesNumber,
       bool available);
  Book(string title, string author, bool available);
  ~Book();
  Book& operator=(const Book& book);
  bool operator==(const Book& book);
  friend ostream& operator<<(ostream& stream, const Book& book);
  string getAuthor() const;
  string getTitle() const;
  int getPubYear() const;
  float getRating() const;
  int getPagesNumber() const;
  bool getAvailable() const;
  void setAuthor(const string& str);
  void setTitle(const string& str);
  void setPubYear(int pubYear);
  void setRating(float rating);
  void setPagesNumber(int pagesNumber);
  void setAvailable(bool available);
  void setAllParameters(const string& title, const string& author, int pubYear,
                        float rating, int pagesNumber, bool available);
  void printBookInfo();
};
