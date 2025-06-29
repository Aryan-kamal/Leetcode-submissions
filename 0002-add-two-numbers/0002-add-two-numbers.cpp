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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // here digits are stored in revered order so its no problem 
        // other we have to reverse the linked list first then code same 

        // also in this ques it is said that that there wont be leading 0's so no problem otherwsie we would have to deal with them also before returning
        // in this code we are returing reversed ll only 
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        int carry = 0;
        while (t1 || t2) {
            int sum = carry;
            if (t1)
                sum += t1->val;
            if (t2)
                sum += t2->val;
            ListNode* newNode = new ListNode(sum % 10);
            carry = sum / 10;
            curr->next = newNode;
            curr = curr->next;
            if (t1)
                t1 = t1->next;
            if (t2)
                t2 = t2->next;
        }
        if (carry) {
            ListNode* neww = new ListNode(carry);
            curr->next = neww;
        }
        return dummy->next;
    }
};

// Helper function to remove leading zeroes
// Node* removeLeadingZeroes(Node* head) {
//     while (head && head->data == 0 && head->next != NULL) {
//         Node* temp = head;
//         head = head->next;
//         delete temp;
//     }
//     return head;
// }