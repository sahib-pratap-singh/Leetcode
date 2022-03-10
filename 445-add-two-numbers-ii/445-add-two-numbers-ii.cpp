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
    ListNode* addTwoNumber(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* dummy=new ListNode(0);
        ListNode* newnode=dummy;
        while(l1!=NULL || l2!=NULL){
            int a=l1==NULL?0:l1->val;
            int b=l2==NULL?0:l2->val;
            int sum=a+b+carry;
            carry= (sum)/10;
            ListNode* nextnode=new ListNode((sum)%10);
            newnode->next=nextnode;
            newnode=newnode->next;
            if(l1){
                l1=l1->next;
            }
            if(l2){
                l2=l2->next;
            }
        }
        if(carry>0){
            newnode->next=new ListNode(carry);
        }
        return dummy->next;
    }
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* cur=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return cur;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverseList(l1);
        l2=reverseList(l2);
        ListNode* result= addTwoNumber(l1,l2);
        return reverseList(result);
    }
};