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
        if(list1==NULL)return list2 ; 
        if(list2==NULL)return list1 ; 

        ListNode* head1 = list1 , *head2 = list2  ;
        ListNode* m = new ListNode(-1) ;
        ListNode *mergedList = m;  
         while(head1 && head2){
             
             if(head1->val<=head2->val){
                m->next = head1 ; 
                m=head1 ; 
                head1=head1->next ; 
             }
             else{
                m->next = head2 ; 
                m=head2 ;
                head2=head2->next ; 
             }
         }
         while(head1){
              m->next = head1 ; 
              m=head1;
              head1 = head1->next ; 
         }
         while(head2){
              m->next = head2 ; 
              m=head2;
              head2 = head2->next ; 
         }

         return mergedList->next ;
    }
};
