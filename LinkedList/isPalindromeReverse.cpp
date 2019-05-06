/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;



  class ListNode {
      public:
      
      int val;
      ListNode *next=NULL;
      
  };

 #include <stack>
 
 void push(ListNode** head_ref, int new_data) 
{ 
    /* allocate node */
    ListNode* new_node = new ListNode();
         
  
    /* put in the data  */
    new_node->val  = new_data; 
  
    /* link the old list off the new node */
    new_node->next = (*head_ref); 
  
    /* move the head to pochar to the new node */
    (*head_ref)    = new_node; 
} 


 void printList(ListNode *ptr) 
{ 
    while (ptr != NULL) 
    { 
        cout<< ptr->val<< " ";
        ptr = ptr->next; 
    } 
    cout<<endl;
} 
 int comp(ListNode* a, ListNode* b){
         ListNode* p1,*p2;
         p1 = a;
         p2 = b;
         while(p1!=NULL && p2!=NULL){
             if(p1->val != p2->val){
                 return 0;
             }
             p1=p1->next;
             p2 = p2->next;
         }
         return 1;
     }
     
 ListNode* reverse(ListNode* A){
     ListNode *cure=A,*next,*prev=NULL;
     while(cure!=NULL){
         next = cure->next;
         cure->next = prev;
         prev = cure;
         cure = next;
     }
     A=prev;
     return A;
     
     
 }
 
 int lPalin(ListNode* A) {
     if(A && A-> next == NULL){
         return 1;
     }
     int res = 1;
    ListNode *p1=A,*p2=A,*mid = NULL,*secondHalf=NULL;
    //we need to save the previous node before p1 so we can link the devided list
    ListNode* prevp1 = NULL;
    while(p2!=NULL && p2->next!=NULL){
        prevp1 = p1;
        p1=p1->next;
        p2=p2->next->next;
    }
    //if p2 in null it means that list's len is even, else is odd(there isn't V.S. there is mid node)
    if(p2 != NULL){
        mid = p1;
        p1 = p1->next;
    }
    secondHalf = p1;
    prevp1->next = NULL;
    printList(secondHalf);
    secondHalf = reverse(secondHalf);
    printList(secondHalf);
    res = comp(A,secondHalf);
    
    secondHalf = reverse(secondHalf);
    
    if(mid != NULL){
        prevp1->next = mid;
        mid->next = secondHalf;
    }else{
        prevp1->next = secondHalf;
    }
    
    return res;
    
    
}


int main()
{
    ListNode* head = NULL;
    push(&head, 6);
    push(&head, 3);
    push(&head, 7);
    push(&head, 3);
    //push(&head, 6);
    printList(head);
    cout<<endl;
    //cout<<lPalin(head);
    head = reverse(head);
    printList(head);

    return 0;
}
