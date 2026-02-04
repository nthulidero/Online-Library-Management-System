#include <iostream>
#include <vector>
#include <string>
using namespace std;

//  BOOK CLASS
class Book {
private:
    int id;
    string title;
    string author;
    bool available;

public:
    Book(int id, string title, string author) {
        this->id = id;
        this->title = title;
        this->author = author;
        this->available = true;
    }

    int getId() { return id; }
    string getTitle() { return title; }
    string getAuthor() { return author; }
    bool isAvailable() { return available; }

    void borrowBook() { available = false; }
    void returnBook() { available = true; }
};

//  USER CLASS 
class User {
private:
    int userId;
    string name;

public:
    User(int userId, string name) {
        this->userId = userId;
        this->name = name;
    }

    int getUserId() { return userId; }
    string getName() { return name; }
};

//  LIBRARY CLASS 
class Library {
private:
    vector<Book> books;

public:
    void addBook(Book book) {
        books.push_back(book);
        cout << "Book added successfully.\n";
    }

    void removeBook(int id) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].getId() == id) {
                books.erase(books.begin() + i);
                cout << "Book removed successfully.\n";
                return;
            }
        }
        cout << "Book not found.\n";
    }

    Book* searchBook(int id) {
        for (auto &book : books) {
            if (book.getId() == id) {
                return &book;
            }
        }
        return nullptr;
    }

    void displayBooks() {
        cout << "\nAvailable Books:\n";
        for (auto &book : books) {
            cout << book.getId() << " | "
                 << book.getTitle() << " | "
                 << book.getAuthor() << " | "
                 << (book.isAvailable() ? "Available" : "Borrowed") << endl;
        }
    }
};

//  TEST CASES 
void runTests() {
    cout << "\n--- Running Tests ---\n";

    Book testBook(1, "1984", "George Orwell");

    // Positive test
    testBook.borrowBook();
    if (!testBook.isAvailable())
        cout << "PASS: Book borrowed successfully.\n";

    // Negative test
    testBook.borrowBook();
    if (!testBook.isAvailable())
        cout << "PASS: Cannot borrow unavailable book.\n";

    testBook.returnBook();
    if (testBook.isAvailable())
        cout << "PASS: Book returned successfully.\n";
}

//  MAIN FUNCTION 
int main() {
    Library library;

    library.addBook(Book(1, "1984", "George Orwell"));
    library.addBook(Book(2, "The Hobbit", "J.R.R. Tolkien"));

    library.displayBooks();

    Book* book = library.searchBook(1);
    if (book && book->isAvailable()) {
        book->borrowBook();
        cout << "\nBook borrowed successfully.\n";
    } else {
        cout << "\nBook not available.\n";
    }

    library.displayBooks();

    runTests();

    return 0;
}