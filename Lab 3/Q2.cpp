#include <iostream>
using namespace std;

class Node{
	
	public:
		
		int data;
		Node* next;
		
	
	Node(int val){
		data = val;
		next= nullptr;
	}
	
};

Node * mergeTwoList(Node * h1,Node *h2){
	
		if (h1==NULL||h2==NULL){
			if (h1==NULL){
				return h2;
			}
			else{
				return h1;
			}
		}
		//case 1
		if (h1->data<=h2->data){
			
			h1->next = mergeTwoList(h1->next,h2);
			return h1;
		}
		
		else{
			//case2 
			h2->next = mergeTwoList(h1,h2->next);
			return h2;
		}
}



 // basic linked list class
class LinkedList{
	
	
	
	public:
		Node* head;
	Node* tail;
		LinkedList(){
			
			head= nullptr;
			tail = nullptr;
		}
	
		void push_front(int val){
			
			Node* newNode = new Node(val);
			
			if (head==nullptr){
				head = newNode;
				tail = newNode;
			}
			else{
				newNode->next = head; 
				head= newNode;
				
			}
		}
		
		void push_back(int val){
			
			Node * newNode = new Node(val);
			
			if (head == nullptr){
				
				head=newNode;
				tail = newNode;
				
			}
			
			else{
				tail->next = newNode;
				tail = newNode;
				
			}
		} 
		
		
		
		void pop_front(){
			
			if (head==nullptr){
				cout <<"LL is empty"<<endl;
				return;
			}
			else{
				Node *temp = head;
				head = head->next;
				temp->next = nullptr;
				
				delete temp;
				
				
			}
		}
		
		void pop_back(){
			
			if (head==nullptr){
				cout <<"LL is empty"<<endl;
				return;
			}
			else{
				Node * prevNode = head;
				
				while (prevNode->next != tail){
					
					prevNode=prevNode->next;
					
					
				}
				prevNode->next = nullptr;
				delete tail;
				tail = prevNode;
			}
		}
		
		
		void insert(int val,int pos){
			if (pos<0){
				cout <<"Invalid Pos"<<endl;
				return;
			}
			else if (pos==0){
				push_front(val);
			}
			else{
				
				Node* temp= head;
				for (int i=0;i<pos-1;i++){
					temp = temp->next;
					if (temp== nullptr){
						cout<<"Invalid Pos, out of bouund"<<endl;
						return;
						
					}	
					
				}
				
				
				Node * newNode = new Node(val);
				newNode->next = temp->next;
				temp->next = newNode;
			}
		}
		void PrintLL(){
			Node* temp = head;
			
			while (temp!=nullptr){
				
				cout <<  temp->data<<"-> ";
				
				temp = temp->next;
			}
			cout <<"NULL"<<endl;
		}
		
		
		int search(int find){
			Node * temp = head;
			int index=0;
			while(temp!=nullptr){
				if (temp->data == find){
					return index;
				}
				else{
					temp = temp->next;
					index++;
				}
			}
			return -1;
			
		}
		
		
	void reverseList(){
		
		Node * prev = NULL;
		Node * curr = head;
		Node * next = NULL;
		
		while(curr!=NULL){
			next =curr->next;
			curr->next = prev;
			
			prev= curr;
			curr= next;
		}
		head = prev;
	}
		
		 
};


int main(){
	LinkedList list1;
	
	list1.push_front(40);
	list1.push_front(30);
	list1.push_front(20);
	list1.push_front(10);
	list1.PrintLL();

  LinkedList list2;
	cout <<"Priting 2nd list."<<endl;
	list2.push_front(55);
	list2.push_front(45);
	list2.push_front(35);
	list2.push_front(25);
	list2.PrintLL();
	
	cout <<"printing merged list"<<endl;
	LinkedList list3;
	Node* temp=mergeTwoList(list1.head,list2.head);
	list3.head= temp;
	list3.PrintLL();
}
	

