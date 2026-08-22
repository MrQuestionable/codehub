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
    ListNode* reverse(ListNode* temp){
       ListNode* dum=temp;
       ListNode* pre=nullptr;
       while(dum){
        ListNode* n=dum->next;
        dum->next=pre;
        pre=dum;
        dum=n;
       }
       return dum; 
    }
    ListNode* findkthnode(ListNode* temp,int k){
        k-=1;
        while(temp!=NULL&& k>0){
            k--;
            temp=temp->next;
        }
        return temp;
    } 
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)return head;
        ListNode* temp=head;
        ListNode* prev=nullptr;
        while(temp){
            ListNode* kth=findkthnode(temp,k);
            if(kth==NULL){
                if(prev)prev->next=temp;
                break;
            }
            ListNode* nextn=kth->next;
        kth->next=nullptr;
        reverse(temp);
        if(temp==head)head=kth;
        else{
            prev->next=kth;
        }
        prev=temp;
        temp=nextn;
        }
        return head;   
    }
};