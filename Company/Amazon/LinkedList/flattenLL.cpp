#include <iostream>
#include<unordered_map>
#include<vector>
#include<stack>
using namespace std;
 
// Structure of given Linked list
struct Node {
    int data;
    struct Node* right;
    struct Node* down;
 
    Node(int x)
    {
        data = x;
        right = NULL;
        down = NULL;
    }
};

void push(Node** head_ref, int new_data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->right = NULL;
    new_node->data = new_data;
    new_node->down = (*head_ref);
 
    (*head_ref) = new_node;
}


// Function to print the
// linked list
void printList(Node* Node)
{
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->down;
    }
}


Node* mergeList(Node* L1, Node* L2){
    Node* temp= NULL;
    push(&temp, 0);
    Node* res=temp;

    while(L1!=NULL && L2!=NULL){
        if(L1->data < L2->data){
            temp->down=L1;
            temp=temp->down;
            L1=L1->down;
        }
        else{
            temp->down=L2;
            temp=temp->down;
            L2=L2->down;
        }
    }

    if(L1){
        temp->down=L1;
    }
    else{
        temp->down=L2;
    }
    return res->down;
}

Node* flatten(Node* root){
    if(root==NULL || root->right==NULL)
        return root;

    //recur
    root->right=flatten(root->right);

    //flatten
    root=mergeList(root, root->right);
    return root;

}

// Driver Code
int main()
{
// https://www.geeksforgeeks.org/flattening-a-linked-list-set-2/
    
    // Concept used of Striver https://www.youtube.com/watch?v=ysytSSXpAI0
// Steps
// 1.Do last 2
// 2.then combined and third last and so on


//     Input: 
// 5 -> 10 -> 19 -> 20
// |     |     |     |
// V    20     V    35
// 7          22     |
// |          |      40
// V          V      |
// 8          50     45
// |              
// V               
// 30              

// Output: 5 7 8 10 19 20 20 22 30 35 40 45 50 

    Node* root = NULL;
 
    // Given Linked List
    push(&root, 30);
    push(&root, 8);
    push(&root, 7);
    push(&root, 5);
 
    push(&(root->right), 20);
    push(&(root->right), 10);
 
    push(&(root->right->right), 50);
    push(&(root->right->right), 22);
    push(&(root->right->right), 19);
 
    push(&(root->right->right->right), 45);
    push(&(root->right->right->right), 40);
    push(&(root->right->right->right), 35);
    push(&(root->right->right->right), 20);
 
    // Flatten the list
    root = flatten(root);
 
    // Print the flatened linked list
    printList(root);
 
    return 0;
}