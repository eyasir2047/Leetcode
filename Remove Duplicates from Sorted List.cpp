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
    ListNode* deleteDuplicates(ListNode* head) {
    ListNode* dummy=new ListNode(-1);
       ListNode* temp=head;
       ListNode* prev=dummy;
       prev->next=head;

       while(temp!=NULL){
            if(temp->next!=NULL && temp->next->val==temp->val ){
                while(temp->next!=NULL && temp->next->val==temp->val){
                    temp=temp->next;
                }
                prev->next=temp;
                prev=prev->next;
            }
            else{
                prev=prev->next;
                

            }
            temp=temp->next;

       }
       return dummy->next;//head
    }
};