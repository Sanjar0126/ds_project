#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include "User.h"
#include "blist.h"
#include <vector>
#include "Book.h"
class Student : public User, public BookList {
private:
    int nOBorrowedBooks;
    std::vector<Book> borrowedBooks;
public:
    Student();

    Student(int nOBorrowedBooks, std::string id, std::string name, std::string password);

    void incrementNOBorrowedBooks();
    void decrementNOBorrowedBooks();
    int getNOBorrowedBooks();

    void addBorrowedBook(Book& book);
    void deleteBorrowedBook(std::string book_id, Book& book);
    std::vector<Book> getBorrowedBooks();
    
  
};
Student::Student()  : User() {
    this->nOBorrowedBooks = 0;
    
}
Student::Student(int nOBorrowedBooks, std::string id, std::string name, std::string password) : User(id, name, password) {
    this->nOBorrowedBooks = nOBorrowedBooks;
    
}
void Student::incrementNOBorrowedBooks() { nOBorrowedBooks++; }
void Student::decrementNOBorrowedBooks() { nOBorrowedBooks--; }
int Student::getNOBorrowedBooks() { return nOBorrowedBooks; }
void Student::addBorrowedBook(Book& book) {
    borrowedBooks.push_back(book);
}
void Student::deleteBorrowedBook(std::string book_id, Book& book) {
    for (int i = 0; i < borrowedBooks.size(); i++) {
        if (borrowedBooks[i].getID() == book.getID()) {
            borrowedBooks.erase(borrowedBooks.begin() + i);
        }
    }
}
std::vector<Book> Student::getBorrowedBooks() {
    return borrowedBooks;
}
#endif