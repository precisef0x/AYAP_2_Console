#include "Book.h"

Book::Book()
{
    author = "Unknown author";
    title = "Unknown title";
    pubYear = 0;
    rating = 0.0;
    pagesNumber = 0;
    available = 0;
}

Book::Book(string title, string author, int pubYear, float rating, int pagesNumber, bool available)
{
    this->title = title;
    this->author = author;
    this->pubYear = pubYear;
    this->rating = rating;
    this->pagesNumber = pagesNumber;
    this->available = available;
}

Book::Book(string title, string author, bool available)
{
    this->title = title;
    this->author = author;
    this->pubYear = 0;
    this->rating = 0.0;
    this->pagesNumber = 0;
    this->available = available;
}

Book::~Book()
{
    
}

Book& Book::operator=(const Book & input)
{
    Book *copy = new Book(input.title, input.author, input.pubYear, input.rating, input.pagesNumber, input.available);
    return *copy;
}

string Book::getAuthor()
{
    return author;
}

string Book::getTitle()
{
    return title;
}

int Book::getPubYear()
{
    return pubYear;
}

float Book::getRating()
{
    return rating;
}

int Book::getPagesNumber()
{
    return pagesNumber;
}

bool Book::getAvailable()
{
    return available;
}

void Book::setAuthor(string arg1)
{
    author = arg1;
}

void Book::setTitle(string arg1)
{
    title = arg1;
}

void Book::setPubYear(int arg1)
{
    pubYear = arg1;
}

void Book::setRating(float arg1)
{
    rating = arg1;
}

void Book::setPagesNumber(int arg1)
{
    pagesNumber = arg1;
}

void Book::setAvailable(bool arg1)
{
    available = arg1;
}

void Book::setAllParameters(string arg1, string arg2, int arg3, float arg4, int arg5, bool arg6)
{
    author = arg1;
    title = arg2;
    pubYear = arg3;
    rating = arg4;
    pagesNumber = arg5;
    available = arg6;
}

void Book::printBookInfo()
{
    cout << "Book \"" << title << "\" by " << author << ':' << endl;
    cout << "Publishing year: " << pubYear << endl;
    cout << "Rating: " << rating << endl;
    cout << "Pages number: " << pagesNumber << endl;
    cout << (available ? "Available " : "Not available ") << "in the library" << endl;
}
