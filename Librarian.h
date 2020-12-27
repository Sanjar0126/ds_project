#pragma once
#ifndef LIBRARIAN_H
#define LIBRARIAN_H
#include <string>
#include <iostream>
#include "User.h"
#include "slist.h"
#include "blist.h"
class Librarian : public User, StudentList, BookList {
public:
    Librarian();
    Librarian(std::string id,std::string name, std::string password);
    void createStudent(Student& st);
    void editStudent();
    void displayAllStudents();
    void deleteStudent();



    void showAllBooks();
    void showBook();
	void showBookName();
	void showBookAuthor();
    void addBook(Book& book);
    void deletebook();
    void showStudentInfo();

	bool checkPass(std::string name, std::string password, Student& student);
	
	void ReturnBook(Book& book, Student& student);
	void BorrowBook(Book& book, Student& student);
};

Librarian::Librarian() : User() {
	
}
Librarian::Librarian(std::string id, std::string name, std::string password) : User(id, name, password) {
	
}

void Librarian::createStudent(Student& st) {
	std::string id, name, password;
	std::cout << "Enter id of student :";
	std::cin >> id;
	std::cout << "Enter username of student: ";
	std::cin >> name;
	std::cout << "Enter password of student: ";
	std::cin >> password;
	st.setID(id);
	st.setName(name);
	st.setPassword(password);
	studentnode* temp = new studentnode;
	temp->data = st;
	temp->next = NULL;
	if (uhead == NULL) {
		uhead = temp;
		utail = temp;
	}
	else {
		utail->next = temp;
		utail = utail->next;
	}
}
void Librarian::editStudent() {
	std::string id, name, password;
	std::cout << "Enter id of student you want to edit: ";
	std::cin >> id;
	studentnode* temp;
	temp = uhead;
	while (temp != NULL && temp->data.getID() != id) {
		temp = temp->next;
	}
	if (temp == NULL) {
		std::cout << "Student is not found.\n";
		return;
	}
	std::cout << "Enter new username for student: ";
	std::cin >> name;
	std::cout << "Enter new password for student: ";
	std::cin >> password;
	temp->data.setName(name);
	temp->data.setPassword(password);
}
void Librarian::displayAllStudents() {
	studentnode* temp;
	temp = uhead;
	while (temp != NULL) {
		std::cout << "id: " << (temp->data).getID() << std::endl;
		std::cout << "username: " << (temp->data).getName() << std::endl;
		std::cout << "password: " << (temp->data).getPassword() << std::endl;
		temp = temp->next;
	}
}
void Librarian::deleteStudent() {
	std::string id;
	std::cout << "Enter id of student you want to delete: ";
	std::cin >> id;
	studentnode* temp;
	temp = uhead;
	studentnode* prev;
	prev = NULL;
	if (temp != NULL && temp->data.getID() == id) {
		uhead = temp->next;
		delete temp;              //free memory
		return;
	}
	while (temp != NULL && temp->data.getID() != id) {
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL) {
		std::cout << "User is not found.\n";
		return;
	}
	prev->next = temp->next;
	delete temp;                  //free memory
	std::cout << "User record is deleted.\n";
}
void Librarian::showAllBooks() {
	booknode* temp;
	temp = bhead;
	int count=0;
	while (temp != NULL) {
		std::cout << "id: " << (temp->data).getID() << std::endl;
		std::cout << "title: " << (temp->data).getTitle() << std::endl;
		std::cout << "author: " << (temp->data).getAuthor() << std::endl;
		std::string stat = ((temp->data).getIsBorrowed()) ? "borrowed" : "not borrowed";
		std::cout << "Borrowed status: " << stat << std::endl;
		temp = temp->next;
		count++;
	}
	if (count == 0) {
		std::cout << "No book is found.\n";
	}
}
void Librarian::showBookAuthor() {
	std::string id;
	std::cout << "Enter book's author's name you want to diplay: ";
	std::cin >> id;
	booknode* temp;
	temp = bhead;
	int count = 0;
	while (temp != NULL && temp->data.getAuthor()==id) {
		std::cout << "id: " << (temp->data).getID() << std::endl;
		std::cout << "title: " << (temp->data).getTitle() << std::endl;
		std::cout << "author: " << (temp->data).getAuthor() << std::endl;
		std::string stat = ((temp->data).getIsBorrowed()) ? "borrowed" : "not borrowed";
		std::cout << "Borrowed status: " << stat << std::endl;
		temp = temp->next;
		count++;
	}
	if (count == 0) {
		std::cout << "No such book is found.\n";
	}
}
void Librarian::showBookName() {
	std::string name;
	std::cout << "Enter book's title you want to diplay: ";
	std::cin >> name;
	booknode* temp;
	temp = bhead;
	int count = 0;
	while (temp != NULL && temp->data.getTitle() == name) {
		std::cout << "id: " << (temp->data).getID() << std::endl;
		std::cout << "title: " << (temp->data).getTitle() << std::endl;
		std::cout << "author: " << (temp->data).getAuthor() << std::endl;
		std::string stat = ((temp->data).getIsBorrowed()) ? "borrowed" : "not borrowed";
		std::cout << "Borrowed status: " << stat << std::endl;
		temp = temp->next;
		count++;
	}
	if (count == 0) {
		std::cout << "No such book is found.\n";
	}
}
void Librarian::showBook() {
	std::string id;
	std::cout << "Enter book's id you want to diplay: ";
	std::cin >> id;
	booknode* temp;
	temp = bhead;
	while (temp != NULL && temp->data.getID() != id) {
		temp = temp->next;
	}
	if (temp == NULL) {
		std::cout << "Book is not found.\n";
		return;
	}
	std::cout << "id: " << (temp->data).getID() << std::endl;
	std::cout << "title: " << (temp->data).getTitle() << std::endl;
	std::cout << "author: " << (temp->data).getAuthor() << std::endl;
	std::string stat = ((temp->data).getIsBorrowed()) ? "borrowed" : "not borrowed";
	std::cout << "Borrowed status: " << stat << std::endl;

}
void Librarian::addBook(Book& book) {
	std::string id, title, author;
	std::cout << "Enter book's id: ";
	std::cin >> id;
	std::cout << "Enter books' title: ";
	std::cin.ignore();
	std::getline(std::cin, title);
	std::cout << "Enter book's author: ";
	//std::cin.ignore();
	std::getline(std::cin, author);
	book.setID(id);
	book.setAuthor(author);
	book.setTitle(title);
	booknode* temp = new booknode;
	temp->data = book;
	temp->next = NULL;
	if (bhead == NULL) {
		bhead = temp;
		btail = temp;
	} else {
		btail->next = temp;
		btail = btail->next;
	}
}

