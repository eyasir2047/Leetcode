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
 class mycompare{
public:
 bool operator()(const ListNode* a, const ListNode* b){
        return (a->val>b->val);
    }

 };
class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {//vector, made of linkedlist
        ListNode* head=new ListNode(-1);
        ListNode* temp= head;
        ListNode* first=head;

        priority_queue<ListNode*, vector<ListNode*>,mycompare>pq;

        for(int i=0;i<lists.size();i++){//lists.size()==3

                if(lists[i]!=NULL){
                    pq.push(lists[i]);
                }
        } //only the passsing the head

        while(!pq.empty()){
            auto least=pq.top();
            pq.pop();
            temp->next=least;
            temp=temp->next;
            if(least->next){//after the element is pop out, if there is a element in the list, then add it
            pq.push(least->next);

            }

        }

        return first->next;//return head


    }
};