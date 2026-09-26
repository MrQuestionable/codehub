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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        
        // Step 1: Find the middle using Fast/Slow pointers
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Step 2: Reverse the second half of the list
        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        // Step 3: Compare the first half and the reversed second half
        ListNode* firstHalf = head;
        ListNode* secondHalf = prev; // 'prev' is now the head of the reversed half
        
        while (secondHalf) {
            if (firstHalf->val != secondHalf->val) {
                return false; 
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        
        return true;
    }
};