#include <iostream>
using namespace std;

class safePointer {
	
	private:
		int* ptr;
    
	public:
		safePointer() {
			ptr = new int;
		}
    
	    void setValue(int value) {
	    	*ptr = value;
	    }
	    
	    int getValue() {
	    	return *ptr;
	    }
	    
	    void release() {
	    	delete ptr;
	    	ptr = nullptr;
	    }
	    
	    ~safePointer() {
	    	if (ptr != nullptr) {
	    		delete ptr;
	    	}
	    }
};

int main() {
	
	int numstd = 5;
	int i, marks;
	
	safePointer* marksarr = new safePointer[numstd];
	
	cout << "enter marks for " << numstd << " students:" << endl;
	for (i = 0; i < numstd; i++) {
		cout << "enter marks for student " << i + 1 << ": ";
		cin >> marks;
		marksarr[i].setValue(marks);
	}

	cout << endl << "recorded marks:" << endl;
	for (i = 0; i < numstd; i++) {
		cout << "student " << i + 1 << ": " << marksarr[i].getValue() << endl;
	}

	for (i = 0; i < numstd; i++) {
		marksarr[i].release();
	}
	
	delete[] marksarr;
}
