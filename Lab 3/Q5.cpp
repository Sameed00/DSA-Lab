#include <iostream>
using namespace std;

class Node{
	
    public: 
    
	    int data; 
	    Node *next;
	
	    Node(int val){
	        data = val; 
	        next = NULL;
	    }
};


class CNode{
	
    public:
    	
	    int data;
	    CNode *next;
	
	    CNode(int val){
	        data = val;
	        next = NULL;
	    }
};


class DNode{
    public: 
	    int data; 
	    DNode *next;
	    DNode *prev;
	
	    DNode(int val){
	        data = val; 
	        next = NULL;
	        prev = NULL;
	    }
};


class LinkedList{
    public: 
	    Node *head;
	    Node *tail;
	
	    public: 
	    LinkedList(){
	        head = NULL;
			tail = NULL;
	    }
	
	    void pushFront(int val){
	    	
	        Node *newNode = new Node(val);
	        
	        if(head == NULL){
	        	
	            head =newNode;
		   		tail = newNode;
		   		
	            return;
	        }
	        else{ 
	        
	            newNode->next = head;
	            head = newNode;
	        }
	    }
	
	    void print(){ 
	    
	            Node *temp = head;
	
	            while(temp != NULL){
	            	
	                cout << temp->data << "  ->  ";
	                temp = temp->next;
	            }
	            
	            cout << "NULL" << endl;
	        }
	 
};

class DoubleLinkedList{

    public:
	    DNode *head;
	    DNode *tail;
	
	    public:
	    	
	    DoubleLinkedList(){
	    	
	        head = NULL;
			tail = NULL; 
	    }
	
	    void pushFront(int val){
	    	
	        DNode *newDnode = new DNode(val); 
	
	        if(head == NULL){
	        	
	            head = newDnode;
				 
				tail = newDnode;
	        }
	
	        else{
	        	
	            newDnode->next = head; 
	            head->prev = newDnode; 
	            head = newDnode; 
	        }
	    }
	
	    void print(){
	        DNode *temp = head;
	
	        while(temp != NULL){
	        	
	            cout << temp->data << " <=> ";
	            temp = temp->next;
	        }
	        cout << "NULL" << endl;
	    }
	
	    DoubleLinkedList Dconversion(LinkedList &y){
	    	
	        Node *temp = y.head;
	        DoubleLinkedList result;
	        
	        while (temp != NULL){
	        	
	            result.pushFront(temp->data); 
	            temp = temp -> next;
	        }
	        return result;
	    }
};

class CircularLL{
    	public:
    	
   		CNode *head;
    	CNode *tail;

    	CircularLL(){
        	head = NULL;
			tail = NULL;
    }

    void pushFront(int val){
    	
        CNode *newCNode = new CNode(val);

        if(head == NULL){
        	
        	
            head =newCNode;
			 tail = newCNode;
            tail->next = newCNode;
            
        }
        else
		{
			
            newCNode->next = head;
            head = newCNode;
            tail->next = head;
        }
    }

    void print(){
    	
        if(head == NULL){
            cout << "EMPTY LIST" << endl;
            return;
        }
        
        cout << " -> ";
        cout << head->data << " -> ";
        CNode *temp = head->next;


        while(temp != head){
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << " -> " << endl;
    }


    CircularLL Cconversion(LinkedList &l){
    	
    	
        Node *temp = l.head;
         CircularLL result;

        while(temp != NULL){
            result.pushFront(temp->data);
            temp = temp->next;
        }

        return result;
    }
};


int main(){

    LinkedList llone;
    DoubleLinkedList dllone;
    CircularLL cllone; 
    llone.pushFront(20);
    llone.pushFront(40);
    llone.pushFront(60);
    llone.pushFront(80);
    cout << "Single Linked List(ORIGINAL): ";
    llone.print();

    cout << "Circular Linked List(CONVERTED): ";
    cllone = cllone.Cconversion(llone);
    cllone.print();
    

    cout << "Doubly Linked  List(CONVERTED): ";
    dllone = dllone.Dconversion(llone);
    dllone.print();

    

return 0;
}
