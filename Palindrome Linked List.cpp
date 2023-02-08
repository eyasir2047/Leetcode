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

    ListNode* findMid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL && fast->next!=NULL){
            slow= slow->next;
            fast= fast->next;

            if(fast){//if this is exit, then
                fast=fast->next;//floyd algorithm
            }
        }
        return slow;
    }


    ListNode* reverselist(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr= head;
        ListNode* temp=NULL;

        while(curr!=NULL){
            temp=curr->next;
            curr->next=prev;

            prev=curr;
            curr=temp;
        }
        return prev;
    }

    bool comparelist(ListNode* head1, ListNode* head2){
        while(head1!=NULL && head2!=NULL){
            if(head1->val != head2->val) return false;
            head1=head1->next;
            head2= head2->next;
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {
        //middle of a linkedlist
        //reverse of a linkedlist
        if(head==NULL || head->next==NULL) return true;
        ListNode* mid=findMid(head);
        ListNode* rev=reverselist(mid);

        return comparelist(head,rev);

    }
};