#include <iostream>
using namespace std;

int main() {
    
    float **arr;
    int departs, i, j, x, y;
    
    cout << "enter total number of departs: ";
    cin >> departs;
    
    int emp[departs];
    float avgdepart[departs];
    
    arr = new float*[departs];
    
    for (i = 0; i < departs; i++) {
        cout << "enter number of employees for depart " << i + 1 << ": ";
        cin >> emp[i];
        arr[i] = new float[emp[i]];
    }
    
    cout << "enter employe salary depart wise." << endl;
    
    for (i = 0; i < departs; i++) {
        for (j = 0; j < emp[i]; j++) {
            cout << "enter salary of emp " << j + 1 << " from depart " << i + 1 << " : ";
            cin >> arr[i][j];
        }
    }
    
    cout << "printing data for all emps." << endl;
    
    for (i = 0; i < departs; i++) {
        for (j = 0; j < emp[i]; j++) {
            cout << " " << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    for (i = 0; i < departs; i++) {
        float high = 0.0, total = 0.0;
        
        for (j = 0; j < emp[i]; j++) {
            total = total + arr[i][j];
            if (arr[i][j] > high) {
                high = arr[i][j];
                x = i;
                y = j;
            }
        }
        
        avgdepart[i] = total / emp[i];
        
        cout << "highest salry for depart " << i + 1 << " was: $" << high << " at position (" << x + 1 << "," << y + 1 << ")" << endl;
    }
    
    float departhigh = 0;
    
    for (i = 0; i < departs; i++) {
        if (avgdepart[i] > departhigh) {
            departhigh = avgdepart[i];
            x = i;
        }
    }
    
    cout << "depart with most avg high salary was depart no: " << x + 1 << " with avg salary of $" << departhigh;
    
    for (i = 0; i < departs; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

