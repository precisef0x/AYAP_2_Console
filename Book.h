#pragma once

#include <iostream>
#include <string>

using namespace std;

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
    Book(const Book &);
    Book(string title, string author, int pubYear, float rating, int pagesNumber, bool available);
    Book(string title, string author, bool available);
    ~Book();
    Book& operator=(const Book &);
    bool operator==(const Book &);
    friend ostream& operator<<(ostream&, const Book&);
    string getAuthor() const;
    string getTitle() const;
    int getPubYear() const;
    float getRating() const;
    int getPagesNumber() const;
    bool getAvailable() const;
    void setAuthor(const string&);
    void setTitle(const string&);
    void setPubYear(int);
    void setRating(float);
    void setPagesNumber(int);
    void setAvailable(bool);
    void setAllParameters(const string& title, const string& author, int pubYear, float rating, int pagesNumber, bool available);
    void printBookInfo();
};
