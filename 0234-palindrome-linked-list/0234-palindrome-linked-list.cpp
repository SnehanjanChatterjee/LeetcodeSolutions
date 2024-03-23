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
private:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev=NULL, *curr=head, *next=head;
        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;

        ListNode* start = head;
        ListNode* mid = head;
        ListNode* end = head;

        // Find middle point
        while(end->next != NULL && end->next->next != NULL) {
            mid = mid->next;
            end = end->next->next;
        }

        // Reverse 2nd half
        mid->next = reverseList(mid->next);
        mid = mid->next;

        // Compare 2nd half with 1st half
        while(mid != NULL) {
            if(start->val != mid->val) return false;
            start = start->next;
            mid = mid->next;
        }
        
        return true;
    }
};