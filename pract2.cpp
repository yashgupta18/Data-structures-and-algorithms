#include <iostream>
using namespace std; 
  
/* Link list node */
class Node  
{  
    public: 
    int data;  
    Node* next;  
};  
  
/* Reverses the linked list in groups 
of size k and returns the pointer 
to the new head node. */
Node *reverse (Node *head, int k)  
{  
    if(head==NULL||k==1) return head;
        int num=0;
        Node *preheader = new Node(-1);
        preheader->next = head;
        Node *cur = preheader, *nex, *tmp, *pre = preheader;
        while(cur = cur->next) 
            num++;
        while(num>=k) {
            cur = pre->next;
            nex = cur->next;
            for(int i=1;i<k;i++) {
                tmp= nex->next;
                nex->next = pre->next;
                pre->next = nex;
                cur->next = tmp;
                nex = tmp;
            }
            pre = cur;
            num-=k;
        }
        return preheader->next;
}  
  
/* UTILITY FUNCTIONS */
/* Function to push a node */
void push(Node** head_ref, int new_data)  
{  
    /* allocate node */
    Node* new_node = new Node(); 
  
    /* put in the data */
    new_node->data = new_data;  
  
    /* link the old list off the new node */
    new_node->next = (*head_ref);      
  
    /* move the head to point to the new node */
    (*head_ref) = new_node;  
}  
  
/* Function to print linked list */
void printList(Node *node)  
{  
    while (node != NULL)  
    {  
        cout<<node->data<<" ";  
        node = node->next;  
    }  
}  
  
/* Driver code*/
int main()  
{  
    /* Start with the empty list */
    Node* head = NULL;  
  
    /* Created Linked list is 1->2->3->4->5->6->7->8->9 */
    push(&head, 9);  
    push(&head, 8);  
    push(&head, 7);  
    push(&head, 6);  
    push(&head, 5);  
    push(&head, 4);  
    push(&head, 3);  
    push(&head, 2);  
    push(&head, 1);      
  
    cout<<"Given linked list \n";  
    printList(head);  
    head = reverse(head, 3);  
  
    cout<<"\nReversed Linked list \n";  
    printList(head);  
  
    return(0);  
}  