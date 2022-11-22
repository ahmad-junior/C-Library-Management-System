#include <iostream>
#include <stdio.h>

using namespace std;

// Creating classe
class Book{
    // creating the private variables
    private:
        string _bookId, _bookName, _bookAuthor;
    public:
    // Set Variable Values
        // Set book name
        void setBookName(string bookName){
            _bookName = bookName;
        }
        // Set book id
        void setBookId(string bookId){
            _bookId = bookId;
        }
        // Set book name
        void setBookAuthor(string bookAuthor){
            _bookAuthor = bookAuthor;
        }

    // Get private variables
    string bookName(){
        return _bookName;
    }
    string bookId(){
        return _bookId;
    }
    string bookAuthor(){
        return _bookAuthor;
    }
        
};

Book books[3]; // Set the Max Limit

// Global Book counter
int counter = 0;

// Clear Screen
void clearScreen() {
    system("clear"); 
}

// Pause Program
void pauseProgram(){
    cout << "Press any key to continue..." << endl;
    getchar();
}

// Flush Input
void flushInput(){
    // Flush the buffer
    fflush(stdout); // Use fflush(stdin) for windows
}

// Add book
void addBook(){
    flushInput();
    clearScreen();
    // Declaration of variables
    string bookId, bookName, bookAuthor;

    if(counter >= 3){
        cout << "Can't add book the upper limit exceds." << endl;
        pauseProgram();
    }
    else{
        // Taking input
        cout << "ID: ";
        getline(cin, bookId);

        cout << "Name: ";
        getline(cin, bookName);

        cout << "Author: ";
        getline(cin, bookAuthor);

        // Set book Details
        books[counter].setBookId(bookId);
        books[counter].setBookName(bookName);
        books[counter].setBookAuthor(bookAuthor);

        clearScreen();
        counter++;
        cout << "Book: " << bookName << " Added!" << endl;
        pauseProgram();
        
    }
}

// View Books
void viewBooks(){
	flushInput();
    clearScreen();
	if(counter == 0){
		cout << "Empty! Try to add." << endl;
	}
	else{
		for(int i = 0; i < 3; i++){
		cout <<"| " << books[i].bookName() << " | " << books[i].bookId() << " | "<< books[i].bookAuthor() << " |" << endl;
		}
	}
	pauseProgram();
}

// Delete Book
void delBook(){
    flushInput();
    clearScreen();

    // Declaration of variables
    string bookId;
    bool isFound = false;
    int foundIndex;

	if(counter == 0){
		cout << "Empty! Try to add." << endl;
	}
    else{
        cout << "Enter book ID: ";
        getline(cin, bookId);
        for(int i = 0; i < counter; i++){
            if(books[i].bookId() == bookId){
                isFound = true;
                foundIndex = i;
                cout << "Book: " << books[foundIndex].bookName() << " Deleted!" << endl;
                books[foundIndex].setBookId("");
                books[foundIndex].setBookName("");
                books[foundIndex].setBookAuthor("");
                counter--;
                break;
            }
        }
    }

    if(!isFound){
        cout << "Book not found!" << endl;
    }

    pauseProgram();
}

// Update Book
void updateBook(){
    flushInput();
    clearScreen();

    // Declaration of variables
    string bookId, bookName, bookAuthor;
    bool isFound = false;
    int foundIndex;

    if (counter == 0){
        cout << "Empty! Try to add." << endl;
    }
    else{
        cout << "Enter book ID: ";
        getline(cin, bookId);
        for(int i = 0; i < counter; i++){
            if(books[i].bookId() == bookId){
                isFound = true;
                foundIndex = i;
                cout << "Book: " << books[foundIndex].bookName() << " Edit Mode: On!" << endl;
                cout << "ID: ";
                getline(cin, bookId);
                cout << "Name: ";
                getline(cin, bookName);
                cout << "Author: ";
                getline(cin, bookAuthor);
                books[foundIndex].setBookId(bookId);
                books[foundIndex].setBookName(bookName);
                books[foundIndex].setBookAuthor(bookAuthor);
                break;
            }
        }
    }

    if(!isFound){
        cout << "Book not found!" << endl;
    }

    pauseProgram();
}
