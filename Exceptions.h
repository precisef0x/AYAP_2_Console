#pragma once

#include <string>
#include <sstream>
#include <exception>
#include "Book.h"

using namespace std;

class BookNotFoundException: public exception
{
private:
    string message;
public:
    BookNotFoundException(const Book &);
    BookNotFoundException(int);
    virtual const char* what() const throw();
};

class BookAlreadyExistsException: public exception
{
private:
    string message;
public:
    BookAlreadyExistsException(const Book &);
    virtual const char* what() const throw();
};