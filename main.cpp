#include <iostream>
#include <string>
#include <fstream>
#include "Book.h"
#include "Librarian.h"
#include "Student.h"
using namespace std;
void librarianMenu(Librarian &libr, Student& st, Book& b);
void studentMenu(Librarian& libr, Student &st, Book& b);
int main() {
    Librarian librarian;
    Student student;
    Book book;
    int choice;
    do {
        cout << "1.Student.\n2.Librarian.\n0.Exit.\n";
        cin >> choice;
        switch (choice) {
        case 1: {
            system("cls");
            studentMenu(librarian, student,book);
            system("cls");
            break;
        }
        case 2: {
            system("cls");
            librarianMenu(librarian,student,book);
            system("cls");
            break;
        }
        default:
            break;
        }
    } while (choice > 0);
    cout << "exit\n";   
    return 0;
}
void librarianMenu(Librarian &libr, Student& st, Book& b) {
    int choice;
    do {
        cout << "1.Display all books.\n2.Display book by id.\n3.Display book by title.\n4.Display book by author\n5.Add book.\n6.Delete book.\n7.View User info\n";
        cout<<"8.Add Student.\n9.Edit Student.\n10.View Students\n11.Delete Student.\n0.Back.\n";
        cin >> choice;
        switch (choice) {
        case 1: {
            system("cls");
            libr.showAllBooks();
            system("pause");
            system("cls");
            break;
        }
        case 2: {
            system("cls");
            libr.showBook();
            system("pause");
            system("cls");
            break;
        }
        case 3: {
            system("cls");
            libr.showBookName();
            system("pause");
            system("cls");
            break;
        }
        case 4: {
            system("cls");
            libr.showBookAuthor();
            system("pause");
            system("cls");
            break;
        }
        case 5: {
            system("cls");
            libr.addBook(b);
            system("pause");
            system("cls");
            break;
        }
        case 6: {
            system("cls");
            libr.deletebook();
            system("pause");
            system("cls");
            break;
        }    
        case 7: {
            system("cls");
            libr.showStudentInfo();
            system("pause");
            system("cls");
            break;
        }
        case 8:{
            system("cls");
            libr.createStudent(st);
            system("pause");
            system("cls");
            break;
        }
        case 9:{
            system("cls");
            libr.editStudent();
            system("pause");
            system("cls");
            break;
        }
        case 10:{
            system("cls");
            libr.displayAllStudents();
            system("pause");
            system("cls");
            break;
        }
        case 11:{
            system("cls");
            libr.deleteStudent();
            system("pause");
            system("cls");
            break;
        }
        default:
            break;
        }
    } while (choice > 0);
}
void studentMenu(Librarian& libr, Student &st, Book& b) {
    int choice;
    string id, password, username;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    if (libr.checkPass(username, password, st)) {
        do {
            system("cls");
            cout << "Entered.\n";
            cout << "1.Borrow Book.\n2.Return Book.\n3.Show all books.\n4.Show book by id.\n5.Show book by title.\n6.Show book by author\n0.Back\n";
            cin >> choice;
            switch (choice)
            {
            case 1: {
                system("cls");
                libr.BorrowBook(b,st);
                system("pause");
                system("cls");
                break;
            }
            case 2: {
                system("cls");
                libr.ReturnBook(b,st);
                system("pause");
                system("cls");
                break;
            }
            case 3: {
                system("cls");
                libr.showAllBooks();
                system("pause");
                system("cls");
                break;
            }
            case 4: {
                system("cls");
                libr.showBook();
                system("pause");
                system("cls");
                break;
            }
            case 5: {
                system("cls");
                libr.showBookName();
                system("pause");
                system("cls");
                break;
            }
            case 6: {
                system("cls");
                libr.showBookAuthor();
                system("pause");
                system("cls");
                break;
            }
            default:
                break;
            }
        } while (choice > 0);    
    }
    system("pause");
}
