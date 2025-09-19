#include <iostream>
using namespace std;
int calFactorial(int n){
	
	if (n==1){
		return n;
	}
	
	return n=n*calFactorial(n-1);
}



int main(){
	int num;
	cout <<"Enter number: ";
	cin >>num;
	
	int res =calFactorial(num);
	cout <<"Factorial for "<<num<<" is: "<<res;
}
