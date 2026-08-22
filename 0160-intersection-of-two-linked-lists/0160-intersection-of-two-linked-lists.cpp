#include<bits/stdc++.h> 
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            ListNode* t1=headA;
            ListNode* t2=headB;
            if(headA==NULL || headB==NULL)return NULL;
            unordered_set<ListNode*>mp;
            while(t1){
                mp.insert(t1);
                t1=t1->next;
            }
            while(t2){
                if(mp.find(t2)!=mp.end()){
                    return t2;
                }
                t2=t2->next;
            }
        return NULL;    
    }
};