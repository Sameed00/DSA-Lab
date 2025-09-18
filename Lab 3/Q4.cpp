#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node * next;
		
		Node(int val){
			data = val;
			next = NULL;
		}
		
};

class CircularList{
	
	Node * head;
	Node * tail;
	
	
	public:
		
		CircularList(){
			head=NULL;
			tail = NULL;	
		}
		
		
		void push_back(int val){
			Node * newNode = new Node(val);
			
			if (head==NULL){
				head=newNode;
				tail = newNode;
				tail->next= head; // circular 
			}
			else{
				newNode->next=  head;
				tail->next = newNode;
				tail = newNode;
			}
		}
		
		void PrintLL(){
			
			if (head==NULL){
				cout <<"Empty List"<<endl;
				return ;
			}
			
			Node* temp = head;
			do {
    			cout << temp->data << "->";
    			temp = temp->next;
    			
			} while (temp != head);
			
			cout << "HEAD" << endl;
		}
		
		
		void PosSurvivor(int x){
			if(head==NULL){
				cout <<"Empty list"<<endl;
				return;
				
			}
			if (x<=0){
				cout <<"Invalid Position."<<endl;
				return;
			}
			
			Node *temp =head;
			Node *prev= tail;
			
			
			while(head!=tail){
				
				for (int i=0;i<x-1;i++){
					prev = temp;
					temp = temp->next;
					
				}
				
				Node * ValTodel = temp;
				prev->next=  temp->next;
				temp = temp->next;
				
				if (ValTodel==head){
					head= head->next;
					
				}
				if (ValTodel == tail){
					tail = prev;
				}
				delete ValTodel;
			}
			
			cout <<"THE SURVIVOR IS "<<head->data<<endl;
		}
		
		
};


int main(){
	
	CircularList Clist1;
	
	int N=7;
	int k=3;
	
	  Clist1.push_back(1);
    Clist1.push_back(2);
    Clist1.push_back(3);
    Clist1.push_back(4);
    Clist1.push_back(5);
    Clist1.push_back(6);
    Clist1.push_back(7);
	cout <<"Players: ";
	Clist1.PrintLL();
	
	Clist1.PosSurvivor(k);
}
