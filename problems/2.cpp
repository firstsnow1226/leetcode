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
        ListNode* head = new ListNode(0); // extra node
        ListNode* current = head;
        int carry = 0;
        // (l1!=nullptr) 等價於 (l1)
        while( (l1!=nullptr) || l2 || carry){
            int d1 = (l1)? l1->val : 0;
            int d2 = (l2)? l2->val : 0;
            int sum = d1+d2+carry;
            carry = sum/10;
            current->next = new ListNode(sum%10);
            current = current->next;

            l1 = (l1)? l1->next : nullptr;
            l2 = (l2)? l2->next : nullptr;
        }
        return head->next;

    }
};
