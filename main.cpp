// Copyright 2015 <precisef0x>

#include <iostream>
#include "Book.h"
#include "Library.h"
#include "Exceptions.h"

int main(void) {
  Book book;
  cout << "We created a book:" << endl << book << endl;
  // Which is equivalent to:
  book.printBookInfo();
  cout << endl;

  // Set some options:
  book.setTitle("The adventures of Sherlock Holmes");
  book.setAuthor("Arthur Conan Doyle");
  book.setAvailable(1);
  cout << book << endl;

  Library* lib = new Library("My favorite library", "Right around the corner");
  lib->printLibraryInfo();
  lib->add(book);
  book.setTitle("The Mystery of Cloomber");
  book.setAvailable(false);
  lib->add(book);
  cout << endl;

  // Check whether the books counter changed or not
  lib->printLibraryInfo();

  // Now print all books:
  cout << endl;
  lib->printBooks();

  // Create a new library from the first and add a new book
  Library lib2(*lib);
  Book* book2 = new Book("Cool title", "A genius", 2015, 0.12, 200, 1);
  lib2.add(*book2);
  try {
    lib2.add(*book2);
  } catch (exception& e) {
    cout << "Error: " << e.what() << endl;
  }

  cout << endl << "New library: " << endl;
  lib2.printLibraryInfo();
  lib2.printBooks();

  lib2.setName("Unknown library");

  // Create the third library as sum of the first and the second
  Library lib3 = *lib + lib2;

  cout << endl << "The third library: " << endl;
  lib3.printLibraryInfo();
  lib3.printBooks();

  // Delete the book from the third library:
  lib3.remove(*book2);

  // Print all books again
  cout << endl;
  lib3.printLibraryInfo();
  lib3.printBooks();
  try {
    lib2.remove(100);
  } catch (BookNotFoundException& e) {
    cout << "Error: " << e.what() << endl;
  }

  try {
    lib3.remove(*book2);
  } catch (BookNotFoundException& e) {
    cout << "Error: " << e.what() << endl;
  }

  delete lib;
  delete book2;
  return 0;
}
