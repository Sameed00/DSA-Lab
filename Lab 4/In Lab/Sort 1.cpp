#include <iostream>
using namespace std;

int main(){
	
	int arr[10] ={5,1,3,6,2,9,7,4,8,10};
	int temp;
	bool noswap = false;
	int  boundry=9;
	while(noswap==false){
		noswap=true;
		for (int i=0;i<boundry;i++){
			if (arr[i]<arr[i+1]){
				temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
				noswap = false;
			}
			
		}
		boundry--;
	}
	
	cout <<"Printing Array."<<endl;
	
	
	for(int i=0;i<10;i++){
		cout<<arr[i]<<", ";
	}
}
