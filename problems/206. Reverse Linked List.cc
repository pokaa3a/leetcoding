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
        ListNode* oldNode = NULL;
        ListNode* newNode = NULL;
        while(head){
            newNode = head->next;
            head->next = oldNode;
            oldNode = head;
            head = newNode;
        }
        return oldNode;
    }
};