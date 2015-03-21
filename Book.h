#include <iostream>
#include <string>

using namespace std;

#ifndef AYAP_2_Console_Book_h
#define AYAP_2_Console_Book_h

class Book
{
private:
    string author;
    string title;
    int pubYear;
    float rating;
    int pagesNumber;
    bool available;
public:
    Book();
    Book(string title, string author, int pubYear, float rating, int pagesNumber, bool available);
    Book(string title, string author, bool available);
    ~Book();
    Book& operator=(const Book &);
    string getAuthor();
    string getTitle();
    int getPubYear();
    float getRating();
    int getPagesNumber();
    bool getAvailable();
    void setAuthor(string);
    void setTitle(string);
    void setPubYear(int);
    void setRating(float);
    void setPagesNumber(int);
    void setAvailable(bool);
    void setAllParameters(string, string, int, float, int, bool);
    void printBookInfo();
};

#endif
