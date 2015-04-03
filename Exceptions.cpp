// Copyright 2015 <precisef0x>

#include "Exceptions.h"

BookNotFoundException::BookNotFoundException(int index) {
  ostringstream stream;
  stream << "Book not found at index:" << index;
  message = stream.str();
}

BookNotFoundException::BookNotFoundException(const Book& input) {
  ostringstream stream;
  stream << "Book \"" << input.getTitle() << "\" by " << input.getAuthor()
         << " not found";
  message = stream.str();
}

const char* BookNotFoundException::what() const throw() {
  return message.c_str();
}

BookAlreadyExistsException::BookAlreadyExistsException(const Book& input) {
  ostringstream stream;
  stream << "Book \"" << input.getTitle() << "\" by " << input.getAuthor()
         << " already exists";
  message = stream.str();
}

const char* BookAlreadyExistsException::what() const throw() {
  return message.c_str();
}
