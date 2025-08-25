#include <iostream>
using namespace std;

class BankAccount{
	int balance;
  public:
  	BankAccount(){
  		bal=0;
  		cout << "Balance of account 1 : " << bal << endl ;
	  }
	BankAccount(int b){
		bal = b ;
		cout << "Balance of account 2 : " << bal << endl ;
	}
	BankAccount(const BankAccount &acc){
		bal = acc.bal - 200 ;
		cout << "Balance of account 3 : " << bal << endl ;
		cout << "Balance of account 2 : " << acc.bal << endl ;
	}
  	
};
int main(){
	BankAccount account1 ;
	BankAccount account2(1000) ;
	BankAccount account3(account2) ;
}
