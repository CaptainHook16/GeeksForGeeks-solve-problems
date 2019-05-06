int palindrom(ListNode* head, ListNode* &cure){
    if(head == NULL){
        return 1;
    }
    if(palindrom(head->next,cure) == 0){
        return 0;
    }
    if(head->val != cure->val){
        return 0;
    }
    else{
        cure = cure->next;
        return 1;
    }
}

 int Solution::lPalin(ListNode* A) {
     ListNode* cure = A;
     return palindrom(A,cure);
    
    
}
