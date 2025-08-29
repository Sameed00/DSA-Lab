#include <iostream>
using namespace std;

int main(){
	
	int **arr;
	int rows,occupy,x,y;
	cout <<"Enter Number of Benches:";
	cin>>rows;
	
	int size[rows];
	
	
	arr= new int*[rows];
	
	cout <<"Enter Seat  Number for Each Bench:"<<endl;
	
	for (int i=0;i<rows;i++){
		cout <<"Enter Seats for Bench" <<i+1<<": ";
		cin >>size[i];
		arr[i]= new int[size[i]];
	}
	
	
	for (int i=0;i<rows;i++){
		
		for (int j=0;j<size[i];j++){
			arr[i][j] =0;
		}
	}
	cout <<"Enter no of seats to occupy:";
	cin >> occupy;
	
	
	for (int i=0;i<occupy;i++){
		cout <<"Enter Bench Number and Seat Number to Occupy it:";
		cin >> x;
		cin >>y;	
		arr[x-1][y-1] =1;		
	}
	
	
	for (int i=0;i<rows;i++){
		for (int j=0;j<size[i];j++){
			cout <<" " <<arr[i][j] <<" ";
			
			
		}
		cout <<endl;
	}
	
	for (int i=0;i<rows;i++){
		delete[] arr[i];
		
	}
	delete[] arr;
	
	
	
}
