/*
Author: Liam
Date: Feb 5, 2020
32 ms
11.9MB

You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.



*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* solution;
        ListNode** tempNode = &solution;
        ListNode* l1curr = l1;
        ListNode* l2curr = l2;
        int carry = 0;
        int temp = 0;
        
        while(l1curr != NULL || l2curr != NULL){
            if (l1curr != NULL){
                temp += l1curr->val;
                l1curr = l1curr->next;
            }
            if (l2curr != NULL){
                temp += l2curr->val;
                l2curr = l2curr->next;
            }
            
            
            if (carry == 1 && temp !=0){
                temp++;
                carry = 0;
            }
            if (carry == 1 && temp ==0 && (l1curr!=NULL || l2curr!=NULL)){
                temp++;
                carry = 0;
            }
            if (temp >=10) {
                carry = 1;
                temp = temp-10;
            }
            
            (*tempNode) = new ListNode(temp);
            tempNode = &((*tempNode)->next);
            if (carry == 1 && l1curr==NULL && l2curr==NULL){
                (*tempNode) = new ListNode(1);
            }
            temp=0;
            
        }
        return solution;
    }
};