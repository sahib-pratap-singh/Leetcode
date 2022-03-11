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
    //Reverse a linked list
    ListNode* reverseList(ListNode* root) {
        ListNode* prev = NULL;
        ListNode* curr = root;
        while (curr != NULL) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)
            return 0;
        ListNode* newhead = head;
        int length=0;
        while(newhead!=NULL){
            length++;
            newhead=newhead->next;
        }
        k = k%length;
        if(k==0)
            return head;
        head=reverseList(head);
        ListNode* kthnode=head;
        while(k>1 && kthnode){
            kthnode=kthnode->next;
            k--;
        }
        //ListNode* secondhalf=NULL;
        if(kthnode==NULL || kthnode->next==NULL)
            return head;
        
        ListNode* secondhalf=reverseList(kthnode->next);
        kthnode->next=NULL;
        
        ListNode* firsthalfend=reverseList(head);
        ListNode* result=firsthalfend;
        while(firsthalfend && firsthalfend->next){
            firsthalfend=firsthalfend->next;
        }
        firsthalfend->next=secondhalf;
        return result;
    }
};