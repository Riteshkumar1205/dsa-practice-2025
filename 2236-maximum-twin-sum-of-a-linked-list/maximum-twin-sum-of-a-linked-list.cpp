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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Step 1: Find the middle of the linked list using slow and fast pointers
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Step 2: Reverse the second half of the linked list
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        // Step 3: Iterate through both halves and find the maximum twin sum
        int max_sum = 0;
        ListNode* first_half = head;
        ListNode* second_half = prev; // 'prev' is now the head of the reversed second half
        
        while (second_half) {
            max_sum = max(max_sum, first_half->val + second_half->val);
            first_half = first_half->next;
            second_half = second_half->next;
        }
        
        return max_sum;
    }
};