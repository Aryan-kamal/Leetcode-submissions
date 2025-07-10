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
    ListNode* partition(ListNode* head, int x) {
       if(!head || !head->next)
            return head;
        
        ListNode* less=new ListNode(-1);
        ListNode* high=new ListNode(-1);
        ListNode* lessHead = less;
        ListNode* highHead = high;
        
        ListNode* temp = head;
        while(temp){
            if(temp->val < x)
            {
                less->next=temp;
                less=temp;
            }
            else
            {
                high->next=temp;
                high=temp;
            }
            temp=temp->next;
        }
        high->next = nullptr;
        less->next=highHead->next;
        return lessHead->next; 
    }
};