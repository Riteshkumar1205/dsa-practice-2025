/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // Edge Case: If the list has only 1 node, returning nullptr 
        // leaves an empty list. LeetCode handles the deletion behind the scenes.
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr; // Tracks the node right before 'slow'
        
        // Move 'fast' by 2 steps and 'slow' by 1 step
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // 'slow' now points to the middle node.
        // Bypass the middle node by linking 'prev' directly to 'slow->next'.
        prev->next = slow->next;
        
        // Free the memory of the deleted middle node
        delete slow;
        
        return head;
    }
};