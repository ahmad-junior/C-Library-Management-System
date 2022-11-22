// Custom Header Files
#include "mFun.h"

// Function Prototypes
// Backend Functions
string Menu();

// Driver Program
int main() {
    while(true){
        flushInput();
        clearScreen();
        string choice = Menu();
        
        // Calling the functions
        switch (choice[0]){
        	case '1':
        		addBook();
        		break;
        	case '2':
        		delBook();
        		break;
        	case '3':
        		updateBook();
        		break;
        	case '4':
        		viewBooks();
        		break;
        	default:
        		cout << "Invalid Input! Try Again." << endl;
        		pauseProgram();
		}
    }
    return 0;
}

// User Menu
string Menu(){
    flushInput();
    cout << "\t\tWelcome to Library Management System\n" << endl;
    cout << "1. Add Book\n2. Delete Book\n3. Update Book\n4. View Books" << endl;
    
    // Taking input
    string userSelection;
    cout << "Your Selection: ";
    getline(cin, userSelection);
    

    return userSelection;
}