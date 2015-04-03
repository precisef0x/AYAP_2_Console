// Copyright [2015] <precisef0x>

#include "Book.h"
#include <string>

Book::Book() {
  author = "Unknown author";
  title = "Unknown title";
  pubYear = 0;
  rating = 0.0;
  pagesNumber = 0;
  available = 0;
}

Book::Book(const Book& input) {
  author = input.author;
  title = input.title;
  pubYear = input.pubYear;
  rating = input.rating;
  pagesNumber = input.pagesNumber;
  available = input.available;
}

Book::Book(string title, string author, int pubYear, float rating,
           int pagesNumber, bool available) {
  this->title = title;
  this->author = author;
  this->pubYear = pubYear;
  this->rating = rating;
  this->pagesNumber = pagesNumber;
  this->available = available;
}

Book::Book(string title, string author, bool available) {
  this->title = title;
  this->author = author;
  this->pubYear = 0;
  this->rating = 0.0;
  this->pagesNumber = 0;
  this->available = available;
}

Book::~Book() {}

bool Book::operator==(const Book& input) {
  if (input.author == this->author && input.available == this->available &&
      input.pagesNumber == this->pagesNumber &&
      input.pubYear == this->pubYear && input.rating == this->rating &&
      input.title == this->title)
    return true;
  else
    return false;
}

Book& Book::operator=(const Book& input) {
  this->title = input.title;
  this->author = input.author;
  this->pubYear = input.pubYear;
  this->rating = input.rating;
  this->pagesNumber = input.pagesNumber;
  this->available = input.available;
  return *this;
}

ostream& operator<<(ostream& stream, const Book& input) {
  stream << "Book \"" << input.title << "\" by " << input.author << ':' << endl;
  stream << "Publishing year: " << input.pubYear << endl;
  stream << "Rating: " << input.rating << endl;
  stream << "Pages number: " << input.pagesNumber << endl;
  stream << (input.available ? "Available " : "Not available ")
         << "in the library" << endl;
  return stream;
}

string Book::getAuthor() const { return author; }

string Book::getTitle() const { return title; }

int Book::getPubYear() const { return pubYear; }

float Book::getRating() const { return rating; }

int Book::getPagesNumber() const { return pagesNumber; }

bool Book::getAvailable() const { return available; }

void Book::setAuthor(const string& arg1) { author = arg1; }

void Book::setTitle(const string& arg1) { title = arg1; }

void Book::setPubYear(int arg1) { pubYear = arg1; }

void Book::setRating(float arg1) { rating = arg1; }

void Book::setPagesNumber(int arg1) { pagesNumber = arg1; }

void Book::setAvailable(bool arg1) { available = arg1; }

void Book::setAllParameters(const string& arg1, const string& arg2, int arg3,
                            float arg4, int arg5, bool arg6) {
  author = arg1;
  title = arg2;
  pubYear = arg3;
  rating = arg4;
  pagesNumber = arg5;
  available = arg6;
}

void Book::printBookInfo() { cout << *this; }
