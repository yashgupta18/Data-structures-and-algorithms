#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std; 

struct Node 
{
   int data; 
   vector<Node*>child; 
}; 

Node *newNode(int data) 
{ 
    Node *temp = new Node; 
    temp->data = data; 
    return temp; 
} 


vector<vector <int> > levelOrder(Node* root){
    queue<Node*> q;
    vector<vector <int> > v;
    vector<int> vecTemp;
	if(root==NULL) return v;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp==NULL){
            v.push_back(vecTemp);
            vecTemp.clear();
            if(q.empty()){
                return v;
            }
            else{
                q.push(NULL);
            }
        }
        else{
            vecTemp.push_back(temp->data);
            for(auto i:temp->child){
                q.push(i);
            }
        }
    }
}

int main(){
	Node *root = newNode(1); 
    (root->child).push_back(newNode(2)); 
    (root->child).push_back(newNode(3)); 
    (root->child).push_back(newNode(4)); 
    (root->child).push_back(newNode(5)); 
    (root->child[0]->child).push_back(newNode(6)); 
    (root->child[0]->child).push_back(newNode(7)); 
    (root->child[2]->child).push_back(newNode(8)); 
    (root->child[3]->child).push_back(newNode(9)); 
    (root->child[3]->child).push_back(newNode(10)); 
    (root->child[3]->child).push_back(newNode(11)); 

    cout<<"LEVEL=";
    vector<vector <int> > v=levelOrder(root);
    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = 0; j < v[i].size(); ++j)
        {
            cout<<v[i][j]<<" ";
        }
    }
    cout<<endl;
}














