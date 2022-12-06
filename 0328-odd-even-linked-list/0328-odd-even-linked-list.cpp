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
    ListNode* mySolution1(ListNode* head) {
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
    
    // https://leetcode.com/problems/odd-even-linked-list/discuss/1606963/C%2B%2B-Simplest-Solution-(W-Explanation)-or-One-Pass
    ListNode* solution2(ListNode* head) {

        if(!head || !head->next || !head->next->next) return head;
        
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *even_start = head->next;
        
        while(odd->next && even->next){
            odd->next = even->next; //Connect all odds
            even->next = odd->next->next;  //Connect all evens
            odd = odd->next;
            even = even->next;
        }
        odd->next = even_start;   //Place the first even node after the last odd node.
        return head; 
    }
public:
    ListNode* oddEvenList(ListNode* head) {
        // return mySolution1(head);
        
        return solution2(head);
    }
};