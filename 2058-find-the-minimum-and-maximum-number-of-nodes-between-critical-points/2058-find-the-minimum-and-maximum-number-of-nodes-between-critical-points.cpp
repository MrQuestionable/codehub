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
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return {-1, -1};
        }
        int minDistance = INT_MAX;
        int firstCrit = -1;
        int prevCrit = -1;
        ListNode* prev = head;
        ListNode* curr = head->next;
        int index = 1; 
        while (curr->next != nullptr) {
            ListNode* nextNode = curr->next;
            if ((curr->val > prev->val && curr->val > nextNode->val) || 
                (curr->val < prev->val && curr->val < nextNode->val)) {
                
                if (firstCrit == -1) {
                    firstCrit = index;
                } else {
                    minDistance = min(minDistance, index - prevCrit);
                }
                prevCrit = index; 
            }
            prev = curr;
            curr = nextNode;
            index++;
        }
        if (minDistance == INT_MAX) {
            return {-1, -1};
        }
        int maxDistance = prevCrit - firstCrit;
        
        return {minDistance, maxDistance};
    }
};