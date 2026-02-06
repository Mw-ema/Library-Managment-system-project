#include <iostream>
using namespace std;

const int MAX_BOOKS = 50;
const int TITLE_LEN = 50;

char books[MAX_BOOKS][TITLE_LEN];
int bookCount = 0;

// Add a book
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        cout << "Library is full!\n";
        return;
    }

    cout << "Enter book title: ";
    cin.ignore();
    cin.getline(books[bookCount], TITLE_LEN);

    bookCount++;
    cout << "Book added successfully.\n";
}

// Display all books
void displayBooks() {
    if (bookCount == 0) {
        cout << "No books in the library.\n";
        return;
    }

    cout << "\nBooks in the library:\n";
    for (int i = 0; i < bookCount; i++) {
        cout << i + 1 << ". " << books[i] << endl;
    }
}

// Find a book
void findBook() {
    char search[TITLE_LEN];
    cout << "Enter book title to find: ";
    cin.ignore();
    cin.getline(search, TITLE_LEN);

    for (int i = 0; i < bookCount; i++) {
        bool match = true;
        for (int j = 0; search[j] != '\0' || books[i][j] != '\0'; j++) {
            if (search[j] != books[i][j]) {
                match = false;
                break;
            }
        }

        if (match) {
            cout << "Book found at position " << i + 1 << ".\n";
            return;
        }
    }

    cout << "Book not found.\n";
}

// Delete a book
void deleteBook() {
    char del[TITLE_LEN];
    cout << "Enter book title to delete: ";
    cin.ignore();
    cin.getline(del, TITLE_LEN);

    for (int i = 0; i < bookCount; i++) {
        bool match = true;
        for (int j = 0; del[j] != '\0' || books[i][j] != '\0'; j++) {
            if (del[j] != books[i][j]) {
                match = false;
                break;
            }
        }

        if (match) {
            for (int k = i; k < bookCount - 1; k++) {
                for (int j = 0; j < TITLE_LEN; j++) {
                    books[k][j] = books[k + 1][j];
                }
            }
            bookCount--;
            cout << "Book deleted successfully.\n";
            return;
        }
    }

    cout << "Book not found.\n";
}

int main() {
    int choice;

    do {
        cout << "\n--- Simple Library System ---\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Find Book\n";
        cout << "4. Delete Book\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: findBook(); break;
            case 4: deleteBook(); break;
            case 0: cout << "Goodbye.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
