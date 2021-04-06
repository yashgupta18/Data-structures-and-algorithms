#include <iostream>
#include<stdio.h>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<cmath>
#include<string>

#include<map>
using namespace std; 


int reversell(&arr){
    Node*temp=head;
    Node* fastptr=head->next;
    Node* curr=NULL;
    while(temp!=NULL){
        // Node* curr=temp;
        temp->next=curr;
        curr=temp;
        temp=fastptr;
        fastptr=fastptr->next;
        temp->next=curr;
    }

    return temp;
}

int main(){
	
   int arr[]={2,2,1};
   int n=sizeof(arr)/sizeof(arr[0]);
   cout<<findsingle(arr,n);
    return 0;
}












