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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *oddList = new ListNode(0);
        ListNode *evenList = new ListNode(0);

        ListNode *oddHead = oddList;
        ListNode *evenHead = evenList;  
        
        ListNode *q = head;
        
        int c = 1;
        
        while(q != NULL) {
            ListNode *temp = new ListNode(q->val);
            if(c % 2 == 0) {
                evenList->next = temp;
                evenList = temp;
            } else {
                oddList->next = temp;
                oddList = temp;
            }
            q = q->next;
            c++;
        }
        
        oddList->next = evenHead->next;
        
        return oddHead->next;
    }
};