#include <iostream>
using namespace std;
void printNumbers(int n){
	
	
	
	if (n!=0){
		cout <<n<<endl;
		printNumbers(n-1);
		
	}
	else{

	cout <<n;
	return;
		}
	
}



int main(){
	int num;
	cout <<"Enter number: ";
	cin >>num;

	printNumbers(num);

}
