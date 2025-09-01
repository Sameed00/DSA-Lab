#include <iostream>
using namespace std;

int * resizearr(int*arr,int old,int new_);

int main(){
	
	int *exp;
	int months;
	float total=0.0,avg=0.0;
	string check;
	int i,j;
	
	cout <<"Enter Number of Months:";
	cin  >>months;
	
	exp = new int[months];
	cout <<"Enter month wise expenses."<<endl;
	for (i=0;i<months;i++){
		
		cout <<"Enter Expenses for Month "<<i+1<<": ";
		cin >> exp[i]; 
	}
	
	cout<<"Do you want to add more data for more months (yes/no):";
	cin >>check;
	
	if (check=="yes"){
		int add;
		
		cout <<"How many months do you want to add?";
		cin >>add;
		exp = resizearr(exp,months,months+add);
		
		for (i=months;i<months+add;i++){
			cout <<"Enter Expenses for Month " <<i+1<<": ";
			cin >>exp[i];
		}
		months=months+add;
	}
	
	cout <<"PRINTING DATA FOR ALL MONTHS."<<endl;
	
	for (i=0;i<months;i++){
		cout <<"Expense for Month "<<i+1<<": $ "<<exp[i]<<endl;
		total = total + exp[i];
		
	}
	cout <<"Your total Expense for all months were: $"<<total<<endl;
	avg=  total/months;
	cout <<"Your avg expense Per month was : $"<<avg<<endl;
	
	
	delete []exp;
}

int * resizearr(int*arr,int old,int new_){
	
	if (old==new_){
		return arr;
	}
	int * temp = new int[new_];
	if (old<new_){
		for (int i=0;i<old;i++){
			temp[i] = arr[i];
		}
		
	}
	else{
		for (int i=0;i<new_;i++){
			temp[i] = arr[i];
		}
	}
	delete []arr; 
	return temp;
}
