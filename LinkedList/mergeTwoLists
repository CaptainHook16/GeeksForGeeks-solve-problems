/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 

ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode* res = NULL;
    if(A==NULL && B){
        return B;
    }
    if(B==NULL && A){
        return A;
    }
    
    if(A->val <= B->val){
        res = A;
        res->next = mergeTwoLists(A->next,B);
    }else{
        res=B;
        res->next = mergeTwoLists(A,B->next);
    }
    return res;
}
