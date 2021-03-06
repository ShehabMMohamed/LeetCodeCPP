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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)   return head;
        ListNode* current = head->next;
        head->next = NULL;
        ListNode* prev = reverseList(current);
        current->next = head;
        return prev;
    }

};