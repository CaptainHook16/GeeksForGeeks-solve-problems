/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 
ListNode* Solution::reverseList(ListNode* A) {
    ListNode* prev,*cure,*next;
    prev = NULL;
    cure = A;
    
    
    while(cure != NULL)
    {
        next = cure->next;
        cure->next = prev;
        prev = cure;
        cure = next;
    }
    
    A=prev;
    return A;
    
    
    
}
