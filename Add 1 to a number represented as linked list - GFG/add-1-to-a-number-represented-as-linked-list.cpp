// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    int carry=1;
    Node* solve(Node* root){
        if(root==NULL){
            return root;
        }
        solve(root->next);
        int val=root->data+carry;
        if(val>9){
            carry=1;
        }
        else{
            carry=0;
        }
        //cout<<val<<" ";
        root->data=val%10;
        //return root;
    }
    Node* addOne(Node *head) 
    {
        if(head==NULL){
            return head;
        }
        Node* root=solve(head);
        if(carry){
            Node* node=new Node(1);
            node->next=root;
            return node;
        }
        return root;
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends