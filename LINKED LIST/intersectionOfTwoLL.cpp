/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getAns(ListNode *headA, ListNode *headB) {
        ListNode *tempA=headA;
        ListNode *tempB=headB;
         while(tempA!=NULL || tempB!=NULL){
             if(tempA==tempB) return tempA;
             tempA=tempA->next;
             tempB=tempB->next;
        }
        return NULL;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL) return NULL;
        ListNode *temp=headA;
        int countA=0, countB=0;
        while(temp!=NULL){
            countA++;
            temp=temp->next;
        }
        temp=headB;
        while(temp!=NULL){
            countB++;
            temp=temp->next;
        }
        if(countA==countB){
            return getAns(headA, headB);
        }
        
        int d=abs(countA-countB);
        if(countA>countB){
            temp=headA;
            while(temp!=NULL && d>0){
                d--;
                temp=temp->next;
                
            }
            return getAns(temp, headB);
        }else{
            temp=headB;
            while(temp!=NULL && d>0){
                d--;
                temp=temp->next;
                
            }
            return getAns(headA, temp);
        }
        return NULL;
    }
};