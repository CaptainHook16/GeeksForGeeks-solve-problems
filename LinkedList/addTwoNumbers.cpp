ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    int carry = 0;
    ListNode* p1 = A;
    ListNode* p2 = B;
    int sum = 0;
    ListNode* res=NULL;
    ListNode* cure = res;
    while(p1!=NULL && p2!=NULL)
    {
        sum = 0;
        sum = p1->val + p2->val + carry;
        carry = sum/10;
        ListNode* n = new ListNode(sum%10);
        n->val = sum%10;
        if(cure!=NULL){
            cure->next = n;
            cure = cure->next;
        }else{
            res = n;
            cure = res;
        }
        p2=p2->next;
        p1=p1->next;
    }
    
    if(p1 == NULL && p2 == NULL){
        cure->next = NULL;
       return res; 
    }
    if(p1==NULL && p2!=NULL)
    {
        while(p2!=NULL && carry!=0){
          sum = 0;
          sum =  p2->val + carry; 
          carry = sum/10;
          ListNode* n = new ListNode(sum%10);
          n->val = sum%10;
          cure->next = n;
          cure = cure->next;
          p2=p2->next;
        }
        if(p2==NULL && carry==0){
            cure->next = NULL;
            return res;
        }
        if(carry!=0 && p2==NULL){
            ListNode* n = new ListNode(carry);
            cure->next = n;
            cure->next->next = NULL;
            return res;
        }
        if(carry==0 && p2!=NULL)
        {
            while(p2!=NULL)
            {
            ListNode* n = new ListNode(p2->val);
            n->val = p2->val;
            cure->next = n;
            cure = cure->next;
            p2=p2->next;
            }
        }
    }
    
    if(p2==NULL && p1!=NULL)
    {
        while(p1!=NULL && carry!=0){
          sum = 0;
          sum =  p1->val + carry; 
          carry = sum/10;
          ListNode* n = new ListNode(sum%10);
          n->val = sum%10;
          cure->next = n;
          cure = cure->next;
          p1=p1->next;
        }
        if(p1==NULL && carry==0){
            cure->next = NULL;
            return res;
        }
        if(carry!=0 && p1==NULL){
            ListNode* n = new ListNode(carry);
            cure->next = n;
            cure->next->next = NULL;
            return res;
        }
        if(carry==0 && p1!=NULL){
            while(p1!=NULL)
            {
            ListNode* n = new ListNode(p1->val);
            n->val = p1->val;
            cure->next = n;
            cure = cure->next;
            p1=p1->next;
            }
        }
    }
    cure->next = NULL; 
    return res;
}
