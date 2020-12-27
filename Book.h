#pragma once
#ifndef BOOK_H
#define BOOK_H
#include <string>

class Book {
private:
    std::string id;
    std::string title;
    std::string author;
    bool isBorrowed;
    std::string studentID;
public:
    Book();

    Book(std::string id, std::string title, std::string author, bool isBorrowed);

    void setID(std::string id);
    std::string getID();

    void setTitle(std::string title);
    std::string getTitle();

    void setAuthor(std::string author);
    std::string getAuthor();

    void setIsBorrowed(bool isBorrowed);
    bool getIsBorrowed();

    void setStudentID(std::string studentID);
    std::string getStudentID();
};
Book::Book() {
    id = "-1";
    title = "Not set";
    author = "Not set";
    isBorrowed = false;
}
Book::Book(std::string id, std::string title, std::string author, bool isBorrowed) {
    this->id = id;
    this->title = title;
    this->author = author;
    this->isBorrowed = isBorrowed;
}
void Book::setID(std::string id) { this->id = id; }
std::string Book::getID() { return id; }

void Book::setTitle(std::string title) { this->title = title; }
std::string Book::getTitle() { return title; }
void Book::setAuthor(std::string author) { this->author = author; }
std::string Book::getAuthor() { return author; }
void Book::setIsBorrowed(bool isBorrowed) { this->isBorrowed = isBorrowed; }
bool Book::getIsBorrowed() { return isBorrowed; }
void Book::setStudentID(std::string studentID) {
    this->studentID = studentID;
}
std::string Book::getStudentID() {
    return studentID;
}
#endif