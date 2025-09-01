#include <iostream>
using namespace std;

int main() {
	
    int categ, searchid;
    bool found = false;
    
    cout << "enter number of categories to store : ";
    cin >> categ;

    int *numbooks = new int[categ];
    int **books = new int*[categ];

    for (int i = 0; i < categ; i++) {
    	
        cout << "enter number of books in category " << i + 1 << ": ";
        cin >> numbooks[i];

        books[i] = new int[numbooks[i]];
        
        for (int j = 0; j < numbooks[i]; j++) {
        	
            cout << "enter book id for category " << i + 1 
                 << ", book " << j + 1 << ": ";
                 
            cin >> books[i][j];
        }
    }

    cout << "enter book id to search: ";
    cin >> searchid;

    for (int i = 0; i < categ; i++) {
    	
        for (int j = 0; j < numbooks[i]; j++) {
        	
            if (books[i][j] == searchid) {
            	
                cout << "book id " << searchid 
                     << " found in category " << i + 1 << endl;
                     
                found = true;
            }
        }
    }
    
    if (!found) {
    	
        cout << "book id " << searchid 
             << " not found in any category." << endl;
    }

    for (int i = 0; i < categ; i++) {
    	
        delete[] books[i];
    }
    
    delete[] books;
    delete[] numbooks;
}