void Librarian::deletebook() {
	std::string id;
	std::cout << "Enter book's id you want to delete: ";
	std::cin >> id;
	booknode* temp;
	temp = bhead;
	booknode* prev;
	prev = NULL;
	if (temp != NULL && temp->data.getID() == id) {
		bhead = temp->next;
		delete temp;              //free memory
		return;
	}
	while (temp != NULL && temp->data.getID() != id) {
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL) {
		std::cout << "Book is not found.\n";
		return;
	}
	prev->next = temp->next;
	delete temp;                  //free memory
	std::cout << "Book is deleted.\n";
}
void Librarian::showStudentInfo() {
	std::string id;
	std::cout << "Enter student's id you want to view info: ";
	std::cin >> id;
	studentnode* temp;
	temp = uhead;
	while (temp != NULL && temp->data.getID() != id) {
		temp = temp->next;
	}
	if (temp == NULL) {
		std::cout << "Student is not found.\n";
		return;
	}
	std::cout << "id: " << (temp->data).getID() << std::endl;
	std::cout << "username: " << (temp->data).getName() << std::endl;
	if ((temp->data).getNOBorrowedBooks() > 0)
	{
		std::cout << "Number of borrowed books: " << (temp->data).getNOBorrowedBooks() << std::endl;

		for (int i = 0; i < (temp->data).getBorrowedBooks().size(); i++) {
			std::cout << "ID of " << i + 1 << "-borrowed book: " << (temp->data).getBorrowedBooks()[i].getID() << std::endl;
		}
	}
}
bool Librarian::checkPass(std::string name, std::string password, Student& student) {
	studentnode* temp;
	temp = uhead;
	while (temp != NULL && temp->data.getName() != name && temp->data.getPassword() != password) {
		temp = temp->next;
	}
	if (temp == NULL) {
		std::cout << "No match is found.\n";
		return false;
	}
	student = temp->data;
	if (temp->data.getName() == name && temp->data.getPassword() == password)
	{
		return true;
	}
	
}
void Librarian::BorrowBook(Book& book, Student& student) {
	std::string bookid;
	std::cout << "Enter id of book you want to borrow: \n";
	std::cin >> bookid;
	booknode* temp;
	temp = bhead;
	studentnode* tempst;
	tempst = uhead;
	while (temp != NULL && temp->data.getID() != bookid) {
		temp = temp->next;
	}
	if (temp == NULL) {
		std::cout << "No book with such id is found.\n";
		return;
	}
	if (temp->data.getIsBorrowed() == true) {
		std::cout << "This book is borrowed. No available.\n";
		return;
	}
	while (tempst != NULL && tempst->data.getID() != student.getID()) {
		tempst = tempst->next;
	}
	temp->data.setStudentID(tempst->data.getID());
	temp->data.setIsBorrowed(true);
	tempst->data.addBorrowedBook(temp->data);
	tempst->data.incrementNOBorrowedBooks();
}
void Librarian::ReturnBook(Book& book, Student& student) {
	std::string bookid;
	booknode* temp;
	temp = bhead;
	studentnode* tempst;
	tempst = uhead;
	while (tempst != NULL && tempst->data.getID() != student.getID()) {
		tempst = tempst->next;
	}
	std::cout << "Enter id of book you want to return: \n";
	std::cin >> bookid;
	while (temp != NULL && temp->data.getID() != bookid) {
		temp = temp->next;
	}
	if (temp == NULL ) {
		std::cout << "No book with such id is found.\n";
		return;
	}
	for (int i = 0; i < tempst->data.getBorrowedBooks().size(); i++) {
		if(tempst->data.getBorrowedBooks()[i].getID() == bookid && temp->data.getStudentID()==tempst->data.getID()) {
			std::cout << "Returned book\n";
			temp->data.setIsBorrowed(false);
			tempst->data.deleteBorrowedBook(bookid, temp->data);
			tempst->data.decrementNOBorrowedBooks();
			temp->data.setStudentID("");
			return;			
		}
	}
	std::cout << "Book is not property of student\n";
}
#endif
