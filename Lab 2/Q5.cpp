#include <iostream>
using namespace std;

int ** addmatrix(int **m1, int r1, int c1, int **m2, int r2, int c2);
int ** submatrix(int **m1, int r1, int c1, int **m2, int r2, int c2);

int main() {
    
    int **m1;
    int **m2;
    int **res;
    int r1, r2, c1, c2;
    int i, j;
    
    cout << "Enter Rows and Columns for Matrix 1: ";
    cin >> r1 >> c1;
    
    cout << "Enter Rows and Columns for Matrix 2: ";
    cin >> r2 >> c2;
    
    m1 = new int*[r1];
    m2 = new int*[r2];
    
    for (i = 0; i < r1; i++) {
        m1[i] = new int[c1];
    }
    
    for (i = 0; i < r2; i++) {
        m2[i] = new int[c2];
    }
    
    cout << "Enter Data for Matrix 1." << endl;
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            cout << "Enter Data for Position (" << i+1 << "," << j+1 << "): ";
            cin >> m1[i][j]; 
        }
    }

    cout << "Enter Data for Matrix 2." << endl;
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            cout << "Enter Data for Position (" << i+1 << "," << j+1 << "): ";
            cin >> m2[i][j]; 
        }
    }
    
    cout << "Two Matrices are Made. Printing both." << endl << endl;
    
    cout << "Matrix 1:" << endl;
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            cout << " " << m1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    cout << "Matrix 2:" << endl;
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            cout << " " << m2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    res = addmatrix(m1, r1, c1, m2, r2, c2);
    if (res) {
        for (i = 0; i < r1; i++) {
            delete [] res[i];
        }
        delete [] res;
    }
    
    res = submatrix(m1, r1, c1, m2, r2, c2);
    if (res) {
        for (i = 0; i < r1; i++) {
            delete [] res[i];
        }
        delete [] res;
    }
    
    for (i = 0; i < r1; i++) {
        delete [] m1[i];
    }
    delete [] m1;
    
    for (i = 0; i < r2; i++) {
        delete [] m2[i];
    }
    delete [] m2;
}

int ** addmatrix(int **m1, int r1, int c1, int **m2, int r2, int c2) {
    
    if (r1 == r2 && c1 == c2) {
        
        int **res = new int*[r1];
        for (int i = 0; i < r1; i++) {
            res[i] = new int[c1];
        }
        
        cout << "Adding Both Matrices." << endl;
        
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c1; j++) {
                res[i][j] = m1[i][j] + m2[i][j];
            }
        }
        
        cout << "Printing Resultant Matrix:" << endl;
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c1; j++) {
                cout << " " << res[i][j] << " ";
            }
            cout << endl;
        }
        
        return res;
    }
    else {
        cout << "Both Matrices do not have the same dimensions!" << endl;
        cout << "Cannot Perform Addition!" << endl;
        return nullptr;
    }
}

int ** submatrix(int **m1, int r1, int c1, int **m2, int r2, int c2) {
    
    if (r1 == r2 && c1 == c2) {
        
        int **res = new int*[r1];
        for (int i = 0; i < r1; i++) {
            res[i] = new int[c1];
        }
        
        cout << "Subtracting Both Matrices." << endl;
        
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c1; j++) {
                res[i][j] = m1[i][j] - m2[i][j];
            }
        }
        
        cout << "Printing Resultant Matrix:" << endl;
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c1; j++) {
                cout << " " << res[i][j] << " ";
            }
            cout << endl;
        }
        
        return res;
    }
    else {
        cout << "Both Matrices do not have the same dimensions!" << endl;
        cout << "Cannot Perform Subtraction!" << endl;
        return nullptr;
    }
}
