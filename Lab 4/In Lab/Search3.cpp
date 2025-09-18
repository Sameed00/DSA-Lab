#include <iostream>
using namespace std;
void bubblesort(int *arr,int bound);
int interpolationSearch(int arr[],int size,int x);
int main(){
	int value;
	cout <<"Enter Number of Values: ";
	cin >>value;
	
	int *arr;
	arr = new int[value];
	
	for (int i=0;i<value;i++){
		cout <<"Enter Value "<<i+1<<" for the Array: ";
		cin >> arr[i];
	}
	
	
	
	bubblesort(arr,value-1);
	bool flag=true;
	int diff = arr[1]-arr[0];
	
	for (int i=0;i<value-1;i++){
		
		if (arr[i+1]-arr[i]!=diff){
			cout <<"data no uniform";
			return 1;
		}
	}
	
	int temp =interpolationSearch(arr, value,30);
	if (temp==-1){
		cout <<"Value not found";
		
	}
	else{
		cout <<"value found at: "<<temp<<endl;
	}
	
	
	
}


void bubblesort(int *arr,int bound){
	int temp;
		bool noswap = false;
	int  boundry=bound;
	while(noswap==false){
		noswap=true;
		for (int i=0;i<boundry;i++){
			if (arr[i]>arr[i+1]){
				temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
				noswap = false;
			}
			
		}
		boundry--;
	}
}
int interpolationSearch(int array[],int size,int x){
	int low = 0 ;
	int high = size - 1 ;
	while(low<=high&&x>=array[low]&&x<=array[high]){
		if(low==high){
			if(array[low]==x){
				return low ;
			}
			return -1;
		}
		int pos = low + ((x-array[low])*(high-low)) / (array[high]-array[low]) ;
		if(array[pos] == x) return pos ;
		if(array[pos]<x) low = pos + 1 ;
		else high = pos - 1 ;
	}
	return -1 ; 
}
