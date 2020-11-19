#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std; 

struct ExpressionTree{
  char data;
  ExpressionTree *left, *right;
};

ExpressionTree* newNode(char item) 
{ 
    ExpressionTree *temp = new ExpressionTree;
    temp->left = temp->right = NULL;
    temp->data = v;
    return temp;
}

ExpressionTree* constructTree(char postfix[])
{
    stack<ExpressionTree *> st;
    ExpressionTree *t, *t1, *t2;
 
    // Traverse through every character of
    // input expression
    for (int i=0; i<strlen(postfix); i++)
    {
        // If operand, simply push into stack
        if (!isOperator(postfix[i]))
        {
            t = newNode(postfix[i]);
            st.push(t);
        }
        else // operator
        {
            t = newNode(postfix[i]);
 
            // Pop two top nodes
            t1 = st.top(); // Store top
            st.pop();      // Remove top
            t2 = st.top();
            st.pop();
 
            //  make them children
            t->right = t1;
            t->left = t2;
 
            // Add this subexpression to stack
            st.push(t);
        }
    }
 
    //  only element will be root of expression
    // tree
    t = st.top();
    st.pop();
 
    return t;
}
void postr(node* p) 
{ 
    if (p == NULL) { 
        return; 
    } 
    else { 
        postr(p->left); 
        postr(p->right); 
        printf("%c ", p->data); 
    } 
} 

int main() 
{ 
    node* s = NULL; 
    char a[] = "*+ab-cd"; 
    add(&s, a); 
    printf("The Infix expression is:\n "); 
    inr(s); 
    printf("\n"); 
    printf("The Postfix expression is:\n "); 
    postr(s); 
    return 0; 
} 




