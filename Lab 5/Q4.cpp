#include <iostream>
using namespace std;


int ackermann(int m,int n){
	
	if (m==0 ){
		return n+1;
		
	}
	else if (m>0 && n==0){
		return ackermann(m-1,1);
	}
	else if (m>0 && n>0){
		return ackermann(m-1,ackermann(m,n-1));
	}
}

int main(){
	int m,n;
	
	cout <<"Enter Values for M and N: ";
	cin >> m;
	cin >> n;
	cout <<"Ackermann(" << m <<","<< n <<") = " << ackermann(m,n)<<endl;

	/*
	ackermann(1, 2):
	
	A(1, 2)
	= A(0, A(1, 1))                  // since m>0 and n>0
	
	Now find A(1, 1):
	A(1, 1)
	= A(0, A(1, 0))
	
	Now find A(1, 0):
	A(1, 0)
	= A(0, 1)                        // since m>0 and n=0
	= 1 + 1 = 2
	
	So, A(1, 0) = 2
	
	Now go back:
	A(1, 1) = A(0, A(1, 0)) = A(0, 2)
	A(0, 2) = 2 + 1 = 3
	
	So, A(1, 1) = 3
	
	Now go back again:
	A(1, 2) = A(0, A(1, 1)) = A(0, 3)
	A(0, 3) = 3 + 1 = 4
	
	 A(1, 2) = 4
*/
}
