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
    ListNode* middle(ListNode* head) {
       ListNode* fast=head->next;
       ListNode* slow=head;
       while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
       }
       return slow;
    }
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* dum= new ListNode(-1);
        ListNode* temp=dum;
        while(l1!=NULL && l2!=NULL){
            if(l1->val<l2->val){
                temp->next=l1;
                temp=l1;
                l1=l1->next;
            }
            else{
                temp->next=l2;
                temp=l2;
                l2=l2->next;
            }
        }
        if(l1)temp->next=l1;
        else temp->next=l2;
        return dum->next;
    }
    ListNode* sortList(ListNode* head) {
       if(head==NULL || head->next==NULL)return head;
       ListNode* miid=middle(head);
       ListNode* right=miid->next;
       miid->next=nullptr;
       ListNode* left=head;
       left=sortList(left);
       right=sortList(right);
       return merge(left,right);
    }
};