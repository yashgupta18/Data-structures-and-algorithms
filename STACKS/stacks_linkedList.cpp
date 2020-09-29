#include <iostream>
using namespace std;
#define MAX 1000 

class Node { 
	int data;
	node *next;
};

class Stack{
	node *front;
public:
	Stack(){front=NULL;}
	void push(int);
	void pop();
	int top();
}

void Stack::push(int d){
	node *temp;
	temp-new Node();
	temp->data=d;
	if(front==NULL){
		temp->next=NULL;
	}
	else{
		temp->next=front;
	}
	
	front=temp;
}

int Stack :: pop()
{
	if(front==NULL){
		cout<<"underflow" 
	}

	else{
		node *temp=new Node();
		front=front=>next;
		delete(temp);
	}
}

int Stack :: top()
{
	return front->data;
}

int main() {
 	Node 
}