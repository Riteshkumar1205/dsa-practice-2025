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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }

        int firstIndex = -1;
        int prevIndex = -1;
        int currentIndex = 1;

        int minDistance = INT_MAX;

        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr->next != nullptr) {
            if ((curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val)) {
                
                if (firstIndex == -1) {
                    firstIndex = currentIndex;
                } else {
                    minDistance = min(minDistance, currentIndex - prevIndex);
                }
                prevIndex = currentIndex;
            }

            prev = curr;
            curr = curr->next;
            currentIndex++;
        }

        if (firstIndex == -1 || firstIndex == prevIndex) {
            return {-1, -1};
        }

        int maxDistance = prevIndex - firstIndex;
        return {minDistance, maxDistance};
    }
};