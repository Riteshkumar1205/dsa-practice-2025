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
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return false;  // No cycle possible
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;           // move by 1
            fast = fast->next->next;     // move by 2
            
            if (slow == fast)            // they meet ⇒ cycle exists
                return true;
        }
        
        return false;  // fast reached the end ⇒ no cycle
    }
};
