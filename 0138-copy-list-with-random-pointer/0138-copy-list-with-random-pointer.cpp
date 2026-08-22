/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        
        // STEP 1: Weave the copied nodes directly after the original nodes.
        // List becomes: 1 -> 1(copy) -> 2 -> 2(copy) -> NULL
        Node* curr = head;
        while (curr != nullptr) {
            Node* copyNode = new Node(curr->val);
            copyNode->next = curr->next;
            curr->next = copyNode;
            curr = copyNode->next; // Move to the next ORIGINAL node
        }
        
        // STEP 2: Assign the random pointers for the copied nodes.
        curr = head;
        while (curr != nullptr) {
            // Check for NULL to avoid crashing!
            if (curr->random != nullptr) {
                // The copy's random points to the original random's copy (which is next)
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next; // Move to the next ORIGINAL node
        }
        
        // STEP 3: Unweave the lists. Restore the original and extract the copy.
        curr = head;
        Node* dummy = new Node(0);
        Node* copyTail = dummy;
        
        while (curr != nullptr) {
            Node* nextOriginal = curr->next->next;
            
            // Link the copy node to our new copied list
            copyTail->next = curr->next;
            copyTail = copyTail->next;
            
            // Restore the original node's next pointer
            curr->next = nextOriginal;
            
            // Move forward
            curr = nextOriginal;
        }
        
        Node* result = dummy->next;
        delete dummy;
        return result;
    }
};