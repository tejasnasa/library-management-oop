#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Book {
public:
    string title;
    string author;
    bool isBorrowed;

    // Constructor to initialize book
    Book(string t, string a, bool b = false) : title(t), author(a), isBorrowed(b) {}

    // Display book details
    void display() const {
        cout << "Title: " << title << ", Author: " << author << ", Status: "
             << (isBorrowed ? "Borrowed" : "Available") << endl;
    }
};

class Library {
private:
    vector<Book> books;

    // Load books from file
    void loadBooks() {
        ifstream inFile("books.txt");
        string title, author;
        bool isBorrowed;
        while (inFile >> title >> author >> isBorrowed) {
            books.emplace_back(title, author, isBorrowed);
        }
        inFile.close();
    }

    // Save books to file
    void saveBooks() {
        ofstream outFile("books.txt");
        for (const auto &book : books) {
            outFile << book.title << " " << book.author << " " << book.isBorrowed << endl;
        }
        outFile.close();
    }

public:
    Library() {
        loadBooks();
    }

    ~Library() {
        saveBooks();
    }

    // Add new book
    void addBook(const string &title, const string &author) {
        books.emplace_back(title, author);
        cout << "Book added successfully.\n";
    }

    // Display all books
    void displayBooks() {
        if (books.empty()) {
            cout << "No books available in the library.\n";
            return;
        }
        for (const auto &book : books) {
            book.display();
        }
    }

    // Borrow a book
    void borrowBook(const string &title) {
        bool bookFound = false;
        for (auto &book : books) {
            if (book.title == title) {
                bookFound = true;
                if (book.isBorrowed) {
                    cout << "The book \"" << title << "\" is already borrowed.\n";
                } else {
                    book.isBorrowed = true;
                    cout << "You have borrowed \"" << title << "\".\n";
                }
                return;
            }
        }
        if (!bookFound) {
            cout << "Book \"" << title << "\" not found in the library.\n";
        }
    }

    // Return a borrowed book
    void returnBook(const string &title) {
        bool bookFound = false;
        for (auto &book : books) {
            if (book.title == title) {
                bookFound = true;
                if (book.isBorrowed) {
                    book.isBorrowed = false;
                    cout << "You have returned \"" << title << "\".\n";
                } else {
                    cout << "The book \"" << title << "\" was not borrowed.\n";
                }
                return;
            }
        }
        if (!bookFound) {
            cout << "Book \"" << title << "\" not found in the library.\n";
        }
    }
};

// Authenticate the admin user
bool authenticate() {
    const string adminPassword = "admin123";
    string password;

    cout << "Enter admin password: ";
    cin >> password;

    if (password == adminPassword) {
        cout << "Authentication successful.\n";
        return true;
    } else {
        cout << "Authentication failed. Access denied.\n";
        return false;
    }
}

int main() {
    if (!authenticate()) {
        return 0;
    }

    Library library;
    int choice;
    string title, author;

    do {
        cout << "\nLibrary Management System:\n";
        cout << "1. Add Book\n2. Display Books\n3. Borrow Book\n4. Return Book\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter book title: ";
                cin >> title;
                cout << "Enter book author: ";
                cin >> author;
                library.addBook(title, author);
                break;
            case 2:
                library.displayBooks();
                break;
            case 3:
                cout << "Enter book title to borrow: ";
                cin >> title;
                library.borrowBook(title);
                break;
            case 4:
                cout << "Enter book title to return: ";
                cin >> title;
                library.returnBook(title);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
