#include <iostream>
using namespace std;

int printNumbers(int n){
	int temp=n;
	
	
	if (n!=0){
		cout <<n<<endl;
		printNumbers(n-1);
		
	}
	else{

	cout <<n<<endl;

	
	return -1;
		}
	
}



int Printer(int x){
	int count=x;

	
	if (count==0){
		return 1;
	}
	else{
	
		printNumbers(x);
		cout <<endl;
		Printer(x-1);
		count--;
	}
	
	
	
}


int main(){
	int num;
	cout <<"Enter number: ";
	cin >>num;

	Printer(num);

}
