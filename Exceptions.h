// Copyright 2015 <precisef0x>

#pragma once

#include <string>
#include <sstream>
#include <exception>
#include "Book.h"

class BookNotFoundException : public exception {
 private:
  string message;

 public:
  explicit BookNotFoundException(const Book& book);
  explicit BookNotFoundException(int index);
  virtual const char* what() const throw();
};

class BookAlreadyExistsException : public exception {
 private:
  string message;

 public:
  explicit BookAlreadyExistsException(const Book& book);
  virtual const char* what() const throw();
};
