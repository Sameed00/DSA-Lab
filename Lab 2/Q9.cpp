#include <iostream>
using namespace std;

int main(){
	
	int **arr;
	int **compressed;
	int nonzero=0;
	int rows;
	int columns;
	int i,j,count;
	
	cout <<"enter number of rows: ";
	cin >> rows;
	
	cout <<"enter number of columns: ";
	cin >> columns;
	
	arr=new int*[rows];
	for(i=0;i<rows;i++){
		arr[i]=new int[columns];
	}
	
	cout <<"enter values for the matrix."<<endl;
	for(i=0;i<rows;i++){
		for(j=0;j<columns;j++){
			cout <<"enter value for ("<<i<<","<<j<<"): ";
			cin >> arr[i][j];
			if(arr[i][j]!=0){
				nonzero++;
			}
		}
	}
	
	compressed=new int*[nonzero];
	for(i=0;i<nonzero;i++){
		compressed[i]=new int[3];
	}
	
	cout <<"normal matrix:"<<endl;
	for(i=0;i<rows;i++){
		for(j=0;j<columns;j++){
			cout <<" "<<arr[i][j]<<" ";
		}
		cout <<endl;
	}
	
	count=0;
	cout <<"compressed form:"<<endl;
	for(i=0;i<rows;i++){
		for(j=0;j<columns;j++){
			if(arr[i][j]!=0){
				compressed[count][0]=i;
				compressed[count][1]=j;
				compressed[count][2]=arr[i][j];
				count++;
			}
		}
	}
	
	for(i=0;i<nonzero;i++){
		for(j=0;j<3;j++){
			cout <<" "<<compressed[i][j]<<" ";
		}
		cout <<endl;
	}
	
	for(i=0;i<rows;i++){
		delete [] arr[i];
	}
	delete [] arr;
	
	for(i=0;i<nonzero;i++){
		delete [] compressed[i];
	}
	delete [] compressed;
}
