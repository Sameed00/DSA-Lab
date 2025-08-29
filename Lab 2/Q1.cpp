#include <iostream>
using namespace std;

int main()	{
	int usize,size,pos;
	
	cout<<"Enter array size ";
	cin>>size;
	int *arr= new int[size];
	int i,num;
	for(i=0;i<size;i++){
		arr[i]=0;
	}
	cout<<"Enter num of values you want to update ";
	cin>>usize;
	for(i=0;i<usize;i++){
		cout<<"Enter what value do you want to update ";
		cin>>num;
		cout<<"At which pos do you want to add it ";
		cin>>pos;
		arr[pos-1]=num;
	}
	for(i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	delete[] arr;

}
