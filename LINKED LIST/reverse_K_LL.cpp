#include <iostream>
#include<unordered_map>
#include<vector>
#include<stack>
using namespace std; 
  

struct Node{
  int data;
  struct Node *next;
};

struct Node *newNode(int item) 
{ 
    struct Node *temp =  (struct Node *)malloc(sizeof(struct Node)); 
    temp->data = item; 
    temp->next = NULL; 
    return temp; 
} 

void traverse(Node* head){
	Node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
}

Node *reverse (Node *head, int k)  
{  
    	if(head==NULL||k==1) return head;
        Node *dummy = newNode(0);
        dummy->next = head;

        Node *cur = dummy, *nex=dummy, *pre = dummy;
        int count=0;
        while(cur->next!=NULL){
        	cur=cur->next;
        	count++;
        } 

        while(count>=k) {
            cur = pre->next;
            nex = cur->next;
            for(int i=1;i<k;i++) {
                cur->next= nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex=cur->next;
            }
            pre = cur;
            count-=k;
        }
        return dummy->next;
}

int main(){
	Node *head= newNode(1);
	head->next=newNode(2);
	head->next->next=newNode(3);
	head->next->next->next=newNode(4);
	head->next->next->next->next=newNode(5);
	head->next->next->next->next->next=newNode(6);
	head->next->next->next->next->next->next=newNode(7);
	head->next->next->next->next->next->next->next=newNode(8);
	// head->next->next->next->next->next->next->next->next=newNode(9);
	int k=3;
	traverse(head);
	cout<<endl;
	head=reverse(head,k);
	traverse(head);

}