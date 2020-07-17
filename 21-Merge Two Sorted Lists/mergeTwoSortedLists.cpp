/*
Author: Liam
Date: Jul 17, 2020
Runtime: 12 ms, faster than 38.38% of C++ online submissions for Merge Two Sorted Lists.
Memory Usage: 14.4 MB, less than 77.30% of C++ online submissions for Merge Two Sorted Lists.

Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4




*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        ListNode l3(0);
        ListNode* curr = &l3;
        
        while(l1 != NULL && l2 != NULL){
            if(l1->val <= l2->val){
                curr->next = l1;
                l1 = l1->next;
            }
            else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        
        if(l1 == NULL){
            curr->next = l2;
        }
        
        if(l2 == NULL){
            curr->next = l1;
        }
        
        return l3.next;
    }
};

/*
Testcases

[1,1,1]
[1,1,1]
[1]
[1,2,3,4,5]
[]
[1,2,3]
[1,2,4]
[1,3,4]
[]
[]

*/