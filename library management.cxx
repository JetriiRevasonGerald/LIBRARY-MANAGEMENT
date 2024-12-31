#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Book class represents a book in the library.
class Book {
private:
    int bookID;
    string title;
    string author;
    bool isIssued; // To track if the book is issued or not

public:
    // Constructor to initialize book details
    Book(int id, string t, string a) : bookID(id), title(t), author(a), isIssued(false) {}

    // Function to display the book's information
    void displayBook() const {
        cout << "Book ID: " << bookID << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Issued: " << (isIssued ? "Yes" : "No") << endl;
    }

    // Getters and setters
    int getBookID() const {
        return bookID;
    }

    bool getIssuedStatus() const {
        return isIssued;
    }

    void issueBook() {
        isIssued = true;
    }

    void returnBook() {
        isIssued = false;
    }
};

// Member class represents a library member.
class Member {
private:
    int memberID;
    string name;
    string contact;

public:
    // Constructor to initialize member details
    Member(int id, string n, string c) : memberID(id), name(n), contact(c) {}

    // Function to display member information
    void displayMember() const {
        cout << "Member ID: " << memberID << endl;
        cout << "Name: " << name << endl;
        cout << "Contact: " << contact << endl;
    }

    int getMemberID() const {
        return memberID;
    }
};

// Library class to manage books and members
class Library {
private:
    vector<Book> books;  // Collection of books
    vector<Member> members;  // Collection of library members

public:
    // Function to add a new book
    void addBook(const Book &b) {
        books.push_back(b);
    }

    // Function to add a new member
    void addMember(const Member &m) {
        members.push_back(m);
    }

    // Function to display all books
    void displayBooks() const {
        cout << "\nBooks available in the library:\n";
        for (const auto &book : books) {
            book.displayBook();
            cout << endl;
        }
    }

    // Function to display all members
    void displayMembers() const {
        cout << "\nLibrary Members:\n";
        for (const auto &member : members) {
            member.displayMember();
            cout << endl;
        }
    }

    // Function to issue a book to a member
    void issueBook(int bookID, int memberID) {
        bool bookFound = false;
        bool memberFound = false;

        for (auto &book : books) {
            if (book.getBookID() == bookID) {
                bookFound = true;
                if (book.getIssuedStatus()) {
                    cout << "Sorry, this book is already issued.\n";
                    return;
                } else {
                    for (auto &member : members) {
                        if (member.getMemberID() == memberID) {
                            memberFound = true;
                            book.issueBook();
                            cout << "Book issued successfully to " << member.getMemberID() << endl;
                            return;
                        }
                    }
                }
            }
        }

        if (!bookFound) {
            cout << "Book with ID " << bookID << " not found.\n";
        }
        if (!memberFound) {
            cout << "Member with ID " << memberID << " not found.\n";
        }
    }

    // Function to return a book
    void returnBook(int bookID) {
        for (auto &book : books) {
            if (book.getBookID() == bookID) {
                if (book.getIssuedStatus()) {
                    book.returnBook();
                    cout << "Book with ID " << bookID << " returned successfully.\n";
                } else {
                    cout << "This book was not issued.\n";
                }
                return;
            }
        }
        cout << "Book with ID " << bookID << " not found.\n";
    }
};

int main() {
    Library library;

    // Adding some books to the library
    library.addBook(Book(1, "C++ Programming", "Bjarne Stroustrup"));
    library.addBook(Book(2, "Data Structures and Algorithms", "Mark Allen Weiss"));
    library.addBook(Book(3, "The C Programming Language", "Dennis Ritchie"));

    // Adding some members to the library
    library.addMember(Member(101, "Alice Johnson", "555-1234"));
    library.addMember(Member(102, "Bob Smith", "555-5678"));

    int choice;
    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Display all books\n";
        cout << "2. Display all members\n";
        cout << "3. Issue a book\n";
        cout << "4. Return a book\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                library.displayBooks();
                break;
            case 2:
                library.displayMembers();
                break;
            case 3: {
                int bookID, memberID;
                cout << "Enter book ID to issue: ";
                cin >> bookID;
                cout << "Enter member ID: ";
                cin >> memberID;
                library.issueBook(bookID, memberID);
                break;
            }
            case 4: {
                int bookID;
                cout << "Enter book ID to return: ";
                cin >> bookID;
                library.returnBook(bookID);
                break;
            }
            case 5:
                cout << "Exiting the system...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}