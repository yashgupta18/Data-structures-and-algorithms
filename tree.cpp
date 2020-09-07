// C++ program to insert element in binary tree 
// #include<bits/stdc++.h> 
#include <iostream>
// #pragma once
// #ifndef _QUEUE_
#include <queue>
using namespace std; 
  
/* A binary tree node has key, pointer to left child 
and a pointer to right child */
  
struct Node { 
  int key; 
  Node *left, *right; 
  Node (int x) 
  { 
     key = x; 
     left = right = NULL; 
  } 
}; 
  
/* Inorder traversal of a binary tree*/
void inorder(Node* temp) 
{ 
    if (!temp) 
        return; 
  
    inorder(temp->left); 
    cout << temp->key << " "; 
    inorder(temp->right); 
} 
  
/*function to insert element in binary tree */
void insert(Node* temp, int key) 
{ 
    queue <Node*> q; 
    q.push(temp); 
  
    // Do level order traversal until we find 
    // an empty place.  
    while (!q.empty()) { 
        Node* temp = q.front(); 
        q.pop(); 
  
        if (!temp->left) { 
            temp->left = new Node(key); 
            break; 
        } else
            q.push(temp->left); 
  
        if (!temp->right) { 
            temp->right = new Node(key); 
            break; 
        } else
            q.push(temp->right); 
    } 
} 


  
// Driver code 
int main() 
{ 
    Node* root = new Node(10); 
    root->left = new Node(11); 
    root->left->left = new Node(7); 
    root->right = new Node(9); 
    root->right->left = new Node(15); 
    root->right->right = new Node(8); 
    
    
    // cout << "Inorder traversal before insertion:"; 
    // inorder(root); 
  
    int key = 12; 
    insert(root, key); 
  
    // cout << endl; 
    // cout << "Inorder traversal after insertion:"; 
    // inorder(root); 
  
    return 0; 
} 