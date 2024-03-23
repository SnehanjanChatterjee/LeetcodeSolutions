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
    
    void printList(ListNode* head) {
        ListNode *curr=head;
        while(curr != NULL) {
            cout << curr->val << " -> ";
            curr = curr->next;
        }
    }
    
    int countList(ListNode* head) {
        ListNode *curr=head;
        int count = 0;
        while(curr != NULL) {
            count++;
            curr = curr->next;
        }
        return count;
    }
public:
    // Reference for linking the 2 lists: https://www.youtube.com/watch?v=mD7L5l2NmGU
    void reorderList(ListNode* head) {
        ListNode* start = head;
        ListNode* mid = head;
        ListNode* end = head;
        
        // Find middle point
        while(end->next != NULL && end->next->next != NULL) {
            mid = mid->next;
            end = end->next->next;
        }
        
        // Reverse 2nd half
        mid = reverseList(mid->next);
        
        // Link 2 halves according to the problem statement
        while(mid != NULL) {
            ListNode* tmp1 = start->next;
            ListNode* tmp2 = mid->next;
            
            start->next = mid;
            mid->next = tmp1;
            
            start = tmp1;
            mid = tmp2;
        }
        start->next = NULL;
    }
};