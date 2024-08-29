#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;
    int year;

public:
    void setTitle(const string& t) {
        title = t;
    }

    void setAuthor(const string& a) {
        author = a;
    }

    void setYear(int y) {
        year = y;
    }

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    int getYear() const {
        return year;
    }
};

class Library {
private:
    Book* books;
    int size;
    int capacity;

public:
    Library(int c = 10) : capacity(c), size(0) {
        books = new Book[capacity];
    }

    ~Library() {
        delete[] books;
    }

    void addBook(const Book& b) {
        if (size < capacity) {
            books[size] = b;
            size++;
            cout << "Book added successfully!" << endl;
        } else {
            cout << "Library is full!" << endl;
        }
    }

    void displayBooks() const {
        if (size == 0) {
            cout << "No books in the library!" << endl;
            return;
        }

        cout << "Book List:" << endl;
        cout << "Title                        Author           Year" << endl;
        for (int i = 0; i < size; i++) {
            cout << books[i].getTitle() << "          " << books[i].getAuthor() << "        " << books[i].getYear() << endl;
        }
    }

    void searchBook(const string& title) const {
        bool found = false;
        for (int i = 0; i < size; i++) {
            if (books[i].getTitle() == title) {
                found = true;
                cout << "Book found!" << endl;
                cout << "Title: " << books[i].getTitle() << endl;
                cout << "Author: " << books[i].getAuthor() << endl;
                cout << "Year: " << books[i].getYear() << endl;
                break;
            }
        }
        if (!found) {
            cout << "Book not found!" << endl;
        }
    }
};

int main() {
    Library lib;
    int choice;
    string title, author;
    int year;

    while (true) {
        cout << "\nMenu" << endl;
        cout << "1 - Add Book" << endl;
        cout << "2 - Display Books" << endl;
        cout << "3 - Search Book" << endl;
        cout << "4 - Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter author: ";
                getline(cin, author);
                cout << "Enter year: ";
                cin >> year;

                Book b;
                b.setTitle(title);
                b.setAuthor(author);
                b.setYear(year);

                lib.addBook(b);
                break;
            }
            case 2:
                lib.displayBooks();
                break;
            case 3: {
                cout << "Enter a book title to search: ";
                cin.ignore();
                getline(cin, title);
                lib.searchBook(title);
                break;
            }
            case 4:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}

