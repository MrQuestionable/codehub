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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL && list2==NULL)return NULL;
        if(list1==NULL)return list2;
        if(list2==NULL)return list1;
        ListNode* t1=list1;
        ListNode* t2=list2;
        ListNode* dum=new ListNode(-1);
        ListNode* nh=dum;
        while(t1!=NULL && t2!=NULL){
            if(t1->val<t2->val){
                nh->next=t1;
                nh=t1;
                t1=t1->next;
            }
            else{
                nh->next=t2;
                nh=t2;
                t2=t2->next;
            }
        }
        if(t1!=nullptr){
            nh->next=t1;
        }else{
            nh->next=t2;
        }
        ListNode* neh=dum->next;
        delete dum;
        return neh;
    }
};