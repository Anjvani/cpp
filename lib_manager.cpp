#include<iostream>
#include<fstream>
using namespace std;

struct Book {
    int bookID;
    string Title;
    string author;
    int yearPublished;
    bool available;
};

Book b[200];

void addBook() {
    fstream file("lib_booklist.txt", ios::app);
    int n;
    cout << "Enter number of books you want to enter:\n";
    cin >> n;
    cin.ignore();

    if (n < 1) {
        cout << "Enter a valid number.\n";
    } else {
        for (int i = 0; i < n; i++) {
            cout << "\nBook no. " << i + 1 << ":\n";
            cout << "ID No.: ";
            cin >> b[i].bookID;
            file << b[i].bookID << endl;

            cout << "Name: ";
            cin.ignore();
            getline(cin, b[i].Title);
            file << b[i].Title << endl;

            cout << "Author: ";
            getline(cin, b[i].author);
            file << b[i].author << endl;

            cout << "Year of publication: ";
            cin >> b[i].yearPublished;
            file << b[i].yearPublished << endl;

            cout << "Availability (1 for yes, 0 for no): ";
            cin >> b[i].available;
            file << b[i].available << endl;
        }
    }
    file.close();
}

void searchBookByTitle() {
    fstream file("lib_booklist.txt", ios::in);
    string searchit;
    cout << "Enter title of book to search:\n";
    getline(cin, searchit);

    bool found = false;
    Book temp;

    while (file >> temp.bookID) {
        file.ignore();
        getline(file, temp.Title);
        getline(file, temp.author);
        file >> temp.yearPublished;
        file >> temp.available;
        file.ignore();

        if (temp.Title == searchit) {
            cout << "\nBook found:\n";
            cout << "ID No.: " << temp.bookID << endl;
            cout << "Name: " << temp.Title << endl;
            cout << "Author: " << temp.author << endl;
            cout << "Year of publication: " << temp.yearPublished << endl;
            cout << "Available: " << (temp.available ? "Yes" : "No") << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Book with title \"" << searchit << "\" not found.\n";
    }

    file.close();
}

void displayBooks() {
    fstream file("lib_booklist.txt", ios::in);
    Book temp;
    int i = 0;
    cout << "\nDetails of all books stored in our system:\n";

    while (file >> temp.bookID) {
        file.ignore();
        getline(file, temp.Title);
        getline(file, temp.author);
        file >> temp.yearPublished;
        file >> temp.available;
        file.ignore();

        cout << "\nBook no. " << ++i << ":\n";
        cout << "ID No.: " << temp.bookID << endl;
        cout << "Name: " << temp.Title << endl;
        cout << "Author: " << temp.author << endl;
        cout << "Year of publication: " << temp.yearPublished << endl;
        cout << "Available: " << (temp.available ? "Yes" : "No") << endl;
    }

    if (i == 0) {
        cout << "No books found.\n";
    }

    file.close();
}

int main() {
    int s_n;
    cout << "WELCOME TO OUR LIBRARY MANAGEMENT SYSTEM\n";
    cout << "Type serial no. of operation you want to perform:\n"
         << "1. Add new data\n"
         << "2. Search for a book by its title\n"
         << "3. Display all details of books\n"
         << "4. Exit\n\n";
    cin >> s_n;
    cin.ignore();

    switch (s_n) {
        case 1:
            addBook();
            break;
        case 2:
            searchBookByTitle();
            break;
        case 3:
            displayBooks();
            break;
        case 4:
            cout << "Exited the program.\n";
            return 0;
        default:
            cout << "Enter a valid serial number.\n";
            break;
    }

    return 0;
}
