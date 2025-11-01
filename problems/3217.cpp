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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        sort(nums.begin(),nums.end());
        ListNode* pre = new ListNode();
        ListNode* start = pre;
        ListNode* now = head;
        while( now != NULL ){
            int v = now->val;
            auto p = lower_bound(nums.begin(),nums.end(),v);
            if( p != nums.end() and v == *p ){
                pre->next = NULL;
                now = now->next;
                continue;
            }
            pre->next = now;
            pre = pre->next;
            now = now->next;
        }
        return start->next;
    }
};
